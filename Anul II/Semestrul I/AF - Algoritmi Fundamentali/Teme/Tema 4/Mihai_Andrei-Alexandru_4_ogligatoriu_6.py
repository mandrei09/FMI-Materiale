#Acesta rezolvare se bazeaza pe algoritmul lui Dijkstra, care calculeaza
#cel mai scurt drum intre 2 noduri ale unui graf, in cazul nostru va trebui
#sa gasim cel mai scurt drum de la un nod inapoi in acelasi nod, trecand 
#o singura data printr-o muchie. Algornitmul se apeleaza pentru fiecare nod 
#in parte, si se incearca gasirea unui lant in modul descris mai sus.
#Se incepe din nodul curent, apoi se parcurg toate nodurile adiacente
#si se merge pe muchiile unde suma distantelor este minima.

import math
from collections import deque
def dijkstra(nod):
    #initial, setam toate duratele = inf
    durata=[math.inf for _ in range(n+1)]
    cat[nod]=0 
    tata[nod]=0 #initial tatal nodului este 0
    durata[nod]=0 #in afara de durata pentru nodul curent
    q = deque()
    q.append((0,nod))
    while(len(q)):
        drt,y=q.popleft() #scoatem un element din coada
        if drt!=durata[y]:
            continue
        for adiacent in adiacenta[y]: 
            #daca durata nodului curent + cea a nodului adiacent < durata adiacentului
            if durata[y]+adiacent[1]<durata[adiacent[0]]:
                #actualizam distanta
                durata[adiacent[0]] = durata[y] + adiacent[1]
                #punem nodul respectiv in coada 
                q.append((durata[adiacent[0]],adiacent[0]))
                #modificam parintele nodului
                tata[adiacent[0]]=y
                #daca am ajuns inapoi in nodul de inceput
                if y==nod:
                    cat[adiacent[0]]=adiacent[0]
                else:
                    cat[adiacent[0]]=cat[y]
    for i in range(1,n+1):
        for adj in adiacenta   [i]:
            if adj[0]>i:
                #daca exisa lant
                if tata[adj[0]]!=i and tata[i]!=adj[0] and cat[adj[0]]!=cat[i]:
                    #modificam distanta minima
                    cMin[nod]=min(cMin[nod],durata[adj[0]]+durata[i]+adj[1])

#------------------------------------------------------------------------
f=open("dbz.in")
n,m=[int(x) for x in f.readline().split()]
cMin=[math.inf for _ in range(n+1)] #retine durata minima pentru fiecare nod in parte. 
cat=[0 for _ in range(n+1)]
tata=[0 for _ in range(n+1)] #vector de parinti 
durata=[0 for _ in range(n+1)] #retine duratele partiale pentru fiecar nod
adiacenta=[[] for _ in range(n+1)] #listele de adiacenta
#formam listele de adiacenta
for i in range(m):
    x,y,c=[int(x) for x in f.readline().split()]
    adiacenta[x].append((y,c))
    adiacenta[y].append((x,c))

#calculam durata minima pentru fiecare nod prin alg lui dijkstra
for i in range(1,n+1):
    dijkstra(i)

#daca dupa executia programului durata inca este inf, nu exista un drum corespunzator de la planeta i inapoi
for i in range(1,n+1):
    if cMin[i]==math.inf:
        print(-1,end=" ")
    else:
        print(cMin[i],end=" ")    
f.close()
#------------------------------------------------------------------------