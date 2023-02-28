p=input()
l=len(p)
nr=0
s=0
a='1234567890'
for i in range(l):
    if p[i] in a:
        nr=nr*10+int(p[i])
    else: 
        s+=nr
        nr=0
print(s)