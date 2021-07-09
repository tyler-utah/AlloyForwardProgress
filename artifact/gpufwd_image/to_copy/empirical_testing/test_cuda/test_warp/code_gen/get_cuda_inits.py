import os
import itertools
import pdb

TEST_DIR = "../../../ALL_tests_flat/"
heuristics = ["plain"]

tests = os.listdir(TEST_DIR)
test_names = [x[0]+"_"+x[1] for x in itertools.product(heuristics,tests)]

test_names = sorted(test_names)

if __name__ == "__main__":    
    print("void init_kernels() {")
    for n in test_names:
        print("  kernel_names.push_back(\"" + n + "\");")
        print("  kernels.push_back(&" + n + "_ptr);")    
    print("}")

