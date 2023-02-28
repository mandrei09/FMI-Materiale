d={}
f=open("puncte.in")
for linie in f:
    ls= linie.split(maxsplit=2)
    x=int(ls[0])
    y=int(ls[1])
    eticheta=ls[2].rstrip("\n")
    d[(x,y)] = eticheta
f.close()
print(d)

f=open("interogari.in")
for linie in f:
    x,y,operatie=[int(x) for x in linie.split()]
    if operatie==1:
        if (x,y) in d:
            eticheta=d[(x,y)]
        else:
            eticheta="nu exista"
        print(f"{(x,y)} {eticheta}")
    else:
         if (x,y) in d:
             del(d[(x,y)])
f.close()
print("Puncte ramase")
for punct in d:
     print(punct,":",d[punct],sep="")
