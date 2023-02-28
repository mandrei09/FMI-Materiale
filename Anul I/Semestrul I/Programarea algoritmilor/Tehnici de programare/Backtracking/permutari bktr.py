def valid(k):
    if x[k] in x[:k]:
        return 0
    return 1
def back(k):
    if k==n+1:
        #pentru permutarile simple
        # print(x[1:],sep=", ")
        for i in range(1,n+1): #pentru anagrame
            print(litere[x[i]-1],end="")
        print()
        #
    else:
        for i in range(1,n+1):
            x[k]=i
            if valid(k):
                back(k+1)

cuvant=input()
litere=[]
litere.extend(cuvant)
print(litere)

n=len(cuvant)
x=[0 for i in range(n+1)]

back(1)