def conditiiCastig(joc):
    #Daca prima linie este xxx
    if joc[0] == joc[1] and joc[1]==joc[2] and joc[1]:
        return 1
    #Daca a doua linie este xxx
    if joc[3]==joc[4] and joc[4]==joc[5] and joc[3]:
        return 1
    #Daca a treia linie este xxx
    if joc[6]==joc[7] and joc[7]==joc[8] and joc[6]:
        return 1
    #Daca prima coloana este xxx
    if joc[0]==joc[3] and joc[3]==joc[6] and joc[0]:
        return 1
    #Daca a doua coloana este xxx
    if joc[1]==joc[4] and joc[4]==joc[7] and joc[1]:
        return 1
    #Daca a treia coloana este xxx
    if joc[2]==joc[5] and joc[5]==joc[5] and joc[2]:
        return 1 
    #Daca diagonala principala este xxx
    if joc[0]==joc[4] and joc[4]==joc[8] and joc[0]:
        return 1
    #Daca diagnoala secundara este xxx
    if joc[2]==joc[4] and joc[4]==joc[6] and joc[2]:
        return 1
    return 0 
     
def calculeazaConfiguratie(nrConfig):
    #daca configuratia este deja rezolvata, o returnam
    if configuratii[nrConfig]:
        return configuratii[nrConfig]
    copie = nrConfig # auxiliar care urmeaza alterat
    x = 0 #variabila care retine numarul x-urilor din joc
    o = 0 #variabila care retine numarul 0-urilor din joc 
    joc=[0 for _ in range(9)]
        #retine tabla de x si y
        #joc[i][j]=0 ==> casuta libera
        #         =1 ==> x 
        #         =2 ==> 0
    for i in range(9): #calculam numarul de x si 0
        joc[i]=copie%3 
        copie//=3
        if joc[i]==1:
            x+=1
        elif joc[i]==2:
            o+=1 

    #Verificam conditiile de castig 
    if conditiiCastig(joc):
        if x>o:
            configuratii[nrConfig] = 1
            #Daca sunt mai multe x-uri si cineva castiga ==> win
            return 1
        configuratii[nrConfig] =-1
        #Altfel ==> lose
        return -1
    
    if x+o==9:
        #Daca tabla s-a umplut si nimeni nu a castigat ==> draw
        configuratii[nrConfig]=2
        return 2
    
    if x==o:
        #Tabla nu s-a umplut. Inseamna ca este randul jucatorului care are x
        configuratii[nrConfig]=-1 #provizoriu consideram ca aceasta configuratie este invalida
        ok=0 #verificam daca am ales o configuratie deja
        for i in range(9): 
            if joc[i]==0: #in casuta i din tabela este momentan goala
                nrConfigNoua =nrConfig + putere3[i] #umplem casuta curenta
                rezultat = calculeazaConfiguratie(nrConfigNoua) #calculam noua configuratie
                #Daca noua configuratie este castigatoare, o actualizam si pe cea curenta
                if rezultat == 1: 
                    configuratii[nrConfig]=1
                    ok=1
                #Actualizam pentru cand a castigat jucatorul cu 0
                if rezultat==2 and ok==0:
                    configuratii[nrConfig]=2
    else:
        #Tabla nu s-a umplut, dar este randul jucatorului care pune 0
        configuratii[nrConfig]=1 #provizoriu consideram ca aceasta configuratie este win pentru x 
        ok=0 #verificam daca am ales o configuratie deja
        for i in range(9): 
            if joc[i]==0: #in casuta i din tabela este momentan goala
                nrConfigNoua =nrConfig + 2*putere3[i] #umplem casuta curenta
                rezultat = calculeazaConfiguratie(nrConfigNoua) #calculam noua configuratie
                #Daca noua configuratie este castigatoare, o actualizam si pe cea curenta
                if rezultat < 0: 
                    configuratii[nrConfig]=-1
                    ok=1
                #Actualizam pentru cand a castigat jucatorul cu 0
                if rezultat==2 and ok==0:
                    configuratii[nrConfig]=2
    return configuratii[nrConfig]

indiceTest = 1 #pentru afisare
numarConfiguratie = 0 
putere3=[3**i for i in range(10)] #vector care retine puterile lui 3, pentru a calcula configuratia potrivita
configuratii=[0 for _ in range(20000)] # stocheaza pentru fiecar econfiguratie posibila 
                                       # 0 pentru invalid
                                       # 1 pentru win
                                       # -1 pentru lose
                                       # 2 pentru draw
calculeazaConfiguratie(0) #prima configuratie este aceea in care tabla este goala
f=open("xsizero.in")
g=open("xsizero.out","w")
linii=f.read().split()
nr=0
tabla=[]
for linie in linii:
    for caracter in linie:
        tabla.append(caracter)
    nr+=1
    if nr==3:
        nrConfig=0
        #Am memorat cu succes o tabla de joc
        for i in range(9):
            if tabla[i]=='X':
                nrConfig += putere3[i]
            elif tabla[i]=='0':
                nrConfig += 2*putere3[i]
        g.write("Testul #"+str(indiceTest)+":")
        if configuratii[nrConfig]==-1:
            g.write("lose\n")
        elif configuratii[nrConfig]==0:
            g.write("invalid\n")
        elif configuratii[nrConfig]==1:
            g.write("win\n")
        else:
            g.write("draw\n")
        indiceTest+=1
        #O resetam pentru a memora alta
        tabla=[]
        nr=0
g.close()
f.close()

