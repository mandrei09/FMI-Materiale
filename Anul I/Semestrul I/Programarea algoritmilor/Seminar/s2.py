#a)
def frecventa(s):
    frecv={}
    f=open(s)
    linie=f.readline()
    while linie!="":
        caractere= [x for x in linie]
        for c in caractere:
            if c in frecv:
                frecv[c]+=1
            else:
                frecv[c]=1
        linie=f.readline()
    f.close()
    return frecv 

#b)
fv1=frecventa("caractere1.in")
fv2=frecventa("caractere2.in")
print("b) Frecventa caracterelor din cele 2 fisiere este:")
print(fv1)
print(fv2)
print('\n')
#c)
c1=set(fv1)
c2=set(fv2)
print("Caracterele comune celor doua fisiere sunt:")
c=c1 & c2
print(c)
for c in fv1.keys():
    print(c,':',fv1[c],end=" , ")



