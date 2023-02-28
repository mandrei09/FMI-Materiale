# Problema se reduce la algoritmul lui Prim, pe care il vom apela mai intai initial, iar apoi, 
# pe rand, pentru fiecare "muchie" care se mai adauga.
# Algoritmul continua ca in problema minCostConnectPoints doar ca algoritmul se mai aplica si pentru muchiile adaugate ulterior. 
# Dupa parcurgerea initiala afisam totalul si vom face prim() inca de k ori, afisand costul total 
# minim nou dupa fiecare modificare.

import math
import sys  # PENTRU A FOLOSI INT_MAX

def printMatrix(matrice):
    for i in range(len(matrice)):
        for j in range(len(matrice[i])):
            print(matrice[i][j],end=" ")
        print()

# CITIRE DATE
f = open("online.in")

numarNoduri, numarMuchii = [int(x) for x in f.readline().split()]

muchii = []
for i in range(numarMuchii):
    muchii.append([int(x) for x in f.readline().split()])

# Constructie matrice de adiacenta
matrice = [[0 for i in range(numarNoduri+1)]for j in range(numarNoduri+1)]
for muchie in muchii:
    matrice[muchie[0]][muchie[1]]=matrice[muchie[1]][muchie[0]]=muchie[2]


# Functie care alege nodul de distanta minima dintre cele care nu fost deja selectate.

def nodMinim(cheie, rezultat):

    index=0

    Min = sys.maxsize

    for nod in range(1,numarNoduri+1):
        if cheie[nod] < Min and rezultat[nod] == 0:
            Min = cheie[nod]
            index = nod

    return index


# Functie pentru a construi si afisa arborele partial de cost minim. (conform algoritmului lui Prim)
def Prim():

    # initial atribuim tuturor cheilor valoarea infinit
    cheie = [sys.maxsize]*(numarNoduri+1)
    tata = [0 for x in range(numarNoduri+1)]
    rezultat = [0 for x in range(numarNoduri+1)]

    cheie[1] = 0  # parcurgem nodurile in ordine crescatoare, deci pornim din 0
    # de asemenea, ii schimbam si cheia.

    tata[1] = -1  # primul nod este radacina

    for nod in range(numarNoduri+1):
        # Alegem nodul de distanta minima dintre cele care nu fost deja selectate
        u = nodMinim(cheie, rezultat)
        # Adaugam nodul la rezultat
        rezultat[u] = 1

        for v in range(numarNoduri+1):
            if matrice[u][v] > 0 and rezultat[v] == 0 and cheie[v] > matrice[u][v]:
                cheie[v] = matrice[u][v]
                tata[v] = u

    costTotal=0
    for i in range(2, numarNoduri+1):
        costTotal+=matrice[i][tata[i]]
    return costTotal

g=open("online.out","w")
#Aplicam algoritmul lui prim pentru a obtine drumul de cost minim initial
g.write(str(Prim()))

k=f.readline()
k=int(k)

#Aplicam algoritmul lui Prim si pentru muchiile care se mai adauga
for i in range(k):
    muchieNoua=[int(x) for x in f.readline().split()]
    matrice[muchieNoua[0]][muchieNoua[1]]=matrice[muchieNoua[1]][muchieNoua[0]]=muchieNoua[2]
    g.write(str(Prim()))

f.close()
g.close()