s=input()
k=int(input())
#1 prin copiere
t=""
l=len(s)
for i in range(l):
    if i!=k:
        t+=s[i]
print(t)
#2 prin feliere
s=s[:k]+s[k+1:]
print(s)