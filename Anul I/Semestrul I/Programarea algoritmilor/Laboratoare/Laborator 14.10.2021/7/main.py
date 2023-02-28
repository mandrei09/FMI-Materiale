x=int(input("x="))
k=int(input("k="))
b=1
p=0
y=0
while x!=0:
    if b!=k:
        y=y+(x&1)*(1<<p)
        p+=1
    b+=1
    x=x>>1
print(p)