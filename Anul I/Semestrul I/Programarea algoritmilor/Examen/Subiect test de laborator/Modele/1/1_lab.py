def citire_matrice(nume_fisier):

    matrice=[]
    nr=0
    i=0
    f=open(nume_fisier)
    for linie in f:

        matrice.append([int(numar) for numar in linie.split()])
        nr=len(matrice[0])
        if nr!=len(matrice[i]):
            return None
        i+=1

    return matrice
    f.close()

def prima(numar):

    while(numar>9):
        numar//=10
    return numar

def multimi(matrice, *indici):

    negative1 = {x for x in matrice[indici[0]] if x<0}
    pozitive1= {x for x in matrice[indici[0]] if x>0 and x%10==prima(x)}
    
    for i in indici:

        negative2={x for x in matrice[i] if x<0}
        negative1=negative1.intersection(negative1,negative2)
        pozitive2= {x for x in matrice[i] if x>0 and x%10==prima(x)}
        pozitive1=pozitive1.union(pozitive1,pozitive2)

    return negative1,pozitive1

    
M=citire_matrice("matrice.txt")

lungime=len(M[0])
tablou=sorted(multimi(M,lungime-1,lungime-2,lungime-3)[1])
print(*tablou)

mul=multimi(M,0,lungime-1)[0]
nr=0
for i in mul:
    nr+=1
print(nr)