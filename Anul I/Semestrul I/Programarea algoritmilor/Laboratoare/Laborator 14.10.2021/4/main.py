n=int(input("n="))
Max=0
nr=0
while n!=0:
    if n&1==1:
        nr+=1
    else:
        if nr>Max:
            Max=nr
            nr=1
    n=n>>1
if nr>Max:
    Max=nr
print(Max)

