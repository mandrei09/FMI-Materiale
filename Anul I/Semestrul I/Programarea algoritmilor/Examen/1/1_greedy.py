valori=[1,2,3,-4,5,6]
p=1
for numar in valori:
    if numar<0: 
        Max=numar
for numar in valori:
    p*=numar
    if numar>Max and numar<0:
        Max=numar
if p>=0:
    print(p)
else:
    print(p//Max)