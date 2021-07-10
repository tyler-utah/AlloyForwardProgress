# -----------------------------------------------------------------------
# amber_test_generation.py
# Author: Hari Raval
# -----------------------------------------------------------------------
import sys
import re
from configuration import Configuration

# default Configuration object to be used in the Amber test generation
default_config = Configuration(timeout=20000, workgroups=65532, threads_per_workgroup=1, saturation_level=0, subgroup=0)


# write the necessary "boiler plate" code to generate an Amber test, along with Shader
# Storage Buffer Object(s), workgroup size, and global variable to
# assign thread IDs. output is the file being written to, timeout determines (in ms) when the
# program will terminate, num_testing_threads is the number of threads being tested, and saturation_level is the
# type of saturation (if any)
def write_amber_prologue(output, timeout, threads_per_workgroup, workgroups, num_testing_threads, saturation_level,
                         subgroup_setting):
    output.write("#!amber\n")
    output.write("\n")
    output.write("SET ENGINE_DATA fence_timeout_ms " + str(timeout) + "\n")
    output.write("\n")
    output.write("SHADER compute test GLSL\n")

    # determine whether the same or different subgroups will be used for testing to update versions and extensions
    if subgroup_setting == 0:
        output.write("#version 430\n")
    else:
        output.write("#version 450 core\n")
        output.write("#extension GL_KHR_shader_subgroup_basic : enable\n")
        output.write("#extension GL_KHR_shader_subgroup_ballot : enable\n")

    output.write("\n")
    output.write("layout(set = 0, binding = 0) volatile buffer TEST {\n")

    # if no saturation, then only one location in the SSBO is needed
    if saturation_level == 0:
        output.write("\tuint x;\n")
        output.write("\tuint y;\n")

    output.write("\tuint counter;\n")
    output.write("} test; \n")
    output.write("\n")

    # if GPU will be saturated, then ensure there is an SSBO with many locations to be accessed and updated
    if saturation_level == 1 or saturation_level == 2:
        output.write("layout(set = 0, binding = 1) volatile buffer OUT_BUF_1 {\n")
        output.write("\tuint x[];\n")
        output.write("} out_buf1; \n")
        output.write("layout(set = 0, binding = 2) volatile buffer OUT_BUF_2 {\n")
        output.write("\tuint y[];\n")
        output.write("} out_buf2; \n")
        output.write("\n")

    output.write("layout(local_size_x = " + str(threads_per_workgroup) + ", local_size_y = 1, local_size_z = 1) in;\n")
    output.write("\n")
    output.write("void main()\n")
    output.write("{\n")

    # if the same subgroups are used, gid_x will be used in the script
    if subgroup_setting == 0:
        output.write("\tuint gid_x = gl_GlobalInvocationID.x;\n")

    output.write("\tint pc = 0;\n")

    # perform the necessary index computation to update SSBO for "round robin" saturation
    if saturation_level == 1:
        total_threads = workgroups * threads_per_workgroup
        output.write("\n")
        output.write("\tint total_num_threads = " + str(total_threads) + ";\n")
        output.write("\tint num_testing_threads = " + str(num_testing_threads) + ";\n")
        output.write("\tuint index = gid_x / num_testing_threads;\n")

    # perform the necessary computations of "chunk" size and index to update SSBO for "chunking" saturation
    elif saturation_level == 2:
        total_threads = workgroups * threads_per_workgroup
        output.write("\n")
        output.write("\tint total_num_threads = " + str(total_threads) + ";\n")
        output.write("\tint num_testing_threads = " + str(num_testing_threads) + ";\n")
        output.write("\tint chunk_size =  total_num_threads / num_testing_threads;\n")
        output.write("\tuint index = gid_x % chunk_size;\n")

    output.write("\n")


# write the appropriate content to set up each thread by using the thread_instructions, the thread_number,
# the total number of threads (number_of_testing_threads), the number_of_testing_threads, and saturation_level
def write_amber_thread_program(output, thread_instructions, thread_number, number_of_testing_threads, saturation_level,
                               subgroup_set):

    # compose the "if" statements for each thread depending on the type of saturation requested for the Amber test
    if saturation_level == 0:
        # write conditionals based on subgroup setting
        if subgroup_set == 0:
            output.write("\tif (gid_x == " + str(thread_number) + ") { \n")
        else:
            output.write("\tif (gl_SubgroupID == " + str(thread_number) + " && gl_SubgroupInvocationID == 0 &&"
                                                                          " gl_WorkGroupID.x == 0" + ") { \n")
    elif saturation_level == 1:
        output.write("\tif (gid_x % num_testing_threads == " + str(thread_number) + ") { \n")
    elif saturation_level == 2:
        output.write("\tif (gid_x / chunk_size == " + str(thread_number) + ") { \n")
    else:
        print("Saturation level can only be 0, 1, or 2", file=sys.stderr)
        exit(1)

    output.write("\t   int terminate = 0;\n")
    output.write("\n")
    output.write("\twhile (true) {\n")
    output.write("\t   if (terminate == 1) {\n")
    output.write("\t   break;\n")
    output.write("\t}\n")
    output.write("\tswitch(pc) {\n")
    output.write("\n")

    program_end = len(thread_instructions)

    # iterate over each instruction assigned to the specific thread and generate the test case
    for instruc_id, instruction in enumerate(thread_instructions):
        write_amber_thread_instruction(output, instruction, instruc_id, number_of_testing_threads, saturation_level,
                                       program_end)

    output.write("\t  case " + str(program_end) + ":\n")
    output.write("\t\tterminate = 1;\n")
    output.write("\t\tbreak;\n")
    output.write("\n")
    output.write("\t     }\n")
    output.write("\t   }\n")
    output.write("\t}\n")
    output.write("\n")


# write the appropriate test cases for each instruction based off of the instruction id, number of instructions, and
# type of saturation
def write_amber_thread_instruction(output, instruction, instruc_id, num_of_testing_threads, saturation_level,
                                   program_end):
    pattern = "\\((.+?)\\)"
    search_pattern = re.search(pattern, instruction)
    numerical_representation = " "
    if search_pattern:
        numerical_representation = search_pattern.group(1)

    # create a list of the arguments that are provided from the pseudo instruction
    numerical_representation = numerical_representation.split(",")

    # extract the memory location that will be written to
    memory_location = numerical_representation[0]

    output.write("\t  case " + str(instruc_id) + ": \n")

    # extract the appropriate values for an atomic exchange branch from the numerical_representation of the instruction
    # and call handle_atomic_exchange_branch
    if instruction.startswith("atomic_exch_branch"):
        check_value = numerical_representation[1]
        exchange_value = numerical_representation[2]
        instruction_address = numerical_representation[3]
        handle_atomic_exchange_branch(output, check_value, exchange_value, instruction_address,
                                      saturation_level, memory_location, program_end)

    # extract the appropriate values for an atomic exchange branch from the numerical_representation of the instruction
    # and call handle_amber_check_branch
    elif instruction.startswith("atomic_chk_branch"):
        check_value = numerical_representation[1]
        instruction_address = numerical_representation[2]
        handle_amber_check_branch(output, check_value, instruction_address, saturation_level,
                                  memory_location, program_end)

    # extract the appropriate values for an atomic exchange branch from the numerical_representation of the instruction
    # and call handle_atomic_store
    elif instruction.startswith("atomic_store"):
        write_value = numerical_representation[1]
        handle_atomic_store(output, write_value, saturation_level, memory_location)


# write the amber test code for an atomic exchange branch instruction
def handle_atomic_exchange_branch(output, check_value, exchange_value, instruction_address, saturation_level,
                                  memory_location, program_end):
    # perform the operation either at a single memory location or indexed memory location, depending on saturation level
    if saturation_level == 0:
        # determine whether to write to memory location x or memory location y
        if int(memory_location) == 0:
            output.write("\t\tif (atomicExchange(test.x, " + exchange_value + ") == " + check_value + ") { \n")
        else:
            output.write("\t\tif (atomicExchange(test.y, " + exchange_value + ") == " + check_value + ") { \n")

    elif saturation_level == 1 or saturation_level == 2:
        # determine whether to write to memory location x[] or memory location y[]
        if int(memory_location) == 0:
            output.write("\t\tif (atomicExchange(out_buf1.x[index], " + exchange_value + ") ==  " + check_value +
                         ") { \n")
        else:
            output.write("\t\tif (atomicExchange(out_buf2.y[index], " + exchange_value + ") ==  " + check_value +
                         ") { \n")

    if instruction_address == "END":
        output.write("\t\t   pc = " + str(program_end) + ";\n")
    elif instruction_address != "END":
        output.write("\t\t   pc = " + instruction_address + ";\n")
    else:
        print("Incorrect instruction_address in handle_amber_check_branch", file=sys.stderr)
        exit(1)

    output.write("\t\t}\n")
    output.write("\t\telse {\n")
    output.write("\t\t   pc = pc + 1;\n")
    output.write("\t\t}\n")
    output.write("\t\tbreak;\n")
    output.write("\n")


# write the amber test code for an atomic check branch instruction
def handle_amber_check_branch(output, check_value, instruction_address, saturation_level, memory_location, program_end):

    # perform the operation either at a single memory location or indexed memory location, depending on saturation level
    if saturation_level == 0:
        # determine whether to write to memory location x or memory location y
        if int(memory_location) == 0:
            output.write("\t\tif (atomicAdd(test.x, 0) == " + check_value + " ) { \n")
        else:
            output.write("\t\tif (atomicAdd(test.y, 0) == " + check_value + " ) { \n")

    elif saturation_level == 1 or saturation_level == 2:
        # determine whether to write to memory location x[] or memory location y[]
        if int(memory_location) == 0:
            output.write("\t\tif (atomicAdd(out_buf1.x[index], 0) == " + check_value + " ) { \n")
        else:
            output.write("\t\tif (atomicAdd(out_buf2.y[index], 0) == " + check_value + " ) { \n")

    if instruction_address == "END":
        output.write("\t\t   pc = " + str(program_end) + ";\n")
    elif instruction_address != "END":
        output.write("\t\t   pc = " + instruction_address + ";\n")
    else:
        print("Incorrect instruction_address in handle_amber_check_branch", file=sys.stderr)
        exit(1)

    output.write("\t\t}\n")
    output.write("\t\telse {\n")
    output.write("\t\t   pc = pc + 1;\n")
    output.write("\t\t}\n")
    output.write("\t\tbreak;\n")
    output.write("\n")


# write the amber test code for an atomic store instruction
def handle_atomic_store(output, write_value, saturation_level, memory_location):
    # perform the operation either at a single memory location or indexed memory location, depending on saturation level
    if saturation_level == 0:
        # determine whether to write to memory location x or memory location y
        if int(memory_location) == 0:
            output.write("\t\tatomicExchange(test.x, " + write_value + ");\n")
        else:
            output.write("\t\tatomicExchange(test.y, " + write_value + ");\n")

    elif saturation_level == 1 or saturation_level == 2:
        # determine whether to write to memory location x[] or memory location y[]
        if int(memory_location) == 0:
            output.write("\t\tatomicExchange(out_buf1.x[index], " + write_value + ");\n")
        else:
            output.write("\t\tatomicExchange(out_buf2.y[index], " + write_value + ");\n")

    output.write("\t\tpc = pc + 1;\n")
    output.write("\t\tbreak;\n")
    output.write("\n")


# write the necessary "boiler plate" code to end the amber test, along with generating a desired number of threads
def write_amber_epilogue(output, workgroups, threads_per_workgroup, saturation_level):
    total_threads = workgroups * threads_per_workgroup

    output.write("\tatomicAdd(test.counter, 1);\n")
    output.write("}\n")
    output.write("END\n")
    output.write("\n")

    # fill the tester SSBO with 1 or 2 zeroes depending on the saturation level
    if saturation_level == 0:
        output.write("BUFFER tester DATA_TYPE uint32 SIZE 3 FILL 0\n")
    elif saturation_level == 1 or saturation_level == 2:
        output.write("BUFFER tester DATA_TYPE uint32 SIZE 1 FILL 0\n")

    # if the GPU is to be saturated, then the second buffer must be filled with all 0s
    if saturation_level == 1 or saturation_level == 2:
        output.write("BUFFER out1 DATA_TYPE uint32 SIZE 65535 FILL 0\n")
        output.write("BUFFER out2 DATA_TYPE uint32 SIZE 65535 FILL 0\n")

    output.write("\n")
    output.write("PIPELINE compute test_pipe\n")
    output.write("  ATTACH test\n")
    output.write("  BIND BUFFER tester AS storage DESCRIPTOR_SET 0 BINDING 0 \n")

    # if the GPU is to be saturated, then the second buffer must be binded to the SSBO
    if saturation_level == 1 or saturation_level == 2:
        output.write("  BIND BUFFER out1 AS storage DESCRIPTOR_SET 0 BINDING 1 \n")
        output.write("  BIND BUFFER out2 AS storage DESCRIPTOR_SET 0 BINDING 2 \n")

    output.write("\n")
    output.write("END\n")
    output.write("\n")
    output.write("RUN test_pipe " + str(workgroups) + " 1 1\n")

    if saturation_level == 0:
        output.write("EXPECT tester IDX 8 EQ " + str(total_threads) + "\n")
    elif saturation_level == 1 or saturation_level == 2:
        output.write("EXPECT tester IDX 0 EQ " + str(total_threads) + "\n")


# generate an Amber test with a provided input file, a desired output file name, and a Configuration object to set up
# the number of workgroups, threads per workgroup, and timeout
def generate_amber_test(inputted_file, output_file_name, config=default_config):
    input_file = inputted_file
    timeout = config.get_timeout()
    saturation_level = int(config.get_saturation_level())
    subgroup_set = int(config.get_subgroup_setting())

    if output_file_name.endswith(".amber"):
        print("Script will include the .amber extension, please provide a different output file name", file=sys.stderr)
        exit(1)

    if saturation_level < 0 or saturation_level > 2:
        print("Saturation level can only be 0 (no saturation), 1 (round robin saturation), "
              "or 2 (chunking saturation)", file=sys.stderr)
        exit(1)

        if subgroup_set < 0 or subgroup_set > 1:
            print("Saturation level can only be 0 (no saturation), 1 (round robin saturation), "
                  "or 2 (chunking saturation)", file=sys.stderr)
            exit(1)

    with open(input_file, 'r') as file:
        data = file.read().replace('\n', ' ')

    data_list = data.split(" ")

    while "" in data_list:
        data_list.remove("")

    instructions = []

    # iterate over each of the items from input and make a list of lists, where each list contains instructions for an
    # individual thread
    for index, item in enumerate(data_list):
        if item.startswith("THREAD"):
            temp_list = []
            temp_index = index + 1
            while temp_index < len(data_list) and not data_list[temp_index].startswith("THREAD"):
                temp_list.append(data_list[temp_index])
                temp_index = temp_index + 1
            instructions.append(temp_list)

    # number of threads that are provided in the input txt file
    num_of_testing_threads = len(instructions)
    threads_per_workgroup = int(config.get_threads_per_workgroup())
    workgroups = int(config.get_number_of_workgroups())

    total_number_threads = threads_per_workgroup * workgroups

    if (saturation_level == 1 or saturation_level == 2) and (total_number_threads % num_of_testing_threads != 0):
        print("For saturation, total number of threads must be evenly divisble by number of testing threads",
              file=sys.stderr)
        exit(1)

    # name and open the output file to contain the amber test case
    output_amber_file = output_file_name
    output_amber_file = output_amber_file + ".amber"
    output = open(output_amber_file, "a")

    # call the appropriate functions to generate the amber test
    write_amber_prologue(output, timeout, threads_per_workgroup, workgroups, num_of_testing_threads, saturation_level,
                         subgroup_set)

    for number, each_thread in enumerate(instructions):
        write_amber_thread_program(output, each_thread, number, num_of_testing_threads, saturation_level, subgroup_set)

    write_amber_epilogue(output, workgroups, threads_per_workgroup, saturation_level)


def main():
    if len(sys.argv) != 3:
        print("Please provide a .txt file to parse and the desired name for the outputted Amber file", file=sys.stderr)
        exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    # generate an amber test for the desired inputs, with a default configuration if none was provided
    generate_amber_test(input_file, output_file, default_config)


if __name__ == "__main__":
    main()
