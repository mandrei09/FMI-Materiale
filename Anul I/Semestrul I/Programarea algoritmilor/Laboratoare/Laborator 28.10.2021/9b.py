p=input()
k=int(input())
L=len(p)
for i in range(L):
    if 'a'<=p[i]<='z':
        if ord(p[i])-k>=ord("a"): 
            print(chr(ord(p[i])-k),sep="",end="")
        else:
            print(chr(ord('z')-(k-(ord(p[i])-ord('a')+1))),sep="",end="")
    elif 'A'<=p[i]<='Z':
        if ord(p[i])-k>=ord("A"):
            print(chr(ord(p[i])-k),sep="",end="")
        else:
            print(chr(ord('Z')-(k-(ord(p[i])-ord('A')+1))),sep="",end="")
    else:
        print(p[i],sep="",end="")