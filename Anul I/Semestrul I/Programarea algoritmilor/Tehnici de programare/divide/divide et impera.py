import random
def f2(v, p, u):
    if u == p:
        return v[p]
    else:
        m = (p + u) // 2
        x = random.randint(0,2)
        if x==1:
            return f2(v, m + 1, u)
        else:
            return f2(v, p, m)

def f(v, p, u):
    if u == p:
        return v[u]
    else:
        m = (p+u)//2
        s1 = f(v, p, m)
        s2 = 0
        for i in range(m+1, u+1):
            s2 = s2 + v[i]
        return s1 + s2

def DI_max(x,s,d):
    if s==d:
        return x[s]
    else:
        m=(s+d)//2
        Max1=DI_max(x,s,m); Max2=DI_max(x,m+1,d)
        if Max1>Max2:
            return Max1
        else:
            return Max2
def DI_sum(x,s,d):
    if s==d:
        return x[s]
    else:
        m=(s+d)//2
        suma1=DI_sum(x,s,m); suma2=DI_sum(x,m+1,d)
    return suma1+suma2

def inter(x,i,j):
    x[i],x[j]=x[j],x[i]

def pivot(x,p,u):
    i=p
    j=u
    ok=0
    while i!=j:
        if ok==0:
            if x[j]<x[i]:
                inter(x,i,j)
                i,j=j,i
                ok=1
            else:
                j-=1
        else:
            if x[j]>x[i]:
                inter(x,i,j)
                i,j=j,i
                ok=0
            else:
                j+=1
    return i

def quicksort(x,s,d):
    if s>=d:
        return 
    m=pivot(x,s,d)
    quicksort(x,s,m-1)
    quicksort(x,m+1,d)

x=[1,2,3,4,5]
# print(DI_max(x,0,11))
# print(DI_sum(x,0,11))
#quicksort(x,0,len(x)-1)
# print(x)
# print(pivot(x,0,6))
print(f2(x,0,len(x)-1))

