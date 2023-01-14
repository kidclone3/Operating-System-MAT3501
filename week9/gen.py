import random
for i in range(50):
    cProcess = random.randint(ord('a'), ord('z'))
    nPages = random.randint(-5, 11)
    print(chr(cProcess), nPages)
print('!')