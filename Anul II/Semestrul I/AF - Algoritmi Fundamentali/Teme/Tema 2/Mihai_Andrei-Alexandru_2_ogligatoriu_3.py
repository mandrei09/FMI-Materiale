# Am creat functia pentru distanta levenshtein, folosind tehnica programarii dinamice.
# Problema se imparte in 2 subprobleme, anume:
# -Daca ambele cuvinte au ultimul caracter identic, atunci distanta de editare finala
# este aceeasi ca distanta de editare a ambelor siruri pana la penultimul caracter.
# -Daca ultimul caracter difera, atunci distanta va fi 1 + costul minim dintre 
# inserare, stergere si inlocuire a unui caracter.
# Astfel, matrice[i][j] retine distanta dintre cuvintele i si j.

def printMatrix(matrice):
    for i in range(len(matrice)):
        for j in range(len(matrice[i])):
            print(matrice[i][j],end=" ")
        print()


#Calculul distantei Levenshtein pentru clustere de cuvinte similare
def calculDistanta(cuvant1,cuvant2):

    #1. Initializarea matricei

    matrice=[[0 for _ in range(len(cuvant2)+1)] for _ in range(len(cuvant1)+1)]

    for i in range(len(cuvant2)+1):
        matrice[0][i]=i

    for i in range(len(cuvant1)+1):
        matrice[i][0]=i

    # 0 1 2 3 4 5 
    # 1 0 0 0 0 0
    # 2 0 0 0 0 0
    # 3 0 0 0 0 0
    # 4 0 0 0 0 0

    for i in range(1,len(matrice)):
        for j in range(1,len(matrice[i])):
            if cuvant1[i-1]==cuvant2[j-1]:
                matrice[i][j]=matrice[i-1][j-1]
            else:
                matrice[i][j]=1+min(matrice[i-1][j],matrice[i-1][j-1],matrice[i][j-1])
                                    #stergem        #modificam        #inseram

    i=len(matrice)-1
    j=len(matrice[0])-1

    distanta=0

        #2.Se parcurge matricea de la ultimul element, pana la primul
        #  Se creste distanta in una dintre cele 3 situatii : stergere, inserare, modificare

    while i+j!=0:
        if cuvant1[i-1]==cuvant2[j-1]:
            i-=1
            j-=1
        else:
            if matrice[i][j]-1==matrice[i][j-1]: #inseram
                distanta+=1
                j-=1
            else:
                if matrice[i][j]-1==matrice[i-1][j-1]: #modificam
                    distanta+=1
                    i-=1
                    j-=1
                else:
                    if matrice[i][j]-1==matrice[i-1][j]: #stergem
                        distanta+=1
                        i-=1
    return distanta

f=open("cuvinte.in")
cuvinte=[x for x in f.read().split()]
f.close()

k=int(input())

clase = [[] for i in range(k)]
marcat=[0 for i in range(len(cuvinte))]

#Creez o matrice de adiacenta care contine distantele pentru fiecare 2 cuvinte

numarNoduri=len(cuvinte)

adiacenta=[[0 for i in range(numarNoduri)]for j in range(numarNoduri)]
for i in range(1,len(adiacenta)):
    for j in range(i):
        dist=calculDistanta(cuvinte[i],cuvinte[j])
        adiacenta[i][j]=dist
        adiacenta[j][i]=dist
    
# printMatrix(adiacenta)

clasaCurenta=0

#?????????????????????????
for i in range(numarNoduri):
    if marcat[i]==0:
        marcat[i]=1
        clase[clasaCurenta].append((cuvinte[i],i))
        Min=1000
        for j in range(numarNoduri):
            if adiacenta[i][j]<Min and marcat[j]==0:
                Min=adiacenta[i][j]
        for j in range(numarNoduri):
            if adiacenta[i][j]==Min:
                marcat[j]=1
                clase[clasaCurenta].append((cuvinte[j],j))
        if clasaCurenta!=k-1:
            clasaCurenta+=1

print(*clase)