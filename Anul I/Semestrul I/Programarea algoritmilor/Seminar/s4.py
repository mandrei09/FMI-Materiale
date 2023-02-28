d={}
f=open("cuvinte.txt")
for linie in f:
   for cuvant in linie.split():
       litere_cuv=frozenset(cuvant)
       if litere_cuv in d:
           d[litere_cuv].append(cuvant)
       else:
            d[litere_cuv]=[cuvant]
f.close()
def cheie_sortare(x):
    return len,x
for multime in sorted(d,key=len,reverse=True):
    print(*sorted(d[multime],key=cheie_sortare))

