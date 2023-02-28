def modifica_prefix(x,y,prop):
    nr=0
    propozitie=[]
    lenx=len(x)
    for cuvant in prop.split():
        if cuvant[:lenx]==x:
            propozitie.append(y+cuvant[lenx:])
            nr+=1
        else:
            propozitie.append(cuvant)
    return propozitie,nr

def poz_max(lista):
    Max=lista[0]
    for element in lista:
        if element>Max:
            Max=element
    pozitii=[]
    i=1
    for element in lista:
        if element==Max:
            pozitii.append(i)
        i+=1
    return pozitii

f=open("propozitii.in")
g=open("propozitii_modificate.out","w")

prefix1,prefix2=input().split()
lista=[]

for linie in f:
    propozitie=""
    nr=modifica_prefix(prefix1,prefix2,linie)[1]
    propozitie=" ".join(modifica_prefix(prefix1,prefix2,linie)[0])
    g.write(propozitie)
    g.write('\n')
    lista.append(nr)

f.close()
g.close()

print(*poz_max(lista))