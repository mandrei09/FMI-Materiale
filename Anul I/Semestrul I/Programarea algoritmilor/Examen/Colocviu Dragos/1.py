def key1(x):
    return x[1]

def key2(x):
    return x[0]

f=open("numere.in","r")
numere=[]
for linie in f:

    for element in linie.split():
        numarNou=""
        nr=0
        for i in range(0,len(element)-1):
            if element[i]>=element[i+1]:
                numarNou+=element[i]
            else:
                numarNou=numarNou+element[i]+"-"
                nr+=1
        numarNou+=element[len(element)-1]
        numere.append((numarNou,nr+1))

f.close()

numere=sorted(numere,key=key1)

g=open("numere.out","w")
index=0

print(numere)

for numar in numere:
    if numar[1]!=index:
        if(index!=0):
            g.write('\n')
        g.write(str(numar[1])+" parti:")
        g.write('\n')
        index+=1
    g.write(numar[0])
    g.write(", ")
g.close()