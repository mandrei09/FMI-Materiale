# Vectorul 'multime' are semnificatia unui vector de reprezentanti, astfel pentru
# a verifica daca doua noduri fac parte din aceeasi multime vom verifica daca au acelasi 'capat'
# al multimii. 
# Pentru a reuni multimile a 2 noduri vom spune ca acum ambele multimi au acelasi
# capat, actualizand lista 'multime' pentru capetele multimilor.

#Functie care returneaza reprezentul lui x 
def operatie(x):
    if multime[x]==x:
        return x
    multime[x]=operatie(multime[x])
    return multime[x]

f=open("disjoint.in")
g=open("disjoint.out","w")

n,m=[int(x) for x in f.readline().split()]
multime=[int (i) for i in range(n+1)]

for i in range(m):

    cod,x,y=[int(i) for i in f.readline().split()]

    if cod==1: #operatia de reuniune, practic setam reprezentantul

        multime[operatie(y)]=operatie(x)

    elif cod==2:

        #Apartin de aceeasi multime daca au acelasi tata
        if(operatie(x)==operatie(y)):

            g.write("DA"+"\n")

        else:

            g.write("NU"+"\n")
            
f.close()
g.close()