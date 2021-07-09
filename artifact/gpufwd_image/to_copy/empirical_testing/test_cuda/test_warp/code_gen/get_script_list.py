import get_cuda_inits

n = get_cuda_inits.test_names

print("TEST_NAMES = [")
for t in n:
    print("\"" + t + "\",")
print("]")
      
