""" #semnificatia variabilelor utilizate
def litere(*cuvinte):
    d={}
    for cuvant in cuvinte:
        d[cuvant]={}
        for litera in cuvant:
            if litera not in d[cuvant] :
                d[cuvant][litera]=1
            else:
                d[cuvant][litera]+=1
    return d

print(litere('teste', 'dictionar', 'ele'))

p='un exemplu de propozitie'
lung=[(cuvant,len(cuvant)) for cuvant in p.split() if cuvant.startswith("a") or cuvant.startswith("e") or cuvant.startswith("i") or cuvant.startswith("o") or cuvant.startswith("u") ]
print(lung) """

def f(lista, p, u):
    if u - p <= 1:
        return lista[0]
    k = (p + u) // 2
    if k % 2 == 1:
        return f(lista, p, k-1) + f(lista, k+1, u)
    else:
        return f(lista, p, k-2) + f(lista, k+1, u)

print(f([1,56,312,5,6],0,5))


