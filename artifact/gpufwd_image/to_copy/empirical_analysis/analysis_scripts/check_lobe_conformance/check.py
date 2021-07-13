import os
import sys
import re
import pdb

empirical_base_path = "../../empirical_results/"
formal_base_path = "../../../synthesis_analysis/formal_results"

devices = ["GeForce 940M", "Quadro RTX 4000", "A14", "A12", "Intel HD620", "Mali-G77", "Adreno 620", "Tegra X1"]

device_alias = {"Quadro RTX 4000": "CUDA/toucan_quadro_rtx4000-inter-workgroup.csv",
                "GeForce 940M" : "CUDA/laptop_940m-inter-workgroup.csv",
                "A14" : "Apple/iphone_12_a14-inter-workgroup.csv",
                "A12" : "Apple/ipad_air_3_a12-inter-workgroup.csv",
                "Mali-G77": "Vulkan/galaxy-s20-mali-2021-02-07.csv",
                "Adreno 620" : "Vulkan/pixel5-adreno-2021-02-06.csv",
                "Tegra X1" : "Vulkan/results-NVIDIA-SHIELD-Android-TV.csv",
                "Intel HD620": "Vulkan/intelHD620-2021-03-16.csv"}

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
    p = os.path.join(formal_base_path,c,"schedulers/LOBE_results.csv")
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

for d in devices:
    print("Checking device:",d)
    fn = 0
    for c in config:
        r = find_ff_d_tests(c)
        dp = device_alias[d]
        p = get_csv_path(d,c)
        data = split_d(get_data(p))

        for t in r:
            v,vv = check_res(data[t])
            if v in ["F"]:
                if verbose:
                    print("found failed test")
                    print("config:",c)
                    print("id:",t)
                    print("plain fails:",pp_status(vv[0]))
                    print("round-robin fails:",pp_status(vv[1]))
                    print("chunked failes:", pp_status(vv[2]))
                    print("--")
                fn += 1
                #assert(False)
                #if v == "P":
                #print("passed:",c,d,t)
                #if v == "D":
                #c_d += 1
    if fn == 0:
        print("passed LOBE conformance")
    else:
        print("FAILED LOBE conformance")
        print("Failed tests:", fn)
        print("Run with command line arg -v to see tests")
    print("------------")
    #print("device failed count:", d,fn)


