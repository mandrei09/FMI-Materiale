import math
from collections import deque

# BFS------------------------------------------------


def bfs():
    q = deque()
    # REINITIALIZAM VECTORII TATA SI VIZ
    for i in range(1, n+2):
        tata[i] = 0
        viz[i] = 0

    q.append(0)  # ADAUGAM PRIMUL NOD PE COADA
    viz[0] = 1  # VIZITAM
    tata[0] = -1  # SI IL PUNEM PE PRIMUL NIVEL

    while len(q):
        nod = q.popleft()
        if nod == n+1:
            return True
        # PARCURGEM NODURILE ADIACENTE:
        for adj in adiacenta[nod]:
            if viz[adj] == 0 and capacitate[nod][adj] > 0:
                q.append(adj)
                viz[adj] = 1
                tata[adj] = nod

    return False

# ---------------------------------------------------

# VERIFICARE PRIMALITATE-----------------------------
def prim(x):
    if x < 2:
        return 0
    d = 2
    while d*d <= x:
        if x % d == 0:
            return 0
        d += 1
    return 1
# ---------------------------------------------------


# CITIRE DATE----------------------------------------
f = open("no_prime_sum.in")
n = [int(x) for x in f.readline().split()][0]
v = [int(x) for x in f.readline().split()]
f.close()
# ---------------------------------------------------
# print(n, v)
# FORMARE LISTE DE ADIACENTA-------------------------
adiacenta = [[] for _ in range(2*n+2)]
capacitate = [[0 for _ in range(2*n+2)]for _ in range(2*n+2)]
for i in range(1, len(v)):
    if v[i] % 2 == 0:
        capacitate[0][i] = 1
        adiacenta[0].append(i)
        adiacenta[i].append(0)
    else:
        capacitate[i][n+1] = 1
        adiacenta[i].append(n+1)
        adiacenta[n+1].append(i)
# ---------------------------------------------------

tata = [0 for _ in range(n+2)]
viz = [0 for _ in range(n+2)]
raspuns = []

# CONECTAM NUMERELE A CAROR SUMA ESTE UN NUMAR PRIM--
for i in range(n-1):
    for j in range(i+1, n):
        if (prim(v[i]+v[j])):
            adiacenta[i].append(j)
            adiacenta[j].append(i)
        # PLASAM NUMERELE PARE IN STANGA
        if v[i] % 2 == 0:
            capacitate[i][j] = 1
        # SI PE CELE IMPARE IN DREAPTA
        else:
            capacitate[j][i] = 1
# ---------------------------------------------------

# REZOLVARE------------------------------------------
while bfs():
    for i in range(n+1):
        if viz[i] and capacitate[i][n+1] > 0:

            # CALCULAM iP()
            flux = math.inf
            tata[n+1] = i

            nod = n+1
            while tata[nod] != -1:
                flux = min(flux, capacitate[tata[nod]][nod])
                nod = tata[nod]

            if flux == 0:
                continue

            # ACTUALIZAM FLUXURILE
            nod = n+1
            while tata[nod] != -1:
                capacitate[tata[nod]][nod] -= flux
                capacitate[nod][tata[nod]] += flux
                nod = tata[nod]
# --------------------------------------------------

# ADAUGARE SOLUTIE----------------------------------
for i in range(n):
    if (v[i] % 2 == 0 and viz[i] == 0) or (v[i] % 2 and viz[i]):
        raspuns.append(v[i])
# --------------------------------------------------

# AFISARE SOLUTIE-----------------------------------
g = open("no_prime_sum.out", "w")
g.write(str(len(raspuns)) + "\n")
for i in range(len(raspuns)):
    g.write(str(raspuns[i]) + " ")
g.close()
# --------------------------------------------------
