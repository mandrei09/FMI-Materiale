#Pentru aceasta problema, vom reprezenta emailurile ca si noduri, iar 
#o muchie intre 2 email-uri inseamna ca acestea apartin aceluiasi user,
#deci fiecare cont se poate reprezenta ca o componenta conexa in graf.
#1. Conectam fiecare email al unui cont cu celalalte email-uri.
#2. Prin DFS cautam fiecare email care apartine aceleasi persoane.

def DFS(email):
    global contCombinat
    viz.append(email)
    #adaugam in lista de email-uri email-ul curent
    contCombinat.append(email)
    #parcurgem toate "nodurile" adiacente
    for adiacent in adiacenta[email]:
        if adiacent not in viz:
            DFS(adiacent)

accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
#construim listele de adiacenta - adaugam o muchie intre primul email din cont si toate celelalte email-uri din acelasi cont
adiacenta={}
for cont in accounts:
    if len(cont)<3:
        if cont[1] not in adiacenta:
                adiacenta[cont[1]]=[]
    else:
        for i in range(2,len(cont)):
            if cont[1] not in adiacenta:
                adiacenta[cont[1]]=[cont[i]]
            else:
                adiacenta[cont[1]].append(cont[i])
            if cont[i] not in adiacenta:
                adiacenta[cont[i]]=[cont[1]]
            else:
                adiacenta[cont[i]].append(cont[1])

#trecem prin toate conturile pentru a forma componente conexe
conturi=[]
viz=[]
for cont in accounts:
    user=cont[0]
    #Daca un email este vizitat, este parte dintr-o componenta conexa diferita
    #Facem DFS doar daca email-ul nu este vizitat
    if cont[1] not in viz:
        global contCombinat
        contCombinat=[]
        #Intai adaugam user-ul
        contCombinat.append(user)
        DFS(cont[1])
        conturi.append(contCombinat)
print(conturi)