#scurta descriere a algoritmului + incadrare
#corectitudinea + timpul de executare
#seminificatia variabilelor utilizate

""" 
n=int(input())
g=float(input())
greutati=[float(i) for i in input().split()]

print(n,g,greutati) """

n=10
g=8.5
greutati=[8.5,21.25,12,6.05,20.7,23.8,22,33.25,21,48.15,62.20]
greutati.sort()
nr=0 #numarul de perechi
indici=[] #multimea indicilor care trebuie afisati la final
i=0
while i<n:
    if abs(greutati[i]-greutati[i+1])<=g:
        nr+=1
        indici.append(i)
        i+=1
    i+=1
print(greutati)
print(nr)
for indice in indici:
    print(indice,indice+1,sep=" + ")
