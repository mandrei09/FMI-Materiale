p=input()
s=input()
a=[0 for i in range(0,26)]
b=[0 for i in range(0,26)]
Lp=len(p)
Ls=len(s)
for i in range(0,Lp):
    a[ord(p[i])-ord('a')]+=1
for i in range(0,Ls):
    b[ord(s[i])-ord('a')]+=1
ok=0
for i in range(26):
    if a[i] != b[i]:
        ok=1
        break 
if ok==1:
    print("Nu sunt anagrame")
else:
    print("Sunt anagrame")