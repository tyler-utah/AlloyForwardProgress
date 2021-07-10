import sys
import os
import time
import xml.etree.ElementTree as ET
import filecmp
import datetime

# MANUAL COMPARISON
#def compareFiles(fn1, fn2):
#    content1 = open(fn1, 'r').read()
#    content2 = open(fn2, 'r').read()
#   return content1 == content2
#compareFiles("a"+ str(i) + ".txt", "a"+ str(n) + ".txt"):
     
def main(argv):
    folderName = argv[0]
    index = int(argv[1])

    fnN = "../"+ folderName+ "/" + str(index) + "/"+ str(index) + ".txt"
    if os.path.isfile(fnN):
        delete = False
        for i in range(index):
            fnI = "../"+ folderName+ "/" + str(i) + "/"+ str(i) + ".txt"
            if os.path.isfile(fnI) and filecmp.cmp(fnI, fnN, False):
                delete = True
                os.remove(fnN)
                print(1)
                break
    if not delete:
        # If file is not duplicate, add record that we found a new test
        f = open("../"+ folderName+ "/timestamps.txt", "a+")
        now = datetime.datetime.now()
        f.write(now.strftime("%Y-%m-%d %H:%M:%S") + "\n")
        f.close()
        print(0)
               
      
if __name__ == "__main__": 
  
    # calling main function 
    main(sys.argv[1:]) 