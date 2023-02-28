def citire_matrice():
    matrice=[]
    f=open("matrice.in")
    for linie in f:
        rand=[]
        for element in linie.split():
            rand.append(int(element))
        matrice.append(rand)
    f.close()
    return matrice

def mutare(matrice,*indici):
    pozMin=pozMax=0
    for indice in indici:
        Min=Max=matrice[0][indice]
        for i in range(len(matrice)):
            if matrice[i][indice]<Min:
                Min=matrice[i][indice]
                pozMin=i
            else:
                if matrice[i][indice]>Max:
                    Max=matrice[i][indice]
                    pozMax=i
        aux=matrice[pozMin][indice]
        matrice[pozMin][indice]=matrice[pozMax][indice]
        matrice[pozMax][indice]=aux

matrice=citire_matrice()
matrice[0][len(matrice)-1]*=2
mutare(matrice,0,1)

for i in range(len(matrice)):
    for j in range(len(matrice[i])):
        print(matrice[i][j],end=" ")
    print()