def valid(k):
    if x[k] in x[:k]:
        return 0
    return 1

def back(k):
    if k==m+1:
        print(x[1:],sep=", ")
    else:
        for i in range(1,n+1):
            x[k]=i
            if valid(k):
                back(k+1)
#sau

def combinari(k):
    if k==m+1:
        print(x[1:],sep=", ")
    else:
        for i in range(x[k-1]+1,n+1):
            x[k]=i
            combinari(k+1)
        
n,m=input().split()
n=int(n)
m=int(m)
x=[0 for i in range(m+1)]
#back(1)
combinari(1)