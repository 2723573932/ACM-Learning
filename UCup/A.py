from random import randint
from math import gcd
lst=input().split(' ')
s=int(lst[0])
t=int(lst[1])
x=0
if gcd(s,t)==1:
    print("1\n{}".format(s))
elif s%2==1 and t%2==0:
    while(1):
        x=randint(1,int(s/2))
        if(x%2==0 and x/2%2==1):
            if(gcd(int(x/2),t)==1 and gcd(s-x,t)==1):
                print("3\n{} {} {}".format(int(x/2),int(x/2),s-x))
                break
else :
    while(True):
        x=randint(1,int(s/2))
        if(gcd(x,t)==1 and gcd(s-x,t)==1):
            print("2\n{} {}".format(x,s-x))
            break
        
