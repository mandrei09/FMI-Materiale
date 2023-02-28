import sys
def printMatrix(matrice):
    for i in range(len(matrice)):
        for j in range(len(matrice[i])):
            print(matrice[i][j],end=" ")
        print()

#functie care ne ajuta sa gasim indexul nodului care trebuie vizitat data viitoare
def deVizitat():

    global vizitat
    global distanta
    index = -10
    for i in range(n+1):
        if vizitat[i]==0 and (index<0 or distanta[i]<=distanta[index]): 
            #ne intereseaza nodurile nevizitate si care au o distanta cat mai mica
            index=i
    return index

#citire date
f = open("catun.in")

n, m, k = [int(x) for x in f.readline().split()]

fortarete = [int(x) for x in f.readline().split()]

sate = []

for i in range(m):

    linie = [int(x) for x in f.readline().split()]
    sate.append(linie)

f.close()
#########

#Creem matricea de adiacenta unde adiacenta[i][j]=c ==> muchia i j are costul=c
adiacenta=[[0 for i in range(n+1)] for j in range(n+1)]

for i in range(m):
    adiacenta[sate[i][0]][sate[i][1]]=adiacenta[sate[i][1]][sate[i][0]]=sate[i][2]

rezultat=[0 for i in range(n+1)]

#Pentru fiecare nod calculam distanta de la el la celelalte noduri
for i in range(1,n+1):
    vizitat=[0 for i in range(n+1)]
    distanta=[sys.maxsize for i in range(n+1)] #se incepe cu distanta infinit pentru toate nodurile
    #mai putin cel caruia ii calculam distanta
    distanta[i]=0
    for nod in range(1,n+1):
        #Cautam urmatorul nod ce trebuie vizitat
        nodUrmator=deVizitat() #Vezi explicatii la functie
        for vecin in range (1,n+1):
            #Actualizam distantele
            if adiacenta[nodUrmator][vecin] > 1 and vizitat[vecin]==0:
                #daca exista muchie                 nevizitata
                #calculam o distanta noua ca fiind suma distantelor
                distantaNoua=distanta[nodUrmator]+adiacenta[nodUrmator][vecin]
                #noi vrem sa obtinem distante cat mai mici, deci selectam in functie de asta
                if distantaNoua<distanta[vecin]:
                    distanta[vecin]=distantaNoua
            #Vizitam
            vizitat[nodUrmator]=1

    #La final calculam minimul dintre distantele dintre nodul curent si toate fortaretele
    Min=sys.maxsize
    for fortareata in fortarete:
        if distanta[fortareata]<Min:
            Min=distanta[fortareata]
            rezultat[i]=fortareata
    counter = 0
    for fortareata 