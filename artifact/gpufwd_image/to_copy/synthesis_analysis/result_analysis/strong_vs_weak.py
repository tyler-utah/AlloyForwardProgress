# doesn't actually make a csv, but prints out useful data you have to copy by hand into the CSV

# looks at the weak fair results and finds the ones that are not guaranteed termination under the weakly fair scheduler.

import os
data_path = "../formal_results"

runs = ["2_thread_2_instruction",
        "2_thread_3_instruction",
        "2_thread_4_instruction",
        "3_thread_3_instruction",
        "3_thread_4_instruction",]

post_fix = "schedulers"

fname = "WEAK_FAIR_results.csv"

def get_fcontents(fpath):
    f = open(fpath)
    data = f.read()
    f.close()
    return data
    
total_test = 0
total_strong = 0
for r in runs:
    fpath = os.path.join(data_path,r,post_fix,fname)
    d = get_fcontents(fpath)
    num_tests = len(d.split('\n')) - 3
    last_line = d.split('\n')[-2].split(",")[1]
    print("checking: " + r)
    print("strong tests : " + str(num_tests-int(last_line)))
    print("weak tests   : " + last_line)    
    print("strong tests (%) : " + str("{:.2f}".format(100 - (int(last_line)/(num_tests)*100))))
    print("weak tests (%)   : " + str("{:.2f}".format(int(last_line)/(num_tests)*100)))
    print("-----")
    
    total_test += num_tests
    total_strong += int(last_line)

print("total:")
print("strong tests (%) : " + "{:.2f}".format(100 - (int(total_strong)/(total_test)*100)))
print("weak tests (%)   : " + "{:.2f}".format(int(total_strong)/(total_test)*100))
