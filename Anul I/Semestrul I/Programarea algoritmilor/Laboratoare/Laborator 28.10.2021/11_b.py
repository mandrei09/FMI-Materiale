p=input()
L=len(p)
#cu cratima
i=0
while i<L-1:
    print(p[i],sep="",end="")
    if p[i+1]=='-' or p[i+1]==' ':
        print('p',p[i],sep="",end="")
    i+=1
print(p[L-1],'p',p[L-1],sep="",end="")
#fara cratima
print('\n')
i=0
while i<L-1:
    if p[i]!='-':
        print(p[i],sep="",end="")
    if p[i+1]=='-':
        print('p',p[i],sep="",end="")
        i+=1
    elif p[i+1]==' ':
        print('p',p[i],sep="",end="")
    i+=1
print(p[L-1],'p',p[L-1],sep="",end="")