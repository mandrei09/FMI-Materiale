s=int(input("Suma="))
bancnote=(1,5,10,25)
i=3
while s!=0:
    if s>=bancnote[i]:
        nr=s//bancnote[i]
        print(nr,'x',bancnote[i])
        s=s-bancnote[i]*nr
    else:
        i-=1

