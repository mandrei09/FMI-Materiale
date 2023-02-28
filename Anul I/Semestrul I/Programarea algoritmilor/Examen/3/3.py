def back(k,s):
    if k==m+1:
        if s==n:
            if(x[1]==c[1]):
                print(*x[1:],sep=" ,")
    else:
        for i in range(1,c[k]+1):
            x[k]=i
            s+=x[k]
            back(k+1,s)
            s-=x[k]
            
n,m=(int (i) for i in input().split())
c=[int(i) for i in input().split()]
c.insert(0,-1)
x=[0 for i in range(m+1)]
back(1,0)
