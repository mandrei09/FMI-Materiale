def modifica_nota(d,film,id,nota_noua):
    index=0
    ok=False
    for items in d[id]:
        if(items[0]==film):
            ok=true
            d[id][index][1]=nota
            break
        index+=1
    if ok==False:
        d[id].append([film,nota_noua])

d={}
f=open("filme.in")
for linie in f:
    split=linie.split()
    id_utilizator=split[0]
    nume_film=""
    for i in range(1,len(split)):
        if split[i].isnumeric()==False:
            nume_film+=split[i]+" "
    nume_film=nume_film[:-1]
    nota=int(split[len(split)-1])

    if split[0] not in d:
        d[split[0]]=[]
    d[split[0]].append([nume_film,nota])
f.close()

utilizator=input()
f=input().split()
film=""
for words in f:
    film+=words
    film+=" "
film=film[:-1]
nota=int(input())
modifica_nota(d,film,utilizator,nota)
print(d)