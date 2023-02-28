#Aceasta problema este un exemplu diret al algoritmului lui Prim, care
#determina un arbore partial de post minim. Se incepe dintr-un nod
#la intamplare si se aduaga la subgraf muchia cu costul minim care nu apartine de graf.
# Acesti pasi se repeta pana cand formam un arbore partial de cost minim.
# Se creeaza o functie pentru a calcula distanta euclidiana intre 2 puncte.
# Distantele dintre puncte de retin in matricea "matrice", unde matrice[i][j] = distanta dintre
# nodurile i si j. Apoi, parcurgand fiecare bloc, dorim sa calculam distanta minima care trebuie adaugata
# la distanta totala, pentru a se conecta cat mai eficent la retea, dupa care 'vizitam' blocul 
# respectiv, cu semnificatia ca acesta a fost deja adaugat cu cost minim in retea. 

import math
import sys  # PENTRU A FOLOSI INT_MAX

#Functie auxiliara pentru afisare a unei matrice
def printMatrix(matrice):
    for i in range(len(matrice)):
        for j in range(len(matrice[i])):
            print(matrice[i][j],end=" ")
        print()

#Distanta dintre 2 puncte
def calculDistanta(x1, x2, y1, y2):
    return math.sqrt((x1-y1)**2+(x2-y2)**2)

# CITIRE DATE
f = open("retea2.in")
numarCentrale, numarBlocuri = [int(x) for x in f.readline().split()]
numarNoduri = numarCentrale+numarBlocuri
centraleBlocuri = []
for i in range(numarCentrale):
    centraleBlocuri.append([int(x) for x in f.readline().split()])
for i in range(numarBlocuri):
    centraleBlocuri.append([int(x) for x in f.readline().split()])
f.close()
#-------------------------------------------------

# Constructie matrice de adiacenta care retine distantele dintre centrale si blocuri
matrice = [[0 for i in range(numarNoduri)]for j in range(numarNoduri)]
for i in range(len(centraleBlocuri)):
    for j in range(len(centraleBlocuri)):
        matrice[i][j] = calculDistanta(
            centraleBlocuri[i][0], centraleBlocuri[j][0], centraleBlocuri[i][1], centraleBlocuri[j][1])

# Functie care alege nodul de distanta minima dintre cele care nu fost deja selectate.
def nodMinim(cheie, rezultat):

    index=0

    Min = sys.maxsize

    for nod in range(numarNoduri):
        if cheie[nod] < Min and rezultat[nod] == 0:
            Min = cheie[nod]
            index = nod

    return index

# Functie pentru a construi si afisa arborele partial de cost minim. (conform algoritmului lui Prim)
def Prim():

    # initial atribuim tuturor cheilor valoarea infinit
    cheie = [sys.maxsize for _ in range(numarNoduri)]
    tata = [0 for x in range(numarNoduri)]
    rezultat = [0 for x in range(numarNoduri)]

    cheie[0] = 0  # parcurgem nodurile in ordine crescatoare, deci pornim din 0
    # de asemenea, ii schimbam si cheia.

    tata[0] = -1  # primul nod este radacina

    for nod in range(numarNoduri):
        # Alegem nodul de distanta minima dintre cele care nu fost deja selectate
        u = nodMinim(cheie, rezultat)
        # Adaugam nodul la rezultat
        rezultat[u] = 1
        # Pentru nodurile adiacente, modifica cheia pentru cele care au o cheie > distanta memorata in matrice
        for v in range(numarNoduri):
            if matrice[u][v] > 0 and rezultat[v] == 0 and cheie[v] > matrice[u][v]:
                cheie[v] = matrice[u][v]
                tata[v] = u

    costTotal=0.0
    for i in range(1, numarNoduri):
        costTotal+=matrice[i][tata[i]]
    return costTotal

g=open("retea2.out","w")
g.write(str(Prim()))
g.close()

