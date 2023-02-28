def back(k):
    global s
    if s==n:
        print(*x[1:k])
    else:
        for i in range(1,t+1):
            x[k]=i
            s+=x[k]
            if s<=n and x[k]<=x[k-1]:
                back(k+1)
            s-=x[k]

n,t=(input().split())
n=int(n)
t=int(t)
s=0
x=[0 for i in range(n+1)]
x[0]=t+1
back(1)

#pentru b) se adauga x[k]<=x[k-1] la conditie + x[0]=t+1