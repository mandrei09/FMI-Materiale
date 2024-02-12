# Sortam obiectele DESC dupa raportul valoare/greutate
# luam obiectele in ordinea asta si din ultimul obiect luam doar cat mai incape

def cheie(x):
    return -x[0]/x[1]

# f=open("input.txt")
# n,c=[int(x) for x in f.readline().split()]
# v=[int(x) for x in f.readline().split()]
# g=[int(x) for x in f.readline().split()]
# f.close()

n,c=[int(x) for x in input().split()]
v=[int(x) for x in input().split()]
g=[int(x) for x in input().split()]

obiecte=[]

for i in range(len(v)):
    obiecte.append((v[i],g[i]))

obiecte.sort(key=cheie)

# print(n,c,obiecte)

valoareMaxima=0

for obiect in obiecte:
    if obiect[1]<=c:
        valoareMaxima+=obiect[0]
        c-=obiect[1]
    else:
        valoareMaxima+=c*obiect[0]/obiect[1]
        break
        
print("{:.4f}".format(valoareMaxima))