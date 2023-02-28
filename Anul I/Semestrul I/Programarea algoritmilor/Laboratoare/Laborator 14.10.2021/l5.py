import math
a=int(input("a="))
b=int(input("b="))
c=int(input("c="))
delt=b*b-4*a*c
if delt<0:
    print("Nu exista")
else:
    x1=(-b+math.sqrt(delt))//2*a
    x2=(-b-math.sqrt(delt))//2*a
    if x1==x2:
        print("Radacina dubla:",x1)
    else:
        print("Radacinile sunt:",x1,"si",x2)