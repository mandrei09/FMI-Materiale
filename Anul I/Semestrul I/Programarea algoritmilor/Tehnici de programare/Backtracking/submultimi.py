def back(k):
    if k==n+1:
        for i in range(1,n+1):
            if x[i]==1:
                print(m[i-1],end=" ")
        print()
    else:
        for i in range(0,2):
            x[k]=i
            back(k+1)
    
m=[1,6,16,34,1]
n=len(m)
x=[0 for i in range(n+1)]
back(1)

