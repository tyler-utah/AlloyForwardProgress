import sys
import os.path
import time

def main(argv):
    fileN = argv[0]

    f = open(fileN, "r")
    text = f.read()
    text = text.replace("\":", ":")
    text = text.replace(":\"\"", ":\"")
    f.close()

    f = open(fileN, "w+")
    f.write(text)
    f.close()
    
    return 0
               
      
if __name__ == "__main__": 
  
    # calling main function 
    main(sys.argv[1:])
