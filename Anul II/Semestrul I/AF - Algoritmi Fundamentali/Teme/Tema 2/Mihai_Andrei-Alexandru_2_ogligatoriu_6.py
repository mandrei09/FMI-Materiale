#Acest algoritm foloseste DFS pentru a gasi lantul de cost maxim.
# Utilizam vectorul dp, unde dp[i] retine suma maxima a unui lant, pornind din i
# Pentru fiecare nod nevizitat, traversam muchii grafului (prin DFS) si actualizam 
# vectorul de distante daca gasim o valoare mai mare decat cea curenta.

def dfs(nodCurent,precedent):
    global maxCost,suma
    #vizitam nodul
    vizitat[nodCurent]=1
    #memoram costul initial al nodului
    dp[nodCurent]=costuri[nodCurent]
    ok=1 #initial presupunem ca muchia nu va trebui traversata
    costCurent=costuri[nodCurent]
    #parcurgem nodurile adiacente nodului curent
    for adiacent in graf[nodCurent]:
        if vizitat[adiacent] and adiacent!=precedent:
            ok=0
        else:
            if not vizitat[adiacent]:
                ok &=dfs(adiacent,nodCurent)
        costCurent=max(costCurent,costuri[nodCurent]+dp[adiacent])
    dp[nodCurent] = costCurent
    #verificam ca muchia sa nu faca parte dintr-un ciclu
    if ok==0:
        suma+=costuri[nodCurent]
    else:
        maxCost=max(maxCost,dp[nodCurent])
    return ok 

#citire date
f=open("easygraph.in")
t=f.readline()
t=int(t)
n,m=[int (x) for x in f.readline().split()]
costuri=[int (x) for x in f.readline().split()]
costuri.insert(0,None)
muchii=[]
for i in range(m):
    muchii.append([int (x) for x in f.readline().split()])
f.close()

#liste de adiacenta
graf=[[] for i in range(n+1)]
for muchie in muchii:
    graf[muchie[0]].append(muchie[1])

vizitat=[0 for i in range(n+1)] #retine daca un nod a fost sau nu vizitat
dp=[0 for i in range(n+1)] #retine costurile lanturilor
maxCost = 0 #memoram costul maxim al unui nod
suma = 0 #memoram suma costurilor rezultata

#apelam dfs din primul nod, precedentul fiind -1 pentru  ca nu exista un precedent
dfs(1,-1)
print(maxCost+suma)
