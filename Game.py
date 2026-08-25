import random as r
a=r.randint(1,6)
g=int(input("Enter your guess:"))
if(g==a):
    print("🏆You Won🏆")
else:
    print(a)