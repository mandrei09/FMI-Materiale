#scurta descriere a algoritmului + incadrare
#seminificatia variabilelor utilizate
def back(k,s):
    global ok
    if s==c:
        if x[1]==x[k-1]: #conditia pentru b
            print(*x[1:k])
            ok=1
    else:
        for i in range(1,c+1):
            x[k]=i
            s+=x[k]
            if abs(x[k-1]-x[k])<=p:
                if k!=c+1:
                    back(k+1,s)
            s-=x[k]


p,c=(int(i) for i in input().split())
x=[0 for i in range(c+2)]
ok=0
back(1,0)
if ok==0:
    print("Imposibil")
