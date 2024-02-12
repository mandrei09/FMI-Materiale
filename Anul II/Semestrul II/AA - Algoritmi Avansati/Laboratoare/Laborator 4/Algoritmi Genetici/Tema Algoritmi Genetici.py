import copy
import math
import random
import sys

# Numarul de biti necesar pentru a codifica numerele din [a,b]
def calculLungime(a,b,p):
    return math.ceil(math.log2((b-a)*(10**p)))

# Pasul de discretizare
def pasDiscretizare(a,b,l):
   return (b-a)/(2**l)

def suma(index,arr):
    return sum(arr[:index+1])

def primulCromozomPoz(valoriFunctie,nrCrom):
    max = -sys.maxsize
    poz=0
    for i in range(nrCrom):
        if valoriFunctie[i]>max:
            max=valoriFunctie[i]
            poz=i
    return  poz

def meanFitness(valoriFunctie,nrCrom):
    return sum(valoriFunctie[:nrCrom])/nrCrom

def cautaInterval(v, n, x):
    st = 0
    dr = n - 1
    poz = -1

    while dr >= st:
        mid = (st + dr) // 2
        if x > v[mid]:
            poz = mid
            st = mid + 1
        else:
            dr = mid - 1

    return poz + 1

def incrucisare(x1,x2,i):
    return x1[:i]+x2[i:],x2[:i]+x1[i:]

def incrucisare2(x1,x2,i,j):
    return x1[:i]+x2[i:j]+x1[j:], x2[:i]+x1[i:j]+x2[j:]

def mutatie(x,probMutatie):
    mutX=copy.deepcopy(x)
    for i in range(len(x)):
        if random.uniform(0, 1) < probMutatie:
            if x[i]==1:
                mutX[i]=0
            elif x[i]==0:
                mutX[i]=1
    return mutX
  
# Funcția de maximizat, coeficienții fiind citiți la input
def calculFunctie(x, c):
    return c[0]*(x**3) + c[1]*(x**2) + c[2]*x + c[3]

def citireDate():
    n = int(input("Dimensiunea populatiei= "))
    print("Domeniul functiei")
    a = int(input("\ta= "))
    b = int(input("\tb= "))
    print("Parametrii functiei de maximizat: ", end=" ")
    coef = [int(x) for x in input().split()]
    precizie = int(input("precizia = "))
    pr = float(input("probabilitatea de incrucisare = "))
    pm = float(input("probabilitatea de mutatie = "))
    stages = int(input("numarul de etape= "))
    
def citireDateFisier():
    f=open("input.txt")
    n = [int(x) for x in f.readline().split()][0]
    a,b = [int(x) for x in f.readline().split()]
    coef = [int(x) for x in f.readline().split()]
    precizie = [int(x) for x in f.readline().split()][0]
    pr = [float(x) for x in f.readline().split()][0]
    pm = [float(x) for x in f.readline().split()][0]
    stages = [int(x) for x in f.readline().split()][0]
    f.close()
    return n, a, b, coef, precizie, pr, pm, stages

def afisareCromozomi(g):
    for i in range(numarCromozomi):
        if i + 1 < 10:
            g.write('\t')
        else:
            g.write("   ")
        g.write(str(i + 1) + " : " + ''.join(map(str, cromozomi[i])) + " x = ")
        g.write("{:.{}f}".format(valoriCromozomi[i], precizie))
        if valoriCromozomi[i]>=0:
            g.write("  f = ")
        else:
            g.write(" f = ")
        g.write("{:.{}f}".format(valoriFunctie[i], precizie))
        g.write("\n")

#------------------------------------------------------------------------------------------------

def solve(g,stage):
    global valoriCromozomi,valoriFunctie
    if stage==0:
        g.write("\nProbabilitate selectie: \n\n")
    F = suma(numarCromozomi-1,valoriFunctie)
    
    probabilitateSelectie=[val/F for val in valoriFunctie]
    
    if stage==0:
        for i in range(numarCromozomi):
            g.write("\t Cromozomul " + str(i+1) + " are probabilitatea " + str(probabilitateSelectie[i]) +"\n")
    
    if stage==0:  
        g.write("\nIntervale probabilitati selectate:\n\n")
        
    intervaleSelectie=[suma(i,valoriFunctie)/F for i in range(len(valoriFunctie))]
    
    if stage==0:
        for i in range(numarCromozomi):
            g.write("\t" + str(intervaleSelectie[i]) + "\n")
            
        g.write("\n")
        
    #Selectie------------------------------------------------------------------------------------
    numereRandom=[random.uniform(0, 1) for _ in range(numarCromozomi)]
    cromozomiSelectie=[cautaInterval(intervaleSelectie,numarCromozomi,rand) for rand in numereRandom]
    
    if stage==0:
        for i in range(numarCromozomi):
            g.write("\tu = " + str(numereRandom[i]) + " selectam cromozomul " + str(cromozomiSelectie[i]) + "\n")
    
    cromozomiAux=copy.deepcopy(cromozomi)
    valoriFunctieAux=copy.deepcopy(valoriFunctie)
    valoriCromozomiAux=copy.deepcopy(valoriCromozomi)
    
    for i in range(numarCromozomi):
        poz=cromozomiSelectie[i]-1
        cromozomi[i]=cromozomiAux[poz]
        valoriFunctie[i]=valoriFunctieAux[poz]
        valoriCromozomi[i]=valoriCromozomiAux[poz]
    
    if stage==0:
        g.write("\nDupa selectie: \n\n")
        afisareCromozomi(g)

        g.write("\nProbabilitatea de incrucisare " + str(pr) + "\n\n")
    numereRandom2=[random.uniform(0, 1) for _ in range(numarCromozomi)]
    
    cromozomiDeRecombinat=[]
    for i in range(numarCromozomi):
        if stage==0:
            if i + 1 < 10:
                g.write('\t')
            else:
                g.write("   ")

            g.write(str(i + 1) + " : " + ''.join(map(str, cromozomi[i])) + " u = " + str(numereRandom2[i]) + " ")
    
        if numereRandom2[i]<pr:
            if stage==0:
                g.write("< " + str(pr) + " participa")
            cromozomiDeRecombinat.append(i)
        if stage==0:    
            g.write("\n")
    if stage==0:  
        g.write("\n")
    
    #Recombinare---------------------------------------------------------------------------------
    random.shuffle(cromozomiDeRecombinat)
    lungime = len(cromozomiDeRecombinat)

    if lungime % 2 == 0:
        for i in range(0, lungime - 1, 2):
            
            crom1 = cromozomiDeRecombinat[i]
            crom2 = cromozomiDeRecombinat[i + 1]
            if stage==0:
                g.write('\t' + f"Recombinare dintre cromozomul {crom1 + 1} si cromozomul {crom2 + 1}\n")
            punct_rupere = random.randint(0, 21)
            if stage==0:
                g.write('\t' + f"{''.join(map(str, cromozomi[crom1]))} {''.join(map(str, cromozomi[crom2]))} punct {punct_rupere}\n")
            
            X,Y=incrucisare(cromozomi[crom1], cromozomi[crom2], punct_rupere)
            if stage==0:
                g.write('\t' + f"Rezultat {''.join(map(str, X))} {''.join(map(str, Y))}\n\n")
        
    elif lungime % 2 == 1 and lungime != 1:
        
        crom1 = cromozomiDeRecombinat[lungime - 3]
        crom2 = cromozomiDeRecombinat[lungime - 2]
        crom3 = cromozomiDeRecombinat[lungime - 1]

        aux1 = cromozomi[crom1]
        aux2 = cromozomi[crom2]
        aux3 = cromozomi[crom3]
        
        if stage==0:
            g.write('\t' + f"Recombinare dintre cromozomul {crom1 + 1} si cromozomul {crom2 + 1}\n")
        punct_rupere1 = random.randint(0, 21)
        if stage==0:
            g.write('\t' + f"{''.join(map(str, aux1))} {''.join(map(str, cromozomi[crom2]))} punct {punct_rupere1}\n")
        X,Y=incrucisare(aux1, cromozomi[crom2], punct_rupere1)
        if stage==0:
            g.write('\t' + f"Rezultat: {''.join(map(str, X))} {''.join(map(str, Y))}\n\n")
        
            g.write('\t' + f"Recombinare dintre cromozomul {crom2 + 1} si cromozomul {crom3 + 1}\n")
        punct_rupere2 = random.randint(0, 21)
        if stage==0:
            g.write('\t' + f"{''.join(map(str, aux2))} {''.join(map(str, cromozomi[crom3]))} punct {punct_rupere2}\n")
        X,Y=incrucisare(aux2, cromozomi[crom3], punct_rupere2)
        if stage==0:
            g.write('\t' + f"Rezultat: {''.join(map(str, X))} {''.join(map(str, Y))}\n\n")
            g.write('\t' + f"Recombinare dintre cromozomul {crom3 + 1} si cromozomul {crom1 + 1}\n")

        punct_rupere3 = random.randint(0, 21)
    
        X,Y=incrucisare(aux3, cromozomi[crom1], punct_rupere3)
        if stage==0:
            g.write('\t' + f"Rezultat: {''.join(map(str, X))} {''.join(map(str, Y))}\n\n")
    if stage==0:
        g.write("Dupa recombinare:\n\n")

    valoriCromozomi=[x + int(''.join(map(str, crom)), 2) * d for crom in cromozomi]
    valoriFunctie=[calculFunctie(crom,coef) for crom in valoriCromozomi]
    
    if stage==0:
        afisareCromozomi(g)
        g.write("\n") 
    
    #Mutatie------------------------------------------------------------------------------------
    
    if stage==0:
        g.write("Probabilitate de mutatie pentru fiecare gena: " + str(pm) + "\n\n")
        g.write("Au fost modificati cromozomii:\n")

    for i in range(1, numarCromozomi):
        mutant = mutatie(cromozomi[i], pm)
        if cromozomi[i] != mutant:
            if stage==0:
                g.write("\t" + str(i + 1) + "\n")
        cromozomi[i] = mutant
        
    if stage==0:
        g.write("\n")

    valoriCromozomi=[x + int(''.join(map(str, crom)), 2) * d for crom in cromozomi]
    valoriFunctie=[calculFunctie(crom,coef) for crom in valoriCromozomi]
    
    if stage==0:
        g.write("Dupa mutatie:\n\n")
        afisareCromozomi(g)

    #------------------------------------------------------------------------------------------

    mean_fit = meanFitness(valoriFunctie, numarCromozomi)
    pozitia_primului = primulCromozomPoz(valoriFunctie, numarCromozomi)

    cromozomi[0] = cromozomi[pozitia_primului]
    valoriFunctie[0] = valoriFunctie[pozitia_primului]
    valoriCromozomi[0] = valoriCromozomi[pozitia_primului]

    if stage==0:
        g.write("\nEvolutia maximului:\n\n")
    g.write("Max fitness " + "{:.2f}".format(valoriFunctie[0]) + ", Mean fitness " + "{:.2f}\n".format(mean_fit))

#------------------------------------------------------------------------------------------------

#Citire date
numarCromozomi, x, y, coef, precizie, pr, pm, stages = citireDateFisier()
l=calculLungime(x,y,precizie)
d=pasDiscretizare(x,y,l)
#

g=open("Evolutie.txt","w")
g.write("Populatia initiala\n")

cromozomi = [[random.randint(0, 1) for _ in range(l)] for _ in range(numarCromozomi)]
valoriCromozomi=[x + int(''.join(map(str, crom)), 2) * d for crom in cromozomi]
valoriFunctie=[calculFunctie(crom,coef) for crom in valoriCromozomi]
      
afisareCromozomi(g)

for stage in range(stages):
    solve(g,stage)

g.close()