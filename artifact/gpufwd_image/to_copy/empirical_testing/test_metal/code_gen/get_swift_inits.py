import get_osx_inits

n = get_osx_inits.test_names

print("import Foundation")
print("let test_names: [String] = [")
for t in n:
    print("\""+t+"\",")
print("]")

      


    
