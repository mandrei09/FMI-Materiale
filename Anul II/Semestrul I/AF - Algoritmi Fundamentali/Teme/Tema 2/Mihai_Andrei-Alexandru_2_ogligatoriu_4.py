# Vom folosi un bfs pentru a parcurge drumurile prin muchiile dorite, si vom intializa probabilitatea
# nodului de start cu 1 pentru a fi neutra la inmultire. Daca gasim un nod adiacent cu o probabilitate mai 
# buna decat cea a nodului curent, il adaugam in coada si apelam din nou programul pentru
# adiacent si produsul probabilitatilor celor 2 noduri.

from collections import deque,defaultdict

edges = [[0,1],[1,2],[0,2]]
probability = [0.5,0.5,0.2]
start = 0
end = 2

#Formam listele de adiacenta pentru fiecare nod
#   La lista nodului i adaugam tuplul (adj,prob)

graf=defaultdict(list)

for i in range(len(edges)):
    graf[edges[i][0]].append((edges[i][1],probability[i]))
    graf[edges[i][1]].append((edges[i][0],probability[i]))

coada=deque()
#Adaugam la coada nodul de start, si probabilitatea 1 (maxim).
coada.append((start,1))
vizitat=defaultdict(int)

while coada:
    #Scoatem nodul curent de pe coada
    nod,prob=coada.popleft()
    #Memoram la vizitat[nod] probabilitatile cele mai mari
    if vizitat[nod]>prob:
        continue
    else:
        vizitat[nod]=prob

    #Parcurgem toate nodurile adiacente ale nodului curent
    for adiacent,probUrm in graf[nod]:
        if vizitat[adiacent]<prob*probUrm:
            coada.append((adiacent,prob*probUrm))

#Afisam probabilitatea corespunzatoare capatului din dreapta.
print(vizitat[end])