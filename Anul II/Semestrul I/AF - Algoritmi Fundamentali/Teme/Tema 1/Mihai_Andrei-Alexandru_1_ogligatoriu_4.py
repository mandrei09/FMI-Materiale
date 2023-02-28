#Principiu problema
#   -parcurgem graful in DFS si adaugam intr-o stiva capatul nodului dintr-un circuit
#   -se creeaza un graf transpus, fiecare muchie se inverseaza (0->1 devine 1->0 si tot asa)
#   -se merge pe elementele stivei si pentru cele nevizitate se apeleaza din nou DFS
#   -astfel se afiseaza componentele tare conexe.

file = open("ctc.in",'r')
numarNoduri, numarMuchii = (int(valoare) for valoare in file.readline().split())
adiacenteT = [[] for index in range(numarNoduri+1)]
adiacente = [[] for index in range(numarNoduri+1)]

for linie in file.readlines():
    m1 = int(linie.split()[0])
    m2 = int(linie.split()[1])
    adiacente[m1].append(m2)
file.close()

# parcurgem in adancime
def dfsStack(nod,stack):
    vizitate[nod] = 1
    for nodAdiacent in adiacente[nod]:
        if vizitate[nodAdiacent] == 0:
            dfsStack(nodAdiacent,stack)
    stack=stack.append(nod)

def dfs(nod):
    vizitate[nod] = 1
    print(nod,end=" ")
    for nodAdiacent in adiacenteT[nod]:
        if vizitate[nodAdiacent] == 0:
            dfs(nodAdiacent)

def GrafTranspus(adiacenteT):
    for i in range(numarNoduri):
        for adiacent in adiacente[i]:
            adiacenteT[adiacent].append(i)

def AfisareComponeteTareConexe():
    stack=[]
    dfsStack(0,stack)
    GrafTranspus(adiacenteT)
    for i in range(numarNoduri+1):
        vizitate[i]=0
    while stack:
        aux=stack.pop()
        if vizitate[aux]==0:
            dfs(aux)
            print("")

vizitate = [0 for index in range(numarNoduri+1)]

AfisareComponeteTareConexe()


