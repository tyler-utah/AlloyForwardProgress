import os
import sys
sys.path.insert(0,"../../../src")
import cuda_test_generation
from configuration import Configuration
import get_cuda_inits
import pdb

sizes_alias = {"2_thread_2_instruction" : "2t_2i",
               "2_thread_3_instruction" : "2t_3i",
               "2_thread_4_instruction" : "2t_4i",
               "3_thread_3_instruction" : "3t_3i",
               "3_thread_4_instruction" : "3t_4i" ,
}

input_prefix = get_cuda_inits.TEST_DIR

DIR_NAME = "TMP_tests"
PLAIN_TESTS = DIR_NAME + "/plain"

def rm_dir(n):
    res = os.system("rm -rf " + n)
    assert(res == 0)    

def rm_and_mkdir(n):
    res = os.system("rm -rf " + n + "; mkdir " + n)
    assert(res == 0)

def get_data(f):
    f_handle = open(f,'r')
    data = f_handle.read()
    f_handle.close()
    return data

def mk_plain_test(finput, prefix, t):
    name = sizes_alias[prefix] + "_" + str(t)
    dir_name = PLAIN_TESTS + "/" + name
    rm_and_mkdir(dir_name)
    os.system("cp " + finput + " " + dir_name + "/")

    cuda_test_generation.generate_cuda_test(finput, dir_name+"/"+name)
    return get_data(dir_name+"/"+name + ".cu")

def generate_tests(prefix, tests):
    plain_names = []
    plain_kernels = []
    chunked_names = []
    chunked_kernels = []
    rr_names = []
    rr_kernels = []
    for t in tests:
        test_name = sizes_alias[prefix] + "_" + str(t)
        plain_names.append("plain_" + test_name)

        f = input_prefix + "/" + test_name + "/" + str(t) + ".txt"
        plain_kernels.append(mk_plain_test(f,prefix,t))

    return plain_names,plain_kernels

rm_and_mkdir(DIR_NAME)
rm_and_mkdir(PLAIN_TESTS)
header = """
"""
kernels = [header]
for i in sizes_alias:
    tests = [x for x in get_cuda_inits.tests if sizes_alias[i] in x]
    test_ids = [x for x in range(len(tests))]

    plain_names, plain_kernels = generate_tests(i,test_ids)
    uplain_kernels = []
    for i in range(len(plain_names)):
        k = plain_kernels[i]
        k = k.replace("testKernel", plain_names[i])
        uplain_kernels.append(k)



    kernels = kernels + uplain_kernels

rm_dir(DIR_NAME)
print("\n".join(kernels))
