import sys
import os.path
import os
import time

def processFile(folder, i, scheduler, output):
    fName = folder + "/" + str(i) + "/label_" + str(i) + ".txt"
    if os.path.isfile(fName):
        f = open(fName, "r")
        text = f.read()
        if text.find(scheduler + " - Termination: FAIL") != -1:
            output.write(str(i) + ",F,F,F,F\n")
            f.close()
            return 1
        else:
            if text.find(scheduler + " - Termination: PASS") != -1:
                output.write(str(i) + ",P,P,P,P\n")
                f.close()
                return 0
        f.close()
        return -1
    else:
        return -1

def main(argv):
    folder = argv[0]
    scheduler = argv[1]

    csv = open(folder + "/csv/" + scheduler + "_results.csv", "w")
    csv.write("Test File Name,No saturation Result,Round Robin Saturation Result,Chunking Saturation Result,All Passed\n")

    i = 0
    totalF = 0
    found = 0
    while found != -1:
        found = processFile(folder, i, scheduler, csv)
        if found == 1:
            totalF += 1
        i += 1

    totalF = str(totalF)
    csv.write("Total failures:,"+totalF+","+totalF+","+totalF+","+totalF+ "\n")
    csv.close()

    return 0


if __name__ == "__main__":

    # calling main function
    main(sys.argv[1:])
