#CITIRE DATE-------------------------------
f=open("harta.in")
nr = [int(x) for x in f.readline().split()]
n = nr[0]
intra = [0 for i in range(n+1)]
iese = [0 for i in range(n+1)]
numarDrumuri=0
for i in range(1,n+1):
    x,y=[int(j) for j in f.readline().split()]
    iese[i]=x
    intra[i]=y
    numarDrumuri+=x
f.close()
#------------------------------------------

l=[[0 for i in range(n+1)] for j in range(n+1)]
q=[0 for i in range(n+1)]

g=open("harta.out","w")
g.write(str(numarDrumuri)+"\n")

for i in range(1,n+1):

    for j in range(n+1):
        q[j]=0

    for j in range(1,n+1):
        if intra[j] and i!=j:
            q[intra[j]]+=1
            l[intra[j]][q[intra[j]]] = j
    
    j = n

    while j and iese[i]:
        k = q[j]
        while k and iese[i]:
            ok=l[j][k]
            iese[i]-=1
            intra[ok]-=1
            g.write(str(i)+" "+str(ok)+"\n")
            k-=1
        j-=1
g.close()