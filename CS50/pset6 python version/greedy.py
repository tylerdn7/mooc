import cs50
import random


while True:
    print("O hai! How much change is owed?")
    n = cs50.get_float()
    if n > 0:
        break
n = round(n,5) * 100
n = int(n)
count = 0
while n >= 25:
    n-=25
    count+= 1
while n >= 10:
    n-=10
    count+= 1
while n >= 5:
    n-=5
    count+= 1
while n >= 1:
    n-=1
    count+= 1

print(count)