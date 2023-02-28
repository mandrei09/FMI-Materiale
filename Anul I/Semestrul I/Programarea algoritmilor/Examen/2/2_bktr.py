def valid(k):
    if x[k] in x[1:k]:
        return 0
    return 1
def back(k):
    for h in range(i,j+1):
        x[k]=h
        if valid(k):
            if x[1]==j: #pentru b
                print(*x[1:k+1])
            if k!=j-i+1:
                back(k+1)
            

i,j=(input().split())
i=int(i)
j=int(j)
x=[i-1 for k in range (0,j-i+2)]
back(1)