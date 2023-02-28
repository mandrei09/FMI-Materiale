def cuplare(a,b):
    cuplat[cuplat[a]]=0
    cuplat[a]=b
    cuplat[cuplat[b]]=0
    cuplat[b]=a

def dfs(nod):
    viz[nod]=nr
    for ad in adiacente[nod]:
        if viz[ad]!=nr:
            viz[ad]=nr
            if cuplat[ad] and dfs(cuplat[ad]):
                cuplare(nod,ad)
                return 1
            elif cuplat[ad]==0:
                cuplare(nod,ad)
                return 1
    return 0
    
# Datele de intrare

f = open("cuplaj.in")
n, m, k = [int(x) for x in f.readline().split()]

adiacente=[[] for i in range (n+m+1)]

for i in range(k):
    x,y=[int(j) for j in f.readline().split()]
    adiacente[x].append(y+n)
    adiacente[y+n].append(x)

f.close()

##################

ok=1
nr=rezultat=0
cuplat=[0 for i in range (n+m+1)]
viz=[0 for i in range (n+m+1)]

while ok:
    ok=0
    nr+=1
    for i in range(1,n+m+1):
        if cuplat[i]==0 and viz[i]!=nr:
            ok=ok|dfs(i)

for i in range(1,n+1):
    if cuplat[i]:
        rezultat+=1

g = open("cuplaj.out","w")

g.write(str(rezultat))
g.write('\n')

for i in range(1,n+1):
    if cuplat[i]:
        g.write(str(i))
        g.write(" ")
        g.write(str(cuplat[i]-n))
        g.write('\n')
g.close()
