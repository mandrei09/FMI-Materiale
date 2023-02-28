s=input()
v="aeiouAEIOU"
#determin pozitia primei vocale
l=len(s)
for i in range(l):
    if s[i] in v:
        k=i
        break
s=s[:k]+s[k+1:]
print(s)