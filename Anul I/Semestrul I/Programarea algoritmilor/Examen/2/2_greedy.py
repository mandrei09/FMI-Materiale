""" n,h=(input().split())
n=int(n)
h=int(h)
date=[]
for i in range(n):
    nume=input()
    inaltime=int(input())
    date.append((nume,inaltime)) """

def cheie(x):
    return x[1]

n=8
h=10
date=[("Popescu Ion", 172),("Mihai Ana", 162),("Popescu Dana", 190),("Ionescu Ion", 181),("Georgescu Ioana", 170),("Dumitrescu George", 188),("Constantinescu Radu", 165),("Georgescu Anca", 210)]
date=sorted(date,key=cheie)
print(date)
numar_grupe=0
i=0
indici=[]
while i<n-1:
    if date[i+1][1]-date[i][1]<=h:
        numar_grupe+=1
        indici.append(i)
        i+=1
    i+=1
print(numar_grupe)
for indice in indici:
    print(date[indice][0],date[indice+1][0],sep=",")