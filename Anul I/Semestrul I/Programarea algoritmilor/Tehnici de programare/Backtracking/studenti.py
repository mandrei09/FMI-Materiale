def back(k):
    if k==s+1: 
        if x[s//2]<=nrf and x[s//2+1]>nrf:
            if x[1]==1 and x[s//2+1]==nrf+1: #conditia pentru b
                print(*x[1:],sep=", ")
    else:
        for i in range(x[k-1]+1,lungime):
            x[k]=i
            back(k+1)
        

nrf,nrb,s=input().split()
nrf=int(nrf)
nrb=int(nrb)
s=int(s)
lungime=nrf+nrb+1
x=[0 for i in range (s+1)]
back(1)
