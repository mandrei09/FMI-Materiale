#nu am mai facut input de la tastatura sau din fisier
a=[3, -2, 5, -1, 4]
b=[7,8,-5,2,-4,-1,5]
a.sort()
b.sort()
#algoritmul va avea complexitate O(n logn) datorita sortarii
la=len(a); la-=1
lb=len(b); lb-=1
j=0; i=0
s=0
#parcurgem doar elementele lui a (m<=n)
while i<=la:
    if a[i]<0:
        if b[j]<0: #daca ambele elemente sunt negative, facem produsul deoarece este garantat maxim conform sortarii
            s+=a[i]*b[j]
            i+=1
            j+=1
        else: #a[i]<0 b[i]>0 ==> i++, produsul va fii negativ, deci va micsora suma
            i+=1
    else:
        if b[j]<0:
            j+=1 #acelasi caz ca la comentariul de sus
        else:
            #ambele elemente sunt pozitive.
            #pentru a maximiza produsul trebuie sa inmultim elementul a[i] cu corespondentul b[j] de pozitie maxima astfel incat urmatoarele elemente i sa ramana fiecare cu un corespondent j.
            rest_a=la-i+1 ; rest_b=lb-j+1
            if rest_a==rest_b: #daca restul de elemente ramase sunt egale, produsele a[i]*b[j] vor fii maxime
                s+=a[i]*b[j]
                i+=1
                j+=1
            else: #daca nu sunt egale, facem ce am spus acum 2 comentarii
                while rest_a!=rest_b:
                    j+=1
                    rest_b-=1
print(s)


    
