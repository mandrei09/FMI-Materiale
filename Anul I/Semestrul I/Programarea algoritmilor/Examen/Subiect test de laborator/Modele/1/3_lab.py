def sterge_carte(d,cod_carte):
    ok=0
    for cod in d:
        for carte in d[cod]["carti"]:
            if cod_carte==carte:
                ok=1
                autor=cod
                break
    if ok==0:
        return None
    else:
        del d[autor]["carti"][cod_carte]
        return d[autor]["nume"],d[autor]["prenume"]

def cheie(lista):
    return lista[1],-lista[2],lista[0] 
    
def carti_autor(d,cod_autor):
    ok=0
    lista=[]
    for cod in d:
        if cod_autor==cod:
            ok=1
            for carte in d[cod_autor]["carti"]:
                lista.append((d[cod_autor]["carti"][carte]["titlu"],int(d[cod_autor]["carti"][carte]["an"]),int(d[cod_autor]["carti"][carte]["numar de pagini"])))
    if ok==0:
        return lista
    else:
        lista.insert(0,d[cod_autor]["nume"])
        lista.insert(1,d[cod_autor]["prenume"])
        return lista

d={}
f=open("autori.in")
m,n=f.readline().split()
m=int(m)
n=int(n)
i=1
for linie in f:
    cuvinte=linie.split(maxsplit=4)
    cod=int(cuvinte[0])
    if i<=m:
        d[cod]={"nume":cuvinte[1],"prenume":cuvinte[2],"carti":{}}
    else:
        cod_carte=int(cuvinte[1])
        an_aparitie=int(cuvinte[2])
        nr_pagini=int(cuvinte[3])
        nume=cuvinte[4].rstrip('\n')
        d[cod]["carti"][cod_carte]={"an":an_aparitie,"numar de pagini":nr_pagini,"titlu":nume}
    i+=1
f.close()

'''
cod_sters=int(input())
Nume=sterge_carte(d,cod_sters)

if Nume==None:
    print("Cartea nu exista")
else:
    print("Cartea a fost scrisa de",Nume[0],Nume[1])
    print(d)
'''
rezultat=carti_autor(d,int(input()))
print(rezultat[0],rezultat[1])
rezultat[0:2]=[]
rezultat=sorted(rezultat,key=cheie)
for i in range(len(rezultat)):
   print(rezultat[i][0],rezultat[i][1],rezultat[i][2])