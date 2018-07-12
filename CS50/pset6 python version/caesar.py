import cs50
import sys

k = int(sys.argv[1])
s = cs50.get_string()


for i in s:
    if i.isalpha():
        if i.isupper():
            print(chr((((ord(i) - 65) + k) % 26) + 65),end="")
        elif i.islower():
            print(chr((((ord(i) - 97) + k) % 26) + 97),end="")
    else:
        print(i,end="")
print()