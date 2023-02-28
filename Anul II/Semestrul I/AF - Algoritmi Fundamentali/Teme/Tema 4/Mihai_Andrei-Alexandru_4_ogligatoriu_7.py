def dfs(nod,parinte,cost):
    #parcurgem toate nodurile adiacente nodului curent
    for adj in adiacenta[nod]:
        #daca nodul inca nu are un parinte
        if adj[0]==parinte:
            continue
        #merge pe toate lanturile existente, calculand dista maxima pentru fiecare nod de start in parte
        dfs(adj[0],nod,cost+adj[1]) 
        #maximul dintre distanta actuala si distanta altui drum
        distante[nod][1]=max(distante[nod][1],distante[adj[0]][1]+adj[1])
        distante[nod][0] += distante[adj[0]][0] + adj[1] + min(distante[adj[0]][1]+adj[1],cost)

    if distante[nod][1]<cost:
        distante[nod][0]-=distante[nod][1]
    else:
        distante[nod][0]-=cost

#se aplica DFS din ndoul de start curent
def rezolvare(nod):
    #resetam vectorul de distante
    for i in range(n+1):
        distante[i][0]=0
        distante[i][1]=0

    dfs(nod,-1,0) #initial al dolea parametru este -1 deoarece nu se cunoaste parintele 
                  #punctul de start, iar costul initial este 0
    return distante[nod][0] #timpul minim pentru punctul de start curent

#Citire date------------------------------------------------------------------------------------
f=open("riremito.in")
n=[int(x) for x in f.readline().split()][0]
adiacenta=[[] for _ in range(n+1)]
for i in range(n-1):
    #Formare liste de adiacenta
    linie=[int(z) for z in f.readline().split()]
    adiacenta[linie[0]].append((linie[1],linie[2]))
    adiacenta[linie[1]].append((linie[0],linie[2]))
print(adiacenta)
#Numarul punctelor de start si lista punctelor de start
k=[int(x) for x in f.readline().split()][0]
puncteStart=[int(x) for x in f.readline().split()]

#distante[i][0] retine distanta minima la fiecare pas pentru nodul i
#distante[i][1] retine maximul dintre distanta curenta si distanta intregului lant

distante=[[0 for _ in range(2)] for _ in range(n+1)]
f.close()

#aplicam algoritmul pentru fiecare punct de start in parte
for punct in puncteStart:
    print(rezolvare(punct))

