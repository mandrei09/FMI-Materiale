file = open("2.txt",'r')
numarNoduri, numarMuchii = (int(valoare) for valoare in file.readline().split()) 

pozitii = [-1 for i in range(numarNoduri+1)] 

ordine = [int(valoare) for valoare in file.readline().split()]

for index in range(len(ordine)):
    aux = ordine[index]
    pozitii[aux] = index # memoram indexul fiecarui nod in permutarea data

adiacente = [[] for index in range(numarNoduri+1)]

for linie in file.readlines():
    m1 = int(linie.split()[0])
    m2 = int(linie.split()[1])
    adiacente[m1].append(m2)
    adiacente[m2].append(m1)
file.close()

# sortam fiecare lista de adiacenta in functie de vectorul "pozitii"
for index in range(1, numarNoduri+1):
    adiacente[index].sort(key = lambda x: pozitii[x])

# parcurgem in adancime
def check_dfs(nod):
    coada.append(nod)
    vizitate[nod] = 1
    for nodAdiacent in adiacente[nod]:
        if vizitate[nodAdiacent] == 0:
            check_dfs(nodAdiacent)


vizitate = [0 for index in range(numarNoduri+1)] 
coada = []
check_dfs(1)

if coada == ordine:
    print(1)
else:
    print(0)