import math
def deviruseaza(virus):

    lista_prop=[]
    prop=""
    cuvinte=virus.split()
    lungime=len(cuvinte)

    for i in range(lungime):

        lungime_cuvant=len(cuvinte[i])
        if lungime_cuvant>1:
            lista_prop.append(cuvinte[i][lungime_cuvant-1]+cuvinte[i][1:lungime_cuvant-1]+cuvinte[i][0])
        else:
            lista_prop.append(cuvinte[i])

    prop=" ".join(cuvant for cuvant in reversed(lista_prop))
    return prop

def prim(x):
    if x<2:

        return 0

    rad=int(math.sqrt(x))

    for i in range(2,rad+1):

        if x%i==0:

            return 0

    return 1

def prime(n,numar_maxim=0):
    lungime=range(n+1)
    lista=[numar for numar in lungime if prim(numar)==1]
    l_lista=len(lista)

    if numar_maxim!=0:

        lista[numar_maxim:l_lista+1]=[]

    return lista

f=open("intrare.in")

nr_linii=0
for linie in f:
    nr_linii+=1
lista=prime(nr_linii)

f.close()

nr_linii=1

f=open("intrare.in")
g=open("intrare_devirusata.out","w")

for linie in f:

    linie=linie.rstrip('\n')

    if nr_linii in lista:

        g.write(deviruseaza(linie))

    else:

        g.write(linie)

    g.write('\n')
    nr_linii+=1

f.close()
g.close()



    