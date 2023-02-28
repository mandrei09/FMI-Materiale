#Pentru rezolvarea problemei ne vom folosi de un BFS modificat. Daca foloseam BFS clasic problema n-ar fii dat rezultate
#pentru conditia de a nu vizita un nod de 2 ori.
    #1. Facem BFS din fiecare nod, incercand sa ajungem la celelalte noduri.
    #2. Trebuie sa evitam ciclul infinit, dar in acelasi timp sa putem vizita un nod de mai multe ori.

from math import inf
from collections import deque

def shortestPathLength(graf):
    
    numarNoduri = len(graf) #graful ne este dat direct prin liste de adiacenta.

    # conceptually vizitat[k] indicates that only node k has been viz
    vizitat = [1 << i for i in range(numarNoduri)]
    # pentru a verifica daca totate nodurile au fost vizitate : 15 ==> 0b1111 adica cele 4 noduri au fost vizitate
    vizTotal = (1 << numarNoduri) - 1
    queue = deque([(i, vizitat[i]) for i in range(numarNoduri)])

    lungimeLant = 0 #rezultatul

    # encoded_visited in stariVizitat[node] iff
    # (node, encoded_visited) has been pushed onto the queue
    stariVizitat = [{vizitat[i]} for i in range(numarNoduri)]
    # states in stariVizitat will never be pushed onto queue again

    while queue:

        lungimeCoada = len(queue)
        while lungimeCoada:
            nodCurent, viz = queue.popleft()
            if viz == vizTotal:
                return lungimeLant #daca am vizitat toate nodurile, ne oprim

            #incepem BFS din fiecare nod adiacent
            for adiacent in graf[nodCurent]:
                #verificam daca adaugand la lant un vecin obtinem rezultatul dorit
                vizitatNou = viz | vizitat[adiacent]
                if vizitatNou == vizTotal:
                    return lungimeLant + 1
                
                #daca e prima data cand trecem prin acest lant
                if vizitatNou not in stariVizitat[adiacent]:
                    stariVizitat[adiacent].add(vizitatNou) #adaugam in multime
                    queue.append((adiacent, vizitatNou)) #adaugam in coada nodul adiacent

            lungimeCoada -= 1
        lungimeLant += 1

    #daca n-am gasit niciun lant hamiltonian, intoarcem infinit
    return inf

graf = [[1,2,3],[0],[0],[0]]
print(shortestPathLength(graf))