def note(*liste):
    d={}
    for lista in liste:
        nr=0
        for numar in lista:
            if numar>=5:
                nr+=1
        if nr not in d:
            d[nr]=[lista]
        else:
            d[nr].append(lista)
    return d

print(note([5, 4, 2, 7, 10], [6, 7, 8, 10, 3], [10, 7, 4, 10, 9], [5, 6, 8, 4, 1], [5, 5, 6, 10, 7, 9]))

lista_cuvinte=["acasa", "masa", "este", "scaun", "perete", "dulap"]
lista_sufixe=["sa", "te"]

lista_rez=[cuvant for cuvant in lista_cuvinte for sufix in lista_sufixe if cuvant.endswith(sufix)]
print(lista_rez)
