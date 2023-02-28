p=input()
k=int(input())
L=len(p)
for i in range(L):
    if 'a'<=p[i]<='z':
        if ord(p[i])+k<=ord("z"): 
            print(chr(ord(p[i])+k),sep="",end="")
        else:
            print(chr(ord('a')+k-(ord('z')-ord(p[i])+1)),sep="",end="")
    elif 'A'<=p[i]<='Z':
        if ord(p[i])+k<=ord("Z"):
            print(chr(ord(p[i])+k),sep="",end="")
        else:
            print(chr(ord('A')+k-(ord('Z')-ord(p[i]))),sep="",end="")
    else:
        print(p[i],sep="",end="")
        