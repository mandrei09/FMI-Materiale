#Se initializeaza vectorul de tati ( initial, fiecare nod se are pe sine ca parinte ),
#apoi sortam muchiile in functie de cost, pentru a putea determina APM cu ajutorul
#algoritmului lui Kruskal. Vom citi celelalte drumuri, le adaugam la apm si calculam 
#costul minim din nou, pentru fiecare muchie. In final, rezultatul este dat de 
#formula costMinim1-costMinim2-1

import sys  # PENTRU A FOLOSI INT_MAX

def printMatrix(matrice):
    for i in range(len(matrice)):
        for j in range(len(matrice[i])):
            print(matrice[i][j],end=" ")
        print()

#Functie care intoarce tatal nodului
def tata(x):
    if t[x]==x:
        return x
    t[x]=tata(t[x])
    return t[x]

def Union(x,y):
    t[tata(x)]=tata(y)

def InitializareVectorTati(t):
    for i in range(1,numarNoduri+1):
        t[i]=i

# CITIRE DATE
f = open("apm2.in")

numarNoduri, numarMuchii , q = [int(x) for x in f.readline().split()]

muchii = []
for i in range(numarMuchii):
    muchii.append([int(x) for x in f.readline().split()])

t=[0 for i in range(numarNoduri+1)]
InitializareVectorTati(t)

#sortam muchiile in functie de cost
muchii=sorted(muchii,key=lambda x:x[2])

costMinim1=0 #cost minim initial

solutie=[]

#aflam costul minim al APM cu kruskal
for i in range(numarMuchii):
    if tata(muchii[i][0]) != tata(muchii[i][1]):
        Union(muchii[i][0],muchii[i][1])
        costMinim1+=muchii[i][2]
        solutie.append(muchii[i])

#citim celelalte drumuri
g=open("apm2.out","w")
while q:
    costMinim2=0
    x,y=[int(z) for z in f.readline().split()]
    InitializareVectorTati(t)
    Union(x,y)
    for i in range(len(solutie)):
        if tata(solutie[i][0]) != tata(solutie[i][1]):
            Union(solutie[i][0],solutie[i][1])
            costMinim2+=solutie[i][2]
    g.write(str(costMinim1-costMinim2-1)+'\n')
    q-=1
f.close()
g.close()
