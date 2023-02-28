def vocale(*cuvinte):
    d={}
    vocale=["a","e","i","o","u"]
    nr=0
    for cuvant in cuvinte:
        for vocala in vocale:
            p=cuvant.find(vocala)
            while(p!=-1):
                nr+=1
                p=cuvant.find(vocala,p+1)
        if nr not in d:
            d[nr]=[cuvant]
        else:
            d[nr].append(cuvant)
        nr=0
    return d

print(vocale("acasa", "masa", "scaun", "oaie", "oare"))