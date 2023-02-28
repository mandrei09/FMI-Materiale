n=int(input("n="))
nr=0
while n!=0:
    if n&1==1:
        nr+=1
    n=n>>1
print(nr)
