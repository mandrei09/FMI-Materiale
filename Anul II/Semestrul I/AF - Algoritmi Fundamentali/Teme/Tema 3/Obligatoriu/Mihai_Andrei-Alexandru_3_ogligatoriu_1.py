from collections import deque

# BFS pentru a determina un drum de la s la t
def BF(s, n, adiacent, rezid, tata, viz):

    #resetam vectorul de tati si cel de vizitare
    for i in range(n+1):
        viz[i] = 0
        tata[i] = 0

    #ne formam o coada pentru bfs si adaugam nodul curent pe ea
    coada = deque()
    coada.append(s)
    viz[s] = 1

    #operam cat timp mai exista elemente pe coada
    while len(coada) > 0:
        nodCurent = coada.popleft()
        for nodAdiacent in adiacent[nodCurent]:
            if viz[nodAdiacent] == 0 and rezid[nodCurent][nodAdiacent] > 0:
                tata[nodAdiacent] = nodCurent
                if nodAdiacent == n:
                    return 1
                coada.append(nodAdiacent)
                viz[nodAdiacent] = 1
    return 0

# Datele de intrare

f = open("maxflow.in")
n, m = [int(x) for x in f.readline().split()]
muchii = [[int(x) for x in f.readline().split()] for i in range(m)]
f.close()

##################

cost = [[0 for i in range(n+1)] for j in range(n+1)]
rezid = [[0 for i in range(n+1)] for j in range(n+1)]
adiacent = [[] for i in range(n+1)]
adiacentRezid = [[] for i in range(n+1)]
c_max = -1

for muchie in muchii:

    adiacent[muchie[0]].append(muchie[1])

    adiacentRezid[muchie[0]].append(muchie[1])
    adiacentRezid[muchie[1]].append(muchie[0])

    rezid[muchie[0]][muchie[1]] = muchie[2]
    rezid[muchie[1]][muchie[0]] = 0

    if muchie[2] > c_max:
        c_max = muchie[2]

tata =[0 for i in range(n+1)]
viz = [0 for i in range(n+1)]
fmax = 0
s = 1  # sursa
t = n  # destinatia

while BF(s, n, adiacentRezid, rezid, tata, viz):
    
    # capacitatea minima pe un drum
    capacitateMinima = c_max

    t = n

    while t != s:
        if capacitateMinima > rezid[tata[t]][t]:
            capacitateMinima = rezid[tata[t]][t]
        t = tata[t]

    t = n
    while t != s:
        rezid[tata[t]][t] -= capacitateMinima
        rezid[t][tata[t]] += capacitateMinima
        t = tata[t]

    fmax += capacitateMinima
    # print(fmax)s

g = open("maxflow.out", "w")
g.write(str(fmax))
g.close()
