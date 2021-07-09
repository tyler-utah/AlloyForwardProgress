import os
import time
from test_list import TEST_NAMES

NUM_TESTS=len(TEST_NAMES)
ITERS = 20
TIMEOUT = 20

def my_exec(d):
    cmd = " ".join(["timeout", str(TIMEOUT)] + d)
    print("executing:")
    print(cmd)
    
    ret = os.system(cmd)

    # because on linux systems os.system returns a 16
    # bit number: the first 8 are the exit code. For
    # timeout, the timeout error code is 124
    ret = ret >> 8 
    if ret not in [0,124]:
        print(ret)
        print("error!")
        exit(0)
    if ret == 124:
        print("timed out")
        return "F"
    else:
        print("finished")
        return "P"

def get_t_name(t):
    return TEST_NAMES[t]

begin = time.time()
test_log = ""
for t in range(NUM_TESTS):
    t_name = get_t_name(t);
    passed = 0
    failed = 0
    for i in range(ITERS):
        print(t,i,t_name)
        s = my_exec(["./main", str(t), str(i)])
        if s == "P":
            passed += 1
        else:
            failed += 1
    line = "Running Test: " + t_name + "\n"
    line += "Finished\n"
    line += "killed: " + str(failed) + "\n"
    line += "Success: " + str(passed) + "\n"
    test_log += line

end = time.time()
elapsed = end - begin

test_log = "Test Log ("+str(elapsed)+")\n" + test_log

print("TEST LOG BEGIN")
print(test_log)
