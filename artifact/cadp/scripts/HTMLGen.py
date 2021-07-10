import sys
import os.path
import time

def main(argv):
    pathToHTML = argv[0]
    pathOutput = argv[1]
    number = argv[2]

    htmlF = open(pathToHTML, "r")
    all_content = htmlF.read()

    all_content = all_content.replace("$N_TESTS", str(number))

    htmlOutput = open(pathOutput, "w")
    htmlOutput.write(all_content)
    
    return 0
               
      
if __name__ == "__main__": 
  
    # calling main function 
    main(sys.argv[1:])