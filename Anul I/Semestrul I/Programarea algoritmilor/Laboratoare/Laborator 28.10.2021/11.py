p=input()
L=len(p)
v='AEIOUaeiou'
i=0
while i<L:
    if (p[i] in v) == True:
        if p[i+1]=='p' or p[i+1]=='P':
            print(p[i],sep="",end="")
            i+=2
    else:
        print(p[i],sep="",end="")
    i+=1
