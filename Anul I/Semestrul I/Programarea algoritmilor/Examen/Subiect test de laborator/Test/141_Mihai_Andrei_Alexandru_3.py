#Mihai Andrei-Alexandru
#grupa 141
#Se consideră o rețea în plan formată din puncte unite prin linii numite legături (muchii).
#Fiecare punct are coordonatele întregi, iar o legătură are asociată o culoare (un șir de
#caractere fără spații reprezentând numele culorii, de exemplu: roșu, verde, albastru) și o
#etichetă (un șir care poate conține spații). Un punct cu coordonatele x și y va fi notat (x,y). Se
#consideră fișierul text legaturi.in care conține informații despre o astfel de rețea, fiecare linie
#conținând informații despre o legătură sub forma:

d={}

f=open("legaturi.in")
for linie in f:
    cuvinte_2=[]
    cuvinte=linie.split(maxsplit=3)
    for element in cuvinte:
        element=element.rstrip('\n')
        cuvinte_2.append(element)
    cod1=(int(cuvinte_2[0][1]),int(cuvinte_2[0][3]))
    cod2=(int(cuvinte_2[1][1]),int(cuvinte_2[1][3]))
    culoare=cuvinte_2[2]
    eticheta=cuvinte_2[3]
    d[cod1][cod2]["informatii"]={"culoare":culoare,"eticheta":eticheta}
    #d={"cod1":cod1,"cod2":cod2,"culoare":culoare,"eticheta":eticheta}
f.close()

print(d)