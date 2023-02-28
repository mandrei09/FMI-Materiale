#Modelam problema cu ajutorul unui graf bipartit G = (L, C, M):
#--> L = {1, 2, ... N} = liniile
#--> C = {1, 2, ... N} = coloanele 
#--> M = {(i, j), cu proprietatea ca elementul de pe pozitia (i, j) este 1}

#Facem cuplaj pe graful obtinut anterior.
#--> Daca fluxul este egal cu n avem solutie: 
#     muchiile din cuplaj care nu sunt pe diagonala
# --> Daca fluxul nu este egal cu n:
#     nu avem o solutie

from collections import deque

#BFS pentru flux
def bfs():
    global viz
    global tata
    #resetam coada, vectorul de tati si cel de vizitare
    coada = deque()
    for i in range(2*n+2):
        tata[i]=-1
        viz[i]=0

    #incepem din nodul sursa(0)
    coada.append(0)
    viz[0]=1

    while(len(coada)):
        nod=coada.popleft()
        if nod==2*n+1: #daca am ajuns la destinatie, ne oprim
            return 1
        #parcurgem toate nodurile
        for i in range(1,2*n+2):
            if viz[i]==0 and cuplaj[nod][i]>0:
                coada.append(i)
                tata[i]=nod
                viz[i]=1
    return 0

#algoritmul pentru flux
def flux():
    global maxflow
    while(bfs()):
        for i in range(n+1,2*n+1): #parcurgem nodurile din cea de-a doua multime
            if cuplaj[i][2*n+1] > 0 and viz[i]==1:
                #memoram drumul in vector, mergeand pe vectorul de tati
                drum=[]
                drum.append(2*n+1)
                drum.append(i)
                nod=tata[i]
                if nod==0:
                    drum.append(nod)
                else:
                    while nod:
                        drum.append(nod)
                        nod=tata[nod]
                    drum.append(0)
                drum.reverse()
                capacitateMinima = 99999 #initial este infinit
                #calculam capacitatea minima a drumului
                for i in range(len(drum)-1):
                    capacitateMinima=min(capacitateMinima,cuplaj[drum[i]][drum[i+1]])
                #si o adaugam al valoarea fluxului maxim
                maxflow+=capacitateMinima

                #actualizam capacitatile in ambele sensuri
                for i in range(len(drum)-1):
                    cuplaj[drum[i]][drum[i+1]] -= capacitateMinima
                    cuplaj[drum[i+1]][drum[i]] += capacitateMinima
    return maxflow

#citire date----------------------------------------
f=open("matrix.txt")
n=[int(x) for x in f.readline().split()][0]
matriceInitiala=[[0 for _ in range(n+1)] for _ in range(n+1)]
cuplaj=[[0 for _ in range(2*n+2)] for _ in range(2*n+2)]
for i in range(1,n+1):
    linie=[int(x) for x in f.readline().split()]
    linie.insert(0,-1)
    for j in range(1,n+1):
        matriceInitiala[i][j]=linie[j]
            #Daca avem 1 la intersectia liniei si a coloanei adaugam si in matricea pentru cuplaj. 
            #Folosim n+j ca sa nu confundam linia 1 cu coloana 1.
            #Practic, dublam nodurile asa cum faceam la cuplaj normal.

        cuplaj[i][n+j]=matriceInitiala[i][j]
#---------------------------------------------------
f.close()

#Adaugam muchii de la sursa(0) la orice alt nod din prima multime
for i in range(1,n+1):
    cuplaj[0][i]=1
#Adaugam muchii de la destinatie(2*n+1) la orice alt nod din a doua multime
for i in range(1,n+1):
    cuplaj[i+n][2*n+1]=1

index=[i for i in range(n+1)] #retine indexul fiecarei linii
                              #ne va ajuta pentru momentul cand vom interschimba liniile

tata=[-1 for _ in range(2*n+2)] #vectorul de tati
viz=[0 for _ in range(2*n+2)] #vectorul de vizitare

maxflow=0 #valoarea fluxului maxim pentru graf

pereche=[0 for i in range(2*n+2)] #pentru afisarea solutiei

f=flux()
if f!=n: #daca fluxul nu a dat n, nu avem solutie
    print(-1)
else:
    #gasim perechile cuplate
    for i in range(1,n+1):
        for j in range(1,n+1):
            if matriceInitiala[i][j]!=0 and cuplaj[i][j+n]==0:
                pereche[i]=j
    #pentru fiecare linie, daca a fost cuplata cu alta, interschimbam liniile si afisam operatia. 
    for i in range(1,n+1):
        if pereche[i]!=index[i]:
            j=1
            while pereche[i]!=index[j]:
                j+=1
            print("R",index[i],index[j])
            aux=index[i]
            index[i]=index[j]
            index[j]=aux
