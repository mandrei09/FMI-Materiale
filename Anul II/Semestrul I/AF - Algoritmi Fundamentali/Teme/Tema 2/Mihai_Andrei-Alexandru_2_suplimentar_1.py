# Ne vom folosi de algoritmul lui Prim pentru a gasi costul minim al arborelui ce va contine
# toate punctele de pe grafic. Initializam graful, adaugand lungimea fiecarei muchii
# dupa formula data.
# In cadrul algoritmului, ne vom folosi de o functie care returneaza nodul minim care nu a fost vizitat inca
# Initial atribuim tuturor cheilor valoarea infinit. Alegem nodul minim nevizitat si il adaugam la APM, 
# urmand ca in final sa calculam costul total, fiind suma elementelor de tipul adiacenta[i][tata[i]].

import sys

def printMatrix(adiacenta):
    for i in range(len(adiacenta)):
        for j in range(len(adiacenta[i])):
            print(adiacenta[i][j],end=" ")
        print()

def distanta(xi,xj,yi,yj):
    return abs(xi-xj)+abs(yi-yj)

points = [[0,0],[1,1],[1,0],[-1,1]]

numarNoduri=len(points)

adiacenta=[[0 for i in range(numarNoduri)] for j in range(numarNoduri) ]

for i in range(numarNoduri):
    for j in range(numarNoduri):
        adiacenta[i][j]=distanta(points[i][0],points[j][0],points[i][1],points[j][1])

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
    cheie = [sys.maxsize]*numarNoduri
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

        for v in range(numarNoduri):
            if adiacenta[u][v] > 0 and rezultat[v] == 0 and cheie[v] > adiacenta[u][v]:
                cheie[v] = adiacenta[u][v]
                tata[v] = u

    costTotal=0
    for i in range(1, numarNoduri):
        costTotal+=adiacenta[i][tata[i]]
    return costTotal

print(Prim())