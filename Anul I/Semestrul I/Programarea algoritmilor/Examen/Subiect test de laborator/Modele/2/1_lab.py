def min_max(lista):
    Max=Min=lista[0]
    for elem in lista:
        if elem<Min:
            Min=elem
        if elem>Max:
            Max=elem
    return Min,Max

def incarca_fisier(nume_fisier):
    f=open(nume_fisier)
    lista=[]
    for linie in f:
        numere=linie.split()
        for i in range (len(numere)):
            numere[i]=int(numere[i])
        lista.append(numere)
    f.close()
    return lista

ok=0
den_fisier=input()

g=open("egale.txt","w")
lista=incarca_fisier(den_fisier)

lungime=len(lista)

for i in range(lungime):

    Min,Max=min_max(lista[i])
    if(Min==Max):
        g.write(str(i))
        g.write('\n')
        ok=1

if ok==0:
    g.write("Nu exista")

g.close()

lis=[]
for i in range(lungime):
    Min,Max=min_max(lista[i])
    lis.append(Min)
    lis.append(Max)

print(lis)
Min,Max=min_max(lis)

print(Min,Max)