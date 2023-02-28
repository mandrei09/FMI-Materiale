def despre_spiridus(d,cod):
    lista=[]
    for jucarie in d[cod]["jucarii"]:
        lista.append((jucarie,d[cod]["jucarii"][jucarie]["cantitate"]))
    return lista

def cheie(lista):
    return -lista[1],lista[0]

def jucarii(d):
    multime=set()
    for coduri in d:
        for jucarie in d[coduri]["jucarii"]:
            multime.add(jucarie)
    return multime

def cheie_jucarii(lista):
    return -lista[1],-lista[2],lista[0]

def spiridusi(d):
    lista=[]
    for coduri in d:
        nr=0
        bucati=0
        for jucarie in d[coduri]["jucarii"]:
            nr+=1
            bucati+=d[coduri]["jucarii"][jucarie]["cantitate"]
        lista.append((coduri,nr,bucati))
    return lista

d={}
f=open("spiridusi.txt")
for linie in f:
    cuvinte=linie.split()
    cod=cuvinte[0]
    cantitate=int(cuvinte[1])
    jucarie=cuvinte[2]
    if cod not in d:
        d[cod]={"jucarii":{}}
    if jucarie in d[cod]["jucarii"]:
        d[cod]["jucarii"][jucarie]["cantitate"]+=cantitate
    else:
        d[cod]["jucarii"][jucarie]={"cantitate":cantitate}
f.close()

lista=despre_spiridus(d,"S1")
print(sorted(lista,key=cheie))

print(*jucarii(d))

lista=spiridusi(d)
print(*sorted(lista,key=cheie_jucarii),sep='\n')

