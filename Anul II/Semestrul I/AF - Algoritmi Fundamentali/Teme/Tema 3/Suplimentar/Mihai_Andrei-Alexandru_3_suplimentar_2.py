from collections import deque
import math
def bfs():
    q = deque()
    for i in range(2*n+2):
        viz[i]=0
        tata[i]=-1
    
    q.append(start)
    viz[start]=1

    while len(q):
        nodCurent=q.popleft()
        if nodCurent==dest:
            #Am ajuns la destinatie, deci s-a format un drum
            return True
        for adj in adiacenta[nodCurent]:
            if viz[adj]==0 and capacitate[nodCurent][adj]>0:
                tata[adj]=nodCurent
                viz[adj]=1
                q.append(adj)

    return False

def solutie():
    global fluxTotal
    while bfs():
        for i in range(n+1,2*n+1):
            if viz[i]==1:
                tata[dest]=i
                fluxMinim=math.inf
                nodCurent=dest
                
                #Reconstruiesc drumul pe baza vectorului de tati.
                while nodCurent!=start:
                    fluxMinim=min(fluxMinim,capacitate[tata[nodCurent]][nodCurent])
                    nodCurent=tata[nodCurent]

                if fluxMinim:
                    fluxTotal+=fluxMinim
                    nodCurent=dest
                    while nodCurent!=start:
                        capacitate[tata[nodCurent]][nodCurent] -=fluxMinim
                        capacitate[nodCurent][tata[nodCurent]] +=fluxMinim
                        nodCurent=tata[nodCurent]


# CITIRE DATE----------------------------------------
f = open("drumuri2.in")

n, m = [int(x) for x in f.readline().split()]

adiacenta = [[] for _ in range(2*n+2)]
viz = [0 for i in range(2*n+2)]
tata = [0 for i in range(2*n+2)]
capacitate = [[0 for _ in range(2*n+2)] for _ in range(2*n+2)]

for _ in range(1, m+1):

    linie = [int(x) for x in f.readline().split()]

    # formam listele de adiacenta
    adiacenta[linie[0]].append(n + linie[1])
    adiacenta[n + linie[1]].append(linie[0])

    capacitate[linie[0]][n+linie[1]] = 1  # capacitatea
f.close()

start=0
dest=2*n+1
fluxTotal=0
# ---------------------------------------------------

for i in range(1, n+1):
    capacitate[start][i] = 1
    adiacenta[start].append(i)
    capacitate[n+i][dest] =1
    adiacenta[n+i].append(dest)
    capacitate[n+i][i]=1
    adiacenta[i].append(n+i)
    adiacenta[n+i].append(i)

# print(*capacitate,sep="\n")

# for i in range(0,2*n+2):
#     print(i,adiacenta[i],end="\n")

solutie()

g=open("drumuri2.out","w")
g.write(str(n-fluxTotal))
g.close()
