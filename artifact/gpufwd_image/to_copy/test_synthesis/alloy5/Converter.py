import sys
import os.path
import time
import xml.etree.ElementTree as ET 
     
def convertXML(filename, folderName): 
    # create element tree object and get root
    tree = ET.parse("../"+ folderName+ "/" + filename + "/"+ filename + ".xml")  
    root = tree.getroot() 

    try:
        os.mkdir("../"+ folderName +"/"+ filename)
    except:
        pass
    f = open("../"+ folderName+ "/" + filename + "/"+ filename + ".txt", "w")
    f2 = open("../"+ folderName+ "/" + filename + "/"+ filename + "_simple.txt", "w")
  
    # Check the number of threads in XML
    nItems = 0
    # iterate child elements of item 
    for sig in root.findall('./instance/sig'):
        if sig.get('label') == 'this/Thread':
            nItems = len(sig.findall('./atom'))

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
        f.write('THREAD' + str(i) + '\n')
        f2.write('THREAD ' + str(i) + '\n')

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
        nInst = 0
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

            if (nextPo == branch_target): 
                f.write('atomic_store('+ chkLoc + ',' + exchVal + ')\n')
                f2.write(str(nInst) + ': Mem['+ chkLoc + '] = ' + exchVal + ';')
            else:
                if branch_target == "":
                    if (exchVal == ""):
                        f.write('atomic_chk_branch('+ chkLoc + ',' + chkVal + ',END)\n')
                        f2.write(str(nInst) + ': if (Mem['+ chkLoc + '] == ' + chkVal + ') goto END;')
                    else:
                        f.write('atomic_exch_branch('+ chkLoc + ',' + chkVal + ',' + exchVal + ',END)\n')
                        f2.write(str(nInst) + ': if (Exch(Mem['+ chkLoc + '],' + exchVal + ') == ' + chkVal + ') goto END;')
                else:
                    nInst2 = 0
                    while operations[nInst2] != branch_target:
                        nInst2 +=1
                    if (exchVal == ""):
                        f.write('atomic_chk_branch('+ chkLoc + ',' + chkVal + ','+ str(nInst2) +  ')\n')
                        f2.write(str(nInst) + ': if (Mem['+ chkLoc + '] == ' + chkVal + ') goto ' + str(nInst2) + ';')
                    else:
                        f.write('atomic_exch_branch('+ chkLoc + ',' + chkVal + ',' + exchVal + ','+ str(nInst2) +  ')\n')
                        f2.write(str(nInst) + ': if (Exch(Mem['+ chkLoc + '],' + exchVal + ') == ' + chkVal + ') goto ' + str(nInst2) + ';')

            operation = nextPo
            nInst += 1
            f.write('\n')
            f2.write('\n')

        f.write('\n')
        f2.write('\n')

    f.close()
    f2.close()


def main(argv):
    folderName = argv[0]
    index = argv[1]

    if os.path.isfile("../"+ folderName+ "/" + index + "/"+ index + ".xml"):
        convertXML(index, folderName)
        print(1)
    else:
        print(0)
               
      
if __name__ == "__main__": 
  
    # calling main function 
    main(sys.argv[1:])
