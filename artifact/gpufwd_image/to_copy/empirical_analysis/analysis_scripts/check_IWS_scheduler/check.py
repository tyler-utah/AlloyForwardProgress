import os
import pdb
import re
import sys

empirical_base_path = "../../empirical_results/"
formal_base_path = "../../../synthesis_analysis/formal_results"

devices = ["Quadro RTX 4000 (IWS)", "Quadro RTX 4000"]

device_alias = {"Quadro RTX 4000 (IWS)": "CUDA/toucan_quadro_rtx4000_subgroup_sm70.csv",
                "Quadro RTX 4000": "CUDA/toucan_quadro_rtx4000_subgroup.csv"}

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
    p = os.path.join(formal_base_path,c,"schedulers/LOBE_STRONG_results.csv")
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
            #pdb.set_trace()
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

verbose = False
if "-v" in sys.argv:
    verbose = True

def pp_status(s):
    return s.replace("P","0").replace("(","").replace(")","").replace(" ","").replace("F","")

print("checking weak fairness")
def pp_device_prop(d):
    if ("IWS" in d):
        return "IWS"
    else:
        return "non-IWS"
for d in devices:
    c_f = 0
    for c in config:
        r = find_ff_d_tests(c)
        dp = device_alias[d]
        p = get_csv_path(d,c)
        data = split_d(get_data(p))
        for t in r:
            v,vv = check_res(data[t])
            if v in ["F"]:
                assert("(IWS)" not in d)
                if verbose:
                    print("found failed test")
                    print("config:",c)
                    print("id:",t)
                    print("plain fails:",pp_status(vv[0]))
                    print("--")

                    
                c_f += 1
                
    if c_f == 0:
        print("passed all weak fairness for the " + pp_device_prop(d) + " setting")
    else:
        print("failed " + str(c_f) + " weak fairness tests for the " + pp_device_prop(d) + " setting")
if not verbose:
    print("run with -v to see failure test information")


print("------------------")
print("checking strong fairness")


for d in devices:
    c_f = 0
    for c in config:
        r = find_ff_d_tests2(c)
        dp = device_alias[d]
        p = get_csv_path(d,c)
        data = split_d(get_data(p))

        for t in r:
            v,vv = check_res(data[t])
            if v in ["F"]:
                c_f+=1
                if verbose:
                    print("found failed test")
                    print("config:",c)
                    print("id:",t)
                    print("plain fails:",pp_status(vv[0]))
                    print("--")


    if c_f == 0:
        print("passed all strong fairness for the " + pp_device_prop(d) + " setting")
    else:
        print("failed " + str(c_f) + " strong fairness tests for the " + pp_device_prop(d) + " setting")
if not verbose:
    print("run with -v to see failure test information")



