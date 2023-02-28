#Algoritmul utilizeaza BFS pentru a verifica daca exista un drum intre
#2 noduri din graf. Graful este reprezenat in memorie printr-o matrice  
#de adiacenta. Functia src verifica existenta elementului x intr-o lista de liste.
#BFS este apelat pentru fiecare querry. Se reseteaza vectorul de vizitare
#coada si vectorul de distante. Algoritmul itereaza printre adiacentii nodului curent,
#adaugand in vectorul distante acele distante > decat cea curenta. Daca 
#am ajuns in nodul final, returnam numarul de elemente ale listei, apoi subprogramul
#se apeleaza pentru adiacentii nevizitati ai nodului.

def src(liste,x):
    for lista in liste:
        index=0
        if lista[0]==x:
            return index
        index+=1
    return -1

def initializareGraf():
    graf=[[] for i in range(n)]

    adiacenta=[[0 for i in range(n)] for j in range(n)]

    for muchie in edgeList:
        if adiacenta[muchie[0]][muchie[1]]==1 or adiacenta[muchie[1]][muchie[0]]==1:
            graf[muchie[0]][src(graf[muchie[0]],muchie[1])].append(muchie[2])
            graf[muchie[1]][src(graf[muchie[1]],muchie[0])].append(muchie[2])
        else:
            graf[muchie[0]].append([muchie[1],muchie[2]])
            graf[muchie[1]].append([muchie[0],muchie[2]])
            adiacenta[muchie[0]][muchie[1]]=adiacenta[muchie[1]][muchie[0]]=1
    return graf

def BFS(v,u,dist):
    vizitat=[0 for i in range(n)]
    coada=[]

    distante=[]

    coada.append(v)
    vizitat[v]=1
    while coada:
        nod=coada.pop(0)

        for muchie in graf[nod]:
            for distanta in muchie[1:]:
                if distanta>=dist:
                    distante.append(distanta)

        if nod==u: 
            return True,len(distante)
        for adiacent in graf[nod]:
            if vizitat[adiacent[0]]==0:
                coada.append(adiacent[0])
                vizitat[adiacent[0]]=1

    return False,len(distante)
        
def rezolvare():
    rezultat=[[] for i in range(len(queries))]
    index=0
    for elem in queries:
        if BFS(elem[0],elem[1],elem[2])[0]==True and BFS(elem[0],elem[1],elem[2])[1]==0:
            rezultat[index]=True
        else:
            rezultat[index]=False
        index+=1
    return rezultat

n=3
edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]]
queries = [[0,1,2],[0,2,5]]
graf=initializareGraf()
print(rezolvare())

