import os
import itertools
import pdb

TEST_DIR = "../../ALL_tests_flat/"
heuristics = ["chunked", "plain", "round_robin"]

tests = os.listdir(TEST_DIR)
test_names = [x[0]+"_"+x[1] for x in itertools.product(heuristics,tests)]

test_names = sorted(test_names)

if __name__ == "__main__":    
    print("NSArray * get_kernels() {")
    print ("NSArray *kernels = [NSArray arrayWithObjects:")
    for n in test_names:
        print("  @\"" + n + "\",")
    print("  nil];")
    print("return kernels;")
    print("}")

