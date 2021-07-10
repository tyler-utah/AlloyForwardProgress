# -----------------------------------------------------------------------
# amber_launch_tests.py
# Authors: Hari Raval
# -----------------------------------------------------------------------
import sys
import os


# run the amber_test_driver.py script with all input directories available in Input_Files
def main():
    if len(sys.argv) != 1:
        print("ERROR: No command line arguments required to run this higher level script")
        exit(1)

    directory_names = ["../ALL_tests_tmp/2_thread_2_instruction",
                       "../ALL_tests_tmp/2_thread_3_instruction",
                       "../ALL_tests_tmp/2_thread_4_instruction",
                       "../ALL_tests_tmp/3_thread_3_instruction",
                       "../ALL_tests_tmp/3_thread_4_instruction"]

    for name in directory_names:
        os.system("python3 amber_test_driver.py " + name + " 5")


if __name__ == "__main__":
    main()
