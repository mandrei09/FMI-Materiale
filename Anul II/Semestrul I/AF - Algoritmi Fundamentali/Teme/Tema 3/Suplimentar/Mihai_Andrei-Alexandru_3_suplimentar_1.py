# gaseste cel mai scurt drum dintr-un nod in toate celelalte noduri
# spre deosebire de dijktra, algoritmu functioneaza si pentru muchii cu costuri negative
from collections import deque
import math


def BellmanFord():

    inCoada = [False for _ in range(n+1)]
    coada = deque()

    # Initializam toate distantele cu infinit
    for i in range (n+1):
        dBellman[i]=math.inf

    coada.append(s)
    inCoada[s] = True
    dBellman[s] = 0  # in afara de distanta pentru nodul de start

    # Se vor realiza n-1 interatii pentru toate nodurile, unde n este numarul de noduri
    while (len(coada)):
        nod = coada.popleft()
        inCoada[nod] = False
        for adj in adiacenta[nod]:
            if capacitate[nod][adj]:
                # Comparam distanta nodului unde dorim sa ajungem
                # cu distanta nodului curent + capacitatea acestuia
                if dBellman[adj] > dBellman[nod] + costuri[nod][adj]:
                    dBellman[adj] = dBellman[nod] + costuri[nod][adj]
                    if inCoada[adj] == 0:
                        coada.append(adj)
                        inCoada[adj] = True


def Dijkstra():

    global minCost

    # Toate distantele = inf in afara de cele din nodul de start S
    for i in range(1,n+1):
        dPlus[i]=math.inf

    dPlus[s] = 0
    dReal[s] = 0

    pCoada.append((0, s))

    while (len(pCoada)):

        front = pCoada.popleft()
        nod = front[1]

        if dPlus[nod] == front[0]:
            for adj in adiacenta[nod]:
                if capacitate[nod][adj] > 0:
                    if dPlus[adj] > dPlus[nod] + costuri[nod][adj] + dBellman[nod] - dBellman[adj]:
                        dPlus[adj] = dPlus[nod] + costuri[nod][adj] + \
                            dBellman[nod] - dBellman[adj]
                        pCoada.append((dPlus[adj], adj))
                        dReal[adj] = dReal[nod] + costuri[nod][adj]
                        tata[adj] = nod

    for i in range(1, n+1):
        dBellman[i] = dReal[i]

    # Daca nu se poate face drum
    if dPlus[d] == math.inf:
        return False

    # aflam capacitatea minima iP
    flux = math.inf

    nod = d
    while nod != s:
        flux = min(flux, capacitate[tata[nod]][nod])
        nod = tata[nod]

    # actualizam graful
    nod = d
    while nod != s:
        capacitate[tata[nod]][nod] -= flux
        capacitate[nod][tata[nod]] += flux
        nod = tata[nod]

    # incrementam costul minim
    minCost = minCost + flux * dReal[d]
    return True


# CITIRE DATE----------------------------------------
f = open("fmcm.in")

n, m, s, d = [int(x) for x in f.readline().split()]

adiacenta = [[] for i in range(n+1)]
capacitate = [[0 for _ in range(n+1)] for _ in range(n+1)]
costuri = [[0 for _ in range(n+1)] for _ in range(n+1)]

for _ in range(1, m+1):

    linie = [int(x) for x in f.readline().split()]

    # formam listele de adiacenta
    adiacenta[linie[0]].append(linie[1])
    adiacenta[linie[1]].append(linie[0])

    capacitate[linie[0]][linie[1]] = linie[2]  # capacitatea
    costuri[linie[0]][linie[1]] = linie[3]  # costul
    costuri[linie[1]][linie[0]] = -linie[3]

f.close()
# ---------------------------------------------------

minCost = 0
tata = [0 for _ in range(n+1)]
dBellman = [math.inf for _ in range(n+1)]
dReal = [math.inf for _ in range(n+1)]
dPlus = [math.inf for _ in range(n+1)]
pCoada = deque()

BellmanFord()

rezultat = Dijkstra()
while (rezultat == False):
    rezultat = Dijkstra()

print(minCost)
