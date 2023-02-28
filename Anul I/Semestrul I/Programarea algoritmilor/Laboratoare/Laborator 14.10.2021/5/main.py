x=int(input("x="))
y=int(input("y="))
x=x^y ; nr=0
while x:
    if x&1==1:
        nr+=1
    x=x>>1
print(nr)
