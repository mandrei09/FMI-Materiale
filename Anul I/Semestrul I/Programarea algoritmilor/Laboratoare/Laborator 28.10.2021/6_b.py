p=input()
nr=1
l=len(p)
for i in range(0,l-1):
    if p[i]==p[i+1]:
        nr+=1
    else:
        print(nr,p[i],sep="",end="")
        nr=1
if p[i]==p[i+1]:
    print(nr,p[i],sep="",end="")
else:
    print(1,p[l-1],sep="",end="")