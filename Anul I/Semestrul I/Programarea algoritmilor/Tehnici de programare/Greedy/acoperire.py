f=open("acoperire.in")
a,b=(int(x) for x in f.readline().split())
n=int(f.readline().rstrip("\n"))
intervale=[]
for linie in f:
    split=linie.split()
    interval=(int(split[0]),int(split[1]),int(split[1])-a)
    intervale.append(interval)
f.close()

intervale=sorted(intervale)

print(intervale)

len=len(intervale)
len-=1
interval=0
f=open("acoperire.out","w")
while interval<=len:
    if intervale[interval][1]>a and intervale[interval][0]<a:
        break
    interval+=1

if interval>=len:
    f.write("-1")
else:
    solutie=[intervale[interval]]
    cautare=intervale[interval][1]

    inceput=intervale[interval][0]
    nr=1
    interval+=1
    while interval<=len:
        if intervale[interval][1]>cautare:
            nr+=1
            cautare=intervale[interval][1]
            solutie.append(intervale[interval])
            final=intervale[interval][1]
        interval+=1

    if inceput<=a and b<=final:
        f.write(str(nr))
        print(solutie)
    else:
        f.write("-1")
f.close()
