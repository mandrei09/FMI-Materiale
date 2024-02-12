import math

f=open("input.txt","r")
a,b=[int(x) for x in f.readline().split()] #capetele intervalului dat
p=[int(x) for x in f.readline().split()][0] # pricizia
m=[int(x) for x in f.readline().split()][0] # numarul de teste

# a,b=[int(x) for x in input().split()]
# p=[int(x) for x in input().split()][0]
# m=[int(x) for x in input().split()][0]

l=math.ceil(math.log2((b-a)*(10**p))) #numarul de biti necesar pentru a codifica numerele din [a,b]
d=(b-a)/(2**l) #pasul de discretizare

#generarea intervalelor
intervale=[float(a)]
i=0
while intervale[i]<b:
    intervale.append(intervale[i]+d)
    i+=1

#parcurgem testele
for _ in range(m):
    tipTest=f.readline().strip()
    valoare=f.readline().strip()
    # tipTest=input()
    # valoare=input()
    if tipTest=="TO": #convertim la float 
        valoare=float(valoare)
        for i in range(len(intervale)):
            if intervale[i]<=valoare<intervale[i+1]:
                print(format(i,"0"+str(l)+"b")) #afisam in binar 
                break
    else:
        valoare=int(valoare,2) #afisam capatul din stanga al intervalului din care face parte
        print(intervale[valoare])
    
# f.close()