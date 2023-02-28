#Mihai Andrei-Alexandru
#grupa 141
#Se dă fișierul "matrice.in" cu următoarea structură: pe linia 𝑖 se află separate prin câte un spațiu
#𝑛 numere naturale reprezentând elementele de pe linia 𝑖 a unei matrice, ca în exemplul de mai
#jos. Este cunoscut faptul că în fișier se află 𝑛 ∗ 𝑛 elemente numere naturale, unde 𝑛 este un
#număr natural impar > 2.

def citire_matrice():
    matrice=[]
    f=open("matrice.in")
    for linie in f:
        lin=[int(x) for x in linie.split()]
        matrice.append(lin)
    f.close()
    return matrice

def bordare(matrice):

    #bordare ultima coloana
    lungime=len(matrice)
    for i in range(lungime):
        suma=sum(matrice[i])
        matrice[i].append(suma)

    #bordare ultima linie
    lungime=len(matrice)
    ultima=[]
    for i in range(lungime+1):
        s=0
        for j in range(lungime):
            s+=matrice[j][i]
        ultima.append(s)
    matrice.append(ultima)

    return matrice

matrice=citire_matrice()

matrice=bordare(matrice)

lungime=len(matrice)

matrice_adiacenta=[[0 for i in range (lungime)] for j in range(lungime)]

f=open("matrice.out","w")

for i in range(lungime):
    f.write(str(matrice[i][i]))
    f.write(' ')
    matrice_adiacenta[i][i]=1

for i in range(lungime):
    f.write(str(matrice[i][lungime-i-1]))
    f.write(' ')
    matrice_adiacenta[i][lungime-i-1]=1

for i in range(lungime):
    for j in range(lungime):
        if matrice_adiacenta[i][j]==0:
            f.write(str(matrice[i][j]))
            f.write(' ')

f.close()
