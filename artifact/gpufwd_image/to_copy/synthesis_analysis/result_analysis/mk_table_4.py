# doesn't actually make a csv, but prints out useful data you have to copy by hand into the CSV

import os
import pdb
data_path = "../formal_results"

runs = ["2_thread_2_instruction",
        "2_thread_3_instruction",
        "2_thread_4_instruction",
        "3_thread_3_instruction",
        "3_thread_4_instruction",]

runs_alias = {"2_thread_2_instruction" : "2t\\\_2i",
        "2_thread_3_instruction" : "2t\\\_3i",
        "2_thread_4_instruction" : "2t\\\_4i",
        "3_thread_3_instruction" : "3t\\\_3i",
        "3_thread_4_instruction" : "3t\\\_4i"}

post_fix = "schedulers"

scheduler_order = ["STRONG_FAIR_results.csv", "LOBE_STRONG_results.csv", "OBE_STRONG_results.csv", "HSA_STRONG_results.csv","WEAK_FAIR_results.csv", "LOBE_results.csv", "OBE_results.csv", "HSA_results.csv"]

def get_fcontents(fpath):
    f = open(fpath)
    data = f.read()
    f.close()
    return data.split("\n")[1:-2]

#populate sets for all schedulers
STRONG_FAIR_SET = {}
STRONG_FAIR = {}
for r in runs:
    STRONG_FAIR[r] = get_fcontents(os.path.join(data_path,r,post_fix,"STRONG_FAIR_results.csv"))
    STRONG_FAIR_SET[r] = set()

STRONG_LOBE_SET = {}
STRONG_LOBE = {}
for r in runs:
    STRONG_LOBE[r] = get_fcontents(os.path.join(data_path,r,post_fix,"LOBE_STRONG_results.csv"))
    STRONG_LOBE_SET[r] = set()

STRONG_OBE_SET = {}
STRONG_OBE = {}
for r in runs:
    STRONG_OBE[r] = get_fcontents(os.path.join(data_path,r,post_fix,"OBE_STRONG_results.csv"))
    STRONG_OBE_SET[r] = set()

STRONG_HSA_SET = {}
STRONG_HSA = {}
for r in runs:
    STRONG_HSA[r] = get_fcontents(os.path.join(data_path,r,post_fix,"HSA_STRONG_results.csv"))
    STRONG_HSA_SET[r] = set()

WEAK_FAIR_SET = {}
WEAK_FAIR = {}
for r in runs:
    WEAK_FAIR[r] = get_fcontents(os.path.join(data_path,r,post_fix,"WEAK_FAIR_results.csv"))
    WEAK_FAIR_SET[r] = set()

WEAK_LOBE_SET = {}
WEAK_LOBE = {}
for r in runs:
    WEAK_LOBE[r] = get_fcontents(os.path.join(data_path,r,post_fix,"LOBE_results.csv"))
    WEAK_LOBE_SET[r] = set()

WEAK_OBE_SET = {}
WEAK_OBE = {}
for r in runs:
    WEAK_OBE[r] = get_fcontents(os.path.join(data_path,r,post_fix,"OBE_results.csv"))
    WEAK_OBE_SET[r] = set()

WEAK_HSA_SET = {}
WEAK_HSA = {}
for r in runs:
    WEAK_HSA[r] = get_fcontents(os.path.join(data_path,r,post_fix,"HSA_results.csv"))
    WEAK_HSA_SET[r] = set()

scheduler_order = [STRONG_FAIR, STRONG_LOBE, STRONG_OBE, STRONG_HSA, WEAK_FAIR, WEAK_LOBE, WEAK_OBE, WEAK_HSA]

scheduler_order_sets = [STRONG_FAIR_SET, STRONG_LOBE_SET, STRONG_OBE_SET, STRONG_HSA_SET, WEAK_FAIR_SET, WEAK_LOBE_SET, WEAK_OBE_SET, WEAK_HSA_SET]

def populate_weak_tests():
    for r in runs:
        num_tests = len(WEAK_HSA[r])
        for i in range(num_tests):
            s = WEAK_FAIR
            allowed = s[r][i].split(",")[1] == "P"
            if not allowed:
                continue
            s = WEAK_HSA
            hsa_allowed = s[r][i].split(",")[1] == "P"
            s = WEAK_OBE
            obe_allowed = s[r][i].split(",")[1] == "P"
            
            s = WEAK_LOBE
            lobe_allowed = s[r][i].split(",")[1] == "P"

            if (hsa_allowed and obe_allowed and (not lobe_allowed)):
                ## theoretically not impossible, but we want to check it for our tests
                assert(0)

            if (hsa_allowed):
                WEAK_HSA_SET[r].add((r,i))
                continue

            if (obe_allowed):
                WEAK_OBE_SET[r].add((r,i))
                continue

            if (lobe_allowed):
                WEAK_LOBE_SET[r].add((r,i))
                continue
        
            if (allowed):
                WEAK_FAIR_SET[r].add((r,i))

def populate_strong_tests():
    for r in runs:
        num_tests = len(WEAK_HSA[r])
        for i in range(num_tests):
            s = WEAK_FAIR
            allowed = s[r][i].split(",")[1] == "P"
            if allowed:
                continue
            s = STRONG_HSA
            hsa_allowed = s[r][i].split(",")[1] == "P"
            s = STRONG_OBE
            obe_allowed = s[r][i].split(",")[1] == "P"
            #print(obe_allowed)

            s = STRONG_LOBE
            lobe_allowed = s[r][i].split(",")[1] == "P"

            if (hsa_allowed and obe_allowed and (not lobe_allowed)):
                ## theoretically not impossible, but we want to check it for our tests
                assert(0)

            if (hsa_allowed):
                STRONG_HSA_SET[r].add((r,i))
                continue

            if (obe_allowed):
                STRONG_OBE_SET[r].add((r,i))
                continue

            if (lobe_allowed):
                STRONG_LOBE_SET[r].add((r,i))
                continue
            else:
                STRONG_FAIR_SET[r].add((r,i))
                continue

        
populate_weak_tests()
populate_strong_tests()
total_weak = 0
total_strong = 0
total_scheds = [0 for x in range(len(scheduler_order_sets))]
for r in runs:
    line = runs_alias[r]
    #assert(len(scheduler_order_sets[4:]) == 4)
    total_weak += sum([len(x[r]) for x in scheduler_order_sets[4:]])
    total_strong += sum([len(x[r]) for x in scheduler_order_sets[:4]])
    
    x = 0
    for s in scheduler_order_sets[:4]:
        total_scheds[x] += len(s[r])
        x += 1

    for s in scheduler_order_sets[4:]:
        total_scheds[x] += len(s[r])
        x += 1


percents_weak   = [str("{:.2f}".format((x/total_weak)*100)) for x in total_scheds[4:]]
percents_strong = [str("{:.2f}".format((x/total_strong)*100)) for x in total_scheds[:4]]
line =  " Table 4"
line += "\n\n"
line += "         Weak Fairness              Strong Fairness\n"
line += "         -----------------------    ------------------------\n"
line += " Model   D. Tests       C. Tests    D. Tests      C. Tests\n"
line += "------------------------------------------------------------\n"
line += " HSA     " + str(total_scheds[7]) + "  (" + percents_weak[3] + "%)" + "   " + str(total_scheds[7])
line += "         "  + str(total_scheds[3]) + "  (" + percents_strong[3] + "%)" + "   " + str(total_scheds[3]) + "\n"
line += " OBE     " + str(total_scheds[6]) + "  (" + percents_weak[2] + "%)" + "    " + str(total_scheds[6])
line += "         "  + str(total_scheds[2]) + "   (" + percents_strong[2] + "%)" + "    " + str(total_scheds[2]) + "\n"
line += " LOBE    " + str(total_scheds[5]) + "  (" + percents_weak[1] + "%)" + "    " + str(sum(total_scheds[5:8]))
line += "        "  + str(total_scheds[1]) + "  (" + percents_strong[1] + "%)" + "   " + str(sum(total_scheds[1:4])) + "\n"
line += " FULL    " + str(total_scheds[4]) +  " (" + percents_weak[0] + "%)" + "   " + str(sum(total_scheds[4:8]))
line += "        "  + str(total_scheds[0]) + "  (" + percents_strong[0] + "%)" + "   " + str(sum(total_scheds[0:4])) + "\n"
    
print(line)

