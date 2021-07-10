import sys
import os.path
import time
import xml.etree.ElementTree as ET

def RecursiveAddClauses(index, condition, nThreads, myList):
    if (index == nThreads):
        if len(myList) == 0:
            return condition

        setStr = "{"
        for i in range(len(myList) - 1):
            setStr += str(myList[i]) + ", "
        setStr += str(myList[len(myList)-1]) + "}"

        toAppend = "( < "
        for i in range(len(myList) - 1):
            toAppend += " \'EX !" + str(myList[i]) + " .* !" + setStr + "\' . true* ."
        toAppend += " \'EX !" + str(myList[len(myList)-1]) + " .* !" + setStr + "\' . true* > @ )"

        if len(myList) == nThreads:
            toAppend = toAppend + ");"
        else:
            toAppend = toAppend + " or "

        return condition + toAppend
    else:
        condition = RecursiveAddClauses(index+1, condition, nThreads, myList)
        myList.append(index)
        condition = RecursiveAddClauses(index+1, condition, nThreads, myList)
        myList.pop()
        return condition

def generateSVLCondition(nThreads):
    return "<true*> (" + RecursiveAddClauses(0, "", nThreads, [])

def createCADPString(filename):
    # create element tree object and get root
    tree = ET.parse(filename)
    root = tree.getroot()

    # Check the number of threads in XML
    nItems = 0
    # iterate child elements of item
    for sig in root.findall('./instance/sig'):
        if sig.get('label') == 'this/Thread':
            nItems = len(sig.findall('./atom'))

    output=""

    # Find name of first thread
    index = -1
    for field in root.findall('./instance/field'):
        if field.get('label') == 't_order':
            tNotFound = True
            while tNotFound:
                index += 1
                tNotFound = False
                for child in field.findall('./tuple'):
                    atoms = child.findall('./atom')
                    if atoms[1].get('label') == 'Thread$' + str(index):
                        tNotFound = True
    nextThreadName = 'Thread$' + str(index)

    # For each thread we will print all the instructions!
    for i in range(nItems):

        threadName = nextThreadName
        output += '       THREAD [EX, TERMINATE] (' + str(i) + ', {\n';

        # Find next thread
        for field in root.findall('./instance/field'):
            if field.get('label') == 't_order':
                for child in field.findall('./tuple'):
                    atoms = child.findall('./atom')
                    if atoms[0].get('label') == threadName:
                        nextThreadName = atoms[1].get('label')

        #Initialize operation array
        operations = []

        #Check the name of the beginning operation
        state = ""
        for field in root.findall('./instance/field'):
            if field.get('label') == 'T_state':
                for child in field.findall('./tuple'):
                    atoms = child.findall('./atom')
                    if atoms[0].get('label') == 'START$0' and atoms[1].get('label') == threadName:
                        state = atoms[2].get('label')

        operation = ""
        for field in root.findall('./instance/field'):
            if field.get('label') == 'next_ins':
                for child in field.findall('./tuple'):
                    atoms = child.findall('./atom')
                    if atoms[0].get('label') == state:
                        operation = atoms[1].get('label')

        operations.append(operation)
        while operation != "":
            aux = ""
            # Find next operation
            for field in root.findall('./instance/field'):
                if field.get('label') == 'po':
                    for child in field.findall('./tuple'):
                        atoms = child.findall('./atom')
                        if atoms[0].get('label') == operation:
                            aux = atoms[1].get('label')
            operations.append(aux)
            operation = aux

        # Check if there is another instruction after it
        # Break if last instruction
        operation = operations[0]
        while operation != "":
            chkLoc = ""
            exchVal = ""
            chkVal = ""
            nextPo = ""
            branch_target = ""
            # Write the details of the operation
            for field in root.findall('./instance/field'):
                if field.get('label') == 'check_loc':
                    for child in field.findall('./tuple'):
                        atoms = child.findall('./atom')
                        if atoms[0].get('label') == operation:
                            chkLoc = atoms[1].get('label')

                if field.get('label') == 'exch_val':
                    for child in field.findall('./tuple'):
                        atoms = child.findall('./atom')
                        if atoms[0].get('label') == operation:
                            exchVal = atoms[1].get('label')

                if field.get('label') == 'check_val':
                    for child in field.findall('./tuple'):
                        atoms = child.findall('./atom')
                        if atoms[0].get('label') == operation:
                            chkVal = atoms[1].get('label')

                if field.get('label') == 'po':
                    for child in field.findall('./tuple'):
                        atoms = child.findall('./atom')
                        if atoms[0].get('label') == operation:
                            nextPo = atoms[1].get('label')

                if field.get('label') == 'branch_target':
                    for child in field.findall('./tuple'):
                        atoms = child.findall('./atom')
                        if atoms[0].get('label') == operation:
                            branch_target = atoms[1].get('label')

            if (chkVal == "ZERO$0"):
                chkVal = "0"
            else:
                if (chkVal == "ONE$0"):
                    chkVal = "1"

            if (exchVal == "ZERO$0"):
                exchVal = "0"
            else:
                if (exchVal == "ONE$0"):
                    exchVal = "1"

            chkLoc = chkLoc[2:]

            nInst = 0
            if branch_target == "":
                nInst = len(operations)-1
            else:
                while operations[nInst] != branch_target:
                    nInst +=1

            if exchVal == "":
                output += "                            ATOMIC_EXCH_BRANCH(MemLoc(" + str(int(chkLoc)+1) + "), 0, false, "+ chkVal +", " + str(nInst + 1) + ", true)"
            else:
                output += "                            ATOMIC_EXCH_BRANCH(MemLoc(" + str(int(chkLoc)+1) + "), " + str(exchVal) + ", true, " + chkVal + ", " + str(nInst + 1) + ", true)"

            if (nextPo != ""):
                output += ","
            output += "\n"

            operation = nextPo

        output += "      })\n"
        if i < nItems-1:
            output += "\n    ||\n\n"

    return output, str(nItems)

def writeCADPFile(CADPfolder, folder, index, filename, replace, threads, condition = ""):
    f = open(CADPfolder + "/checker/" + filename, "r")
    s = f.read()
    s = s.replace("prod_cons", "test_" + str(index))
    s = s.replace("$REPLACE$", replace)
    s = s.replace("$N_THREADS$", threads)
    s = s.replace("$FORMULA$", condition)
    f.close()

    filename = filename.replace("prod_cons", "test_" + str(index))
    w = open(folder + "/checker/" + filename, "w")
    w.write(s)
    w.close()

def main(argv):
    folderName = argv[0]
    index = argv[1]

    CADPfolder = argv[2]

    replace, threads = createCADPString(folderName + "/"+ str(index)+".xml")
    condition = generateSVLCondition(int(threads))

    try:
        os.mkdir(folderName +"checker")
    except:
        pass

    writeCADPFile(CADPfolder, folderName, index,"prod_cons_hsa.lnt", replace, threads)
    writeCADPFile(CADPfolder, folderName, index, "prod_cons_obe.lnt", replace, threads)
    writeCADPFile(CADPfolder, folderName, index, "prod_cons_lobe.lnt", replace, threads)
    writeCADPFile(CADPfolder, folderName, index, "prod_cons_hsa_obe.lnt", replace, threads)
    writeCADPFile(CADPfolder, folderName, index, "prod_cons_hsa_priority.lnt", replace, threads)
    writeCADPFile(CADPfolder, folderName, index, "prod_cons_weak.lnt", replace, threads)

    writeCADPFile(CADPfolder, folderName, index,"prod_cons_hsa_strong.lnt", replace, threads)
    writeCADPFile(CADPfolder, folderName, index, "prod_cons_obe_strong.lnt", replace, threads)
    writeCADPFile(CADPfolder, folderName, index, "prod_cons_lobe_strong.lnt", replace, threads)
    writeCADPFile(CADPfolder, folderName, index, "prod_cons_hsa_obe_strong.lnt", replace, threads)
    writeCADPFile(CADPfolder, folderName, index, "prod_cons_hsa_priority_strong.lnt", replace, threads)
    writeCADPFile(CADPfolder, folderName, index, "prod_cons_strong.lnt", replace, threads)

    writeCADPFile(CADPfolder, folderName, index, "prod_cons_none.lnt", replace, threads)
    writeCADPFile(CADPfolder, folderName, index, "common.lnt", replace, threads)
    writeCADPFile(CADPfolder, folderName, index, "common_strong.lnt", replace, threads)
    writeCADPFile(CADPfolder, folderName, index, "prod_cons.svl", replace, threads, condition)

if __name__ == "__main__":

    # calling main function
    main(sys.argv[1:])
