import sys
import os.path
import time
from enum import Enum

class Sched(Enum):
    SANITY_LOOP = 0
    SANITY_TERMINATION = 1
    OBE = 2
    S_OBE = 3
    HSA = 4
    S_HSA = 5
    HSA_OBE = 6
    S_HSA_OBE = 7
    # HSA PRIORITY CURRENTLY NOT PRINTED
    HSA_P = 8
    S_HSA_P = 9
    LOBE = 10
    S_LOBE = 11
    W_FAIR = 12
    S_FAIR = 13

def main(argv):
    txtFile = argv[0]
    index = argv[1]

    results = []
    f = open(txtFile, "r")
    text = f.read()
    ind = 0
    for i in range(14):
        if ((text.find("FAIL", ind) < text.find("PASS", ind) and text.find("FAIL", ind) != -1) or text.find("PASS", ind) == -1):
            results.append("FAIL")
            ind = text.find("FAIL", ind) + 4
        else:
            results.append("PASS")
            ind = text.find("PASS", ind) + 4
    f.close()

    txtFile = txtFile.replace("_output", "")
    f = open(txtFile, "w+")
    f.write("SANITY CHECK ---------------------\n")
    f.write("Unfair - At least one lasso: " + results[0] + "\n")
    f.write("Unfair - Can reach termination: " + results[1] + "\n")
    f.write("\n")
    f.write("SCHEDULER RESULTS ---------------------\n")
    f.write("WEAK VARIANTS ---------------------\n")
    f.write("OBE - Termination: " + results[2] + "\n")
    f.write("HSA - Termination: " + results[4] + "\n")
    f.write("HSA_OBE - Termination: " + results[6] + "\n")
    f.write("LOBE - Termination: " + results[10] + "\n")
    f.write("WEAK_FAIR - Termination: " + results[12] + "\n")
    f.write("\n")
    f.write("STRONG VARIANTS ---------------------\n")
    f.write("OBE_STRONG - Termination: " + results[3] + "\n")
    f.write("HSA_STRONG - Termination: " + results[5] + "\n")
    f.write("HSA_OBE_STRONG - Termination: " + results[7] + "\n")
    f.write("LOBE_STRONG - Termination: " + results[11] + "\n")
    f.write("STRONG_FAIR - Termination: " + results[13] + "\n")
    f.write("\n")   
    f.close()

    # Distinguishing Test Labeling

    # If hierarchy is not respected ERROR
    # We first check weak hierarchy
    if (results[Sched.OBE.value]>results[Sched.HSA_OBE.value] or
        results[Sched.HSA.value]>results[Sched.HSA_OBE.value] or
        results[Sched.HSA_OBE.value]>results[Sched.LOBE.value] or
        results[Sched.LOBE.value]>results[Sched.W_FAIR.value] or 

        # We then check strong hierarchy
        results[Sched.S_OBE.value]>results[Sched.S_HSA_OBE.value] or
        results[Sched.S_HSA.value]>results[Sched.S_HSA_OBE.value] or
        results[Sched.S_HSA_OBE.value]>results[Sched.S_LOBE.value] or
        results[Sched.S_LOBE.value]>results[Sched.S_FAIR.value] or 
        
        # Respective Strong versions should PASS if the Weak ones do
        results[Sched.OBE.value]>results[Sched.S_OBE.value] or
        results[Sched.HSA.value]>results[Sched.S_HSA.value] or
        results[Sched.HSA_OBE.value]>results[Sched.S_HSA_OBE.value] or
        results[Sched.LOBE.value]>results[Sched.S_LOBE.value] or
        results[Sched.W_FAIR.value]>results[Sched.S_FAIR.value] ):
        
        f = open("../../distinguishing/error.txt", "a+")
        f.write(str(index) + "\n")
        f.close()
        return 0
    
    # If we did not fail the hierarchy, we process the test to see if it is distinguishing
    if (results[Sched.OBE.value] < results[Sched.HSA.value] and
        results[Sched.S_OBE.value] < results[Sched.HSA.value]):
        f = open("../../distinguishing/hsa.txt", "a+")
        f.write(str(index) + "\n")
        f.close()

    if (results[Sched.HSA.value] < results[Sched.OBE.value] and
        results[Sched.S_HSA.value] < results[Sched.OBE.value]):
        f = open("../../distinguishing/obe.txt", "a+")
        f.write(str(index) + "\n")
        f.close()

    if (results[Sched.OBE.value] < results[Sched.HSA_OBE.value] and
        results[Sched.HSA.value] < results[Sched.HSA_OBE.value] and
        results[Sched.S_OBE.value] < results[Sched.HSA_OBE.value] and 
        results[Sched.S_HSA.value] < results[Sched.HSA_OBE.value]):
        f = open("../../distinguishing/hsa_obe.txt", "a+")
        f.write(str(index) + "\n")
        f.close()

    if (results[Sched.HSA_OBE.value] < results[Sched.LOBE.value] and 
        results[Sched.S_HSA_OBE.value] < results[Sched.LOBE.value]):
        f = open("../../distinguishing/lobe.txt", "a+")
        f.write(str(index) + "\n")
        f.close()

    if (results[Sched.LOBE.value] < results[Sched.W_FAIR.value] and
        results[Sched.S_LOBE.value] < results[Sched.W_FAIR.value]):
        f = open("../../distinguishing/w_fair.txt", "a+")
        f.write(str(index) + "\n")
        f.close()
    

    # We do the same with strong fairness
    if (results[Sched.W_FAIR.value] < results[Sched.S_FAIR.value] and
        results[Sched.S_LOBE.value] < results[Sched.S_FAIR.value]):
        f = open("../../distinguishing/strong_fair.txt", "a+")
        f.write(str(index) + "\n")
        f.close()

    if (results[Sched.W_FAIR.value] < results[Sched.S_LOBE.value] and
        results[Sched.S_HSA_OBE.value] < results[Sched.S_LOBE.value]):
        f = open("../../distinguishing/strong_lobe.txt", "a+")
        f.write(str(index) + "\n")
        f.close()
    
    if (results[Sched.W_FAIR.value] < results[Sched.S_HSA_OBE.value] and
        results[Sched.HSA.value] < results[Sched.S_HSA_OBE.value] and
        results[Sched.OBE.value] < results[Sched.S_HSA_OBE.value]):
        f = open("../../distinguishing/strong_hsa_obe.txt", "a+")
        f.write(str(index) + "\n")
        f.close()

    if (results[Sched.W_FAIR.value] < results[Sched.S_HSA.value] and
        results[Sched.S_OBE.value] < results[Sched.S_HSA.value]):
        f = open("../../distinguishing/strong_hsa.txt", "a+")
        f.write(str(index) + "\n")
        f.close()

    if (results[Sched.W_FAIR.value] < results[Sched.S_OBE.value] and
        results[Sched.S_HSA.value] < results[Sched.S_OBE.value]):
        f = open("../../distinguishing/strong_hsa.txt", "a+")
        f.write(str(index) + "\n")
        f.close()

    return 0
               
      
if __name__ == "__main__": 
  
    # calling main function 
    main(sys.argv[1:])
