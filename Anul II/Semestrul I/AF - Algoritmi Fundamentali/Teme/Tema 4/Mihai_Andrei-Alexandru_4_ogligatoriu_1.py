#Explicatie: 
#Se formeaza pentru fiecare masa a unui drum cate 2 liste de adiacenta, in prima se pune primul nod din muchie iar 
#in a doua, cel de-al doilea nod. Se parcurg toate masele dintr-o lista de adiacenta (acestea au fost sortate descrescator),
#astfel prima capacitate care respecta conditia pusa este rezultatul problemei) si se incearca formarea unui drum intre
#nodurile 1 si n.

#Functie pentru gasirea parintelui fiecarui nod.
def parinte(x):
    if tata[x]!=x:
        tata[x]=parinte(tata[x])
    return tata[x]

#Functie pentru gasirea unui lant intre 2 noduri
def unire(x,y):
    x=parinte(x)
    y=parinte(y)
    if pozitie[x] > pozitie[y]:
        tata[y]=x
    else:
        tata[x]=y
    if pozitie[x]==pozitie[y]:
        pozitie[y]=pozitie[y]+1

#CITIRE DATE----------------------------------------
f=open("transport2.in")
n,m=[int(x) for x in f.readline().split()]
tata=[i for i in range(n+1)]
adiacentaA={}
adiacentaB={}
pozitie=[0 for i in range(n+1)]
for i in range(m): 
    muchie=[int(x) for x in f.readline().split()]

    #formam listele de adiacenta - pentru fiecare capacitate pe care o gasim in fisier
    if muchie[2] not in adiacentaA:
        adiacentaA[muchie[2]]=[muchie[0]]
    else:
        adiacentaA[muchie[2]].append(muchie[0])
    if muchie[2] not in adiacentaB:
        adiacentaB[muchie[2]]=[muchie[1]]
    else:
        adiacentaB[muchie[2]].append(muchie[1])
f.close()

#sortam descrescator dupa capacitate
cheiA=list(adiacentaA.keys())
cheiA=sorted(cheiA,key=lambda x:-x)
sortAdiacentaA={i:adiacentaA[i] for i in cheiA}

cheiB=list(adiacentaB.keys())
cheiB=sorted(cheiB,key=lambda x:-x)
sortAdiacentaB={i:adiacentaB[i] for i in cheiB}

#---------------------------------------------------
g=open("transport2.out","w")
ok=0
print(sortAdiacentaA,sortAdiacentaB)
#parcurgem toate capacitatile
for i in sortAdiacentaA.keys():
    if ok==1:
        break
    for j in range(len(adiacentaA[i])):
        unire(adiacentaA[i][j],adiacentaB[i][j])
        if parinte(1) == parinte(n):
            g.write(str(i))
            ok=1
g.close()
        
            
