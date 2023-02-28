L1=int(input())
L2=int(input())
a=L1
b=L2
while L1!=0 and L2!=0:
    if L1>L2:
        L1=L1%L2
    else:
        L2=L2%L1
if(L1!=0):
    CD=L1
else:
    CD=L2
CM=(a*b)//(CD*CD)
print(CM,L1)
