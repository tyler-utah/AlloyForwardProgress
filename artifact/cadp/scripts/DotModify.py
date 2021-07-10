import sys
import os.path
import time
import re
import xml.etree.ElementTree as ET 

def InstructionString(path, operationName):
    tree = ET.parse(path) 
    root = tree.getroot()
    
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

            nOp = 0
            while operations[nOp] != operation:
                nOp +=1

            chkLoc = chkLoc[2:]
            op_code = operation.replace("$", "")
            thd = 'Thread ' + str(i) + " Instruction " + str(nOp)

            if op_code == operationName:
                if (nextPo == branch_target): 
                    return thd + '\nMem['+ chkLoc + '] =' + exchVal + ';'
                else:
                    if branch_target == "":
                        if (exchVal == ""):
                            return thd + '\nif (Mem['+ chkLoc + '] ==' + chkVal + ')\n goto END;'
                        else:
                            return thd + '\nif (Exch(Mem['+ chkLoc + '], '+ exchVal + ') == ' + chkVal + ')\n goto END;'
                    else:
                        nInst = 0
                        while operations[nInst] != branch_target:
                            nInst +=1
                        if (exchVal == ""):
                            return thd + '\nif (Mem['+ chkLoc + '] ==' + chkVal + ')\n goto ' + str(nInst) + ';'
                        else:
                            return thd + '\nif (Exch(Mem['+ chkLoc + '], '+ exchVal + ') == ' + chkVal + ')\n goto '+ str(nInst) + ';'

            operation = nextPo
    return ""

def readEndpoints(str):
    index = str.find("\" -> \"")
    index2 = str.find("\" [")

    if str.find("forward") != -1:
        return int(str[2:index]), int(str[index+1 + len("\" -> \""):index2])
    else:
        return int(str[index+1 + len("\" -> \""):index2]), int(str[2:index])
     
def convertDot(path): 
    f = open(path, "r")
    lines = f.readlines()

    f_1 = open(path, "r")
    all_content = f_1.read()

    xml_path = path.replace(".dot",".xml")
    new_path = path.replace(".dot", "_simple.dot")
    f2 = open(new_path, "w")

    edges = {}
    for i in range(0,len(lines)):
        if lines[i].find("\" -> \"") != -1:
            if lines[i].find("pre") != -1:
                lines[i] = lines[i].replace("back", "forward")

            a, b = readEndpoints(lines[i])
            if not a in edges:
                edges[a] = []
            if not b in edges:
                edges[b] = []
            edges[a].append(b)

    for i in range(0,len(lines)):
        # Write beginning lines
        if i < 5:
            f2.write(lines[i])

        # If line is an edge
        if lines[i].find("\" -> \"") != -1:
            # Make edges black (remove pre/post labels)
            lines[i] = re.sub(", color = \"#......\"",", color = \"#000000\"",lines[i])
            lines[i] = re.sub(", fontcolor = \"#......\"",", fontcolor = \"#ffffff\"",lines[i])

            # Check if line is part of a cycle (via BFS)
            # Remove line and see if we can still reach the start from the endpoint
            start, current = readEndpoints(lines[i])
            visited = {}
            visited[current] = True
            ordered = []
            ordered.append(current)

            colorEdge = False

            index = 0
            while index < len(ordered):
                current = ordered[index]
                if current == start:
                    colorEdge = True
                    break

                for j in range(0, len(edges[current])):
                    if edges[current][j] in visited:
                        continue
                    ordered.append(edges[current][j])
                    visited[edges[current][j]] = True
                index += 1

            if colorEdge == True:
                lines[i] = re.sub(", color = \"#......\"",", color = \"#ff0000\"",lines[i])

            # If label is post write
            if lines[i].find("post") != -1:
                lines[i] = lines[i].replace("post", "")
                f2.write(lines[i])
            # If label is pre, change direction and write
            if lines[i].find("pre") != -1:
                lines[i] = lines[i].replace("pre", "")
                f2.write(lines[i])

        # If vertex is a state
        if lines[i].find("uuid=\"S") != -1 or lines[i].find("uuid=\"E") != -1:
            # Make vertex white fill with black borders
            lines[i] = re.sub(", color=\"#......\"",", fillcolor = \"#ffffff\"",lines[i])
            lines[i] = re.sub(", fontcolor = \"#......\"",", fontcolor = \"#000000\"",lines[i])

            # Change Start and End states to have a different color
            if lines[i].find("uuid=\"ST") != -1:
                lines[i] = re.sub(", fillcolor = \"#......\"",", fillcolor = \"#6396ef\"",lines[i])

            if lines[i].find("uuid=\"E") != -1:
                lines[i] = re.sub(", fillcolor = \"#......\"",", fillcolor = \"#31cf31\"",lines[i])
            
            # Replace label with memory state
            words = re.split(r"(\\|\s)\s*", lines[i])
            mem_name = ""
            for j in range(0, len(words)):
                if words[j].find("G_mem") != -1:
                    mem_name = words[j]
            
            search = mem_name + "\\nmem: "
            find_loc = all_content.find(search) + len(search)
            end_loc = all_content.find("\", color", find_loc)

            exc_str = all_content[find_loc:end_loc]
            exc_str = exc_str.replace("$0", "")

            exc_str = exc_str.replace("X-", "Mem[0")
            exc_str = exc_str.replace("X", "Mem[")

            exc_str = exc_str.replace("->", "] = ")
            exc_str = exc_str.replace(">", "] = ")

            exc_str = exc_str.replace("ZERO", "0")
            exc_str = exc_str.replace("ONE", "1")

            find_loc = lines[i].find("label=\"")
            end_loc = lines[i].find("\",", find_loc)
            rep_str = lines[i][find_loc:end_loc]
            
            lines[i] = lines[i].replace(rep_str,"label=\"" + exc_str)
            f2.write(lines[i])

        # If vertex is an action
        if lines[i].find("uuid=\"A") != -1 and lines[i].find("uuid=\"AT") == -1:
            lines[i] = re.sub(", color=\"#......\"",", fillcolor = \"#ffffff\"",lines[i])
            lines[i] = re.sub(", fontcolor = \"#......\"",", fontcolor = \"#000000\"",lines[i])

            words = re.split(r"(\\|\s|\")\s*", lines[i])
            op_name = ""
            for j in range(0, len(words)):
                if words[j].find("ATOMIC") != -1:
                    op_name = words[j]

            find_loc = lines[i].find("label=\"")
            end_loc = lines[i].find("\",", find_loc)
            rep_str = lines[i][find_loc:end_loc]

            lines[i] = lines[i].replace(rep_str,"label=\"" + InstructionString(xml_path,op_name))
            

            f2.write(lines[i])
    
    f2.write("}")

def main(argv):
    path = argv[0]
    if os.path.isfile(path):
        convertDot(path)
        return 1
    
    return 0
               
      
if __name__ == "__main__": 
  
    # calling main function 
    main(sys.argv[1:])