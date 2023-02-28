#Citire date
f=open("strings.txt")
n,k=[int(x) for x in f.readline().split()]
cuvinte=f.read().split()
# print(n,k,cuvinte)
f.close()

#daca k = 1, afisam pur si simplu fiecare string.
if k==1:
    for string in cuvinte:
        print(string,end="")
else:

    # Calculam pentru fiecare string care este prefixul lui
    # de lungime k-1 si sufixul de lungime k-1, si tinem minte
    # cate un id pentru a crea un nod virtual care sa reprezinte stringul.
    # Trag o muchie intre prefixul si sufixul fiecarui string.
    
    stringId={} #dictionar care retine pentru fiecare prefix / sufix un ID
    revStringId={} #inversul celui de mai sus, pentru fiecare ID retine prefixul / sufixul
    id=0 #va retine numarul "nodurilor"
    gradInterior=[]
    gradExterior=[]
    adiacenta=[] #listele de adiacenta pentru fiecare string prefix / sufix

    for cuv in cuvinte:

        prefix = cuv[:k-1]
        if prefix not in stringId:
            revStringId[id]=prefix
            stringId[prefix]=id
            id+=1
            gradInterior.append(0)
            gradExterior.append(0)
            adiacenta.append([])

        sufix = cuv[1:k]
        if sufix not in stringId:
            revStringId[id]=sufix
            stringId[sufix]=id
            id+=1
            gradInterior.append(0)
            gradExterior.append(0)
            adiacenta.append([])

        prefId=stringId[prefix]
        sufId=stringId[sufix]
        adiacenta[prefId].append(sufId)
        gradInterior[sufId]+=1
        gradExterior[prefId]+=1
    
    #Practic : stringID contine pentru fiecare prefix un ID
    #pentru a-l putea utiliza in listele de adiacenta si a calcula gradul
    #interior si cel exterior.

    # In continuare, verificam daca se poate face un lant eulerian, anume daca nu exista noduri
    # cu diferenta dintre gradul de intrare si gradul de iesire mai mare decat 1,
    # iar daca exista sunt maxim 2, iar cel cu gradul de intrare mai mic trebuie sa
    # fie nodul de start
    start = 0 #retine nodul de start 
    nr = 0 #numara cate noduri au dif dintre gradul de intrare si cel de iesire > 1 
    for i in range(id):
        if gradInterior[i] == gradExterior[i]:
            continue
        if abs(gradInterior[i] - gradExterior[i]) > 1:
            print(-1)
            break
        nr += 1
        if nr > 2:
            print(-1)
            break
        if gradInterior[i] < gradExterior[i]:
            start = i
    
    #
    stiva = []
    viz = [False for i in range(id)]
    answer = []
    stiva.append(start)

    #Parcurgem nodurile 
    while len(stiva) > 0:
        #preluam ndoul din varful stivei
        nod = stiva[-1]
        #il vizitam
        if not viz[nod]:
            viz[nod] = True

        if len(adiacenta[nod]) == 0:
            answer.append(nod)
            stiva.pop()
        else:
            adj = adiacenta[nod].pop()
            stiva.append(adj)

    #In lista answer, nodurile care formeaza raspunusul
    #sunt in ordine inversa, datorita utilizarii stivei.

    # Daca exista un nod nevizitat, inseamna ca avem mai multe componente conexe
    # si nu putem construi un string cumulat.

    if False in viz:
        print(-1)
    else:

        concatenat = ""

        while len(answer):
            concatenat += revStringId[answer[-1]][-1]
            answer.pop()

        print(concatenat)