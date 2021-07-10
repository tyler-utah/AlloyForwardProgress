import sys
import os.path
import time

def main(argv):
    pathToTxt = argv[0]

    f = open(pathToTxt, "r")
    all_content = f.read()

    all_content = all_content.replace(", END", ",END")
    f.close()

    f = open(pathToTxt, "w")
    f.write(all_content)
    f.close()
    
    return 0
               
      
if __name__ == "__main__": 
  
    # calling main function 
    main(sys.argv[1:])