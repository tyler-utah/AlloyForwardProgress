import os
import sys
import re
import pdb

empirical_base_path = "../../empirical_results/"
formal_base_path = "../../../synthesis_analysis/formal_results"

devices = ["Quadro RTX 4000"]

device_alias = {"Quadro RTX 4000": "CUDA/toucan_quadro_rtx4000_coop-inter-workgroup.csv"}

config = ["2_thread_2_instruction",
          "2_thread_3_instruction",
          "2_thread_4_instruction",
          "3_thread_3_instruction",
          "3_thread_4_instruction"]

def get_data(fname):
    f = open(fname, 'r')
    ret = f.read()
    f.close()
    return ret

def find_ff_d_tests(c):
    ret = []
    p = os.path.join(formal_base_path,c,"schedulers/WEAK_FAIR_results.csv")
    data = get_data(p).split("\n")[1:-2]
    for t in data:
        if "P" in t:
            num = int(t.split(",")[0])
            ret.append(num)

    return ret

def find_ff_d_tests2(c):
    ret = []
    p = os.path.join(formal_base_path,c,"schedulers/STRONG_FAIR_results.csv")
    data = get_data(p).split("\n")[1:-2]
    for t in data:
        if "P" in t:
            num = int(t.split(",")[0])
            ret.append(num)

    return ret


def get_failed_and_total(s):
    tt = re.match('.*\((\d+)/(\d+)\).*',s)
    assert(tt)
    return int(tt[1]),int(tt[2])

def check_res(res):
    res = res.split(",")[1:4]
    for r in res:
        if "P" not in r:
            return "F",res
    return "P",res

def get_csv_path(d,c):
    da = device_alias[d]
    return os.path.join(empirical_base_path,c,da)

def split_d(d):
    d = d.split("\n")
    while d[-1] == '':
        d = d[:-1]
    assert("Total" in d[-1])
    assert("Test File" in d[0])
    return d[1:-1]

print("checking devices:", devices)
print("---------------")
print("checking weak fairness...")
for c in config:
    r = find_ff_d_tests(c)
    c_d = 0
    for d in devices:
        dp = device_alias[d]
        p = get_csv_path(d,c)
        data = split_d(get_data(p))

        for t in r:
            v,vv = check_res(data[t])
            if v in ["F"]:
                assert(False)


# it will fail the assert if weak fairness tests don't pass
print("passed weak fairness")
print("-----")
print("checking strong fairness")

verbose = False
if "-v" in sys.argv:
    verbose = True

def pp_status(s):
    return s.replace("P","0").replace("(","").replace(")","").replace(" ","").replace("F","")


c_d = 0
c_n = 0
for c in config:
    r = find_ff_d_tests2(c)
    for d in devices:
        dp = device_alias[d]
        p = get_csv_path(d,c)
        data = split_d(get_data(p))

        for t in r:
            v,vv = check_res(data[t])
            if v in ["F"]:
                c_d+=1
                if verbose:
                    print("found failed test")
                    print("config:",c)
                    print("id:",t)
                    print("plain fails:",pp_status(vv[0]))
                    print("round-robin fails:",pp_status(vv[1]))
                    print("chunked failes:", pp_status(vv[2]))
                    print("--")

            #if v in ["N"]:
            #    c_n+=1
            
                #if v == "P":
                #print("passed:",c,d,t)
                #if v == "D":
                #c_d += 1
if c_d == 0:
    print("passed strong fairness tests:", c_d)
else:
    print("Failed! Number of failed tests:", c_d)

if not verbose:
    print("run with -v to observe more information about failed tests")


