import cs50

while True:
    print("height: ",end="")
    n = cs50.get_int()
    if n > 0 or n < 23:
        break
for i in range(n+1):
    for j in range(n-i):
        print(" ",end="")
    print("#" * (i+2),end="")
    print()
        