n=int(input("N="))
i=1
while(i<(1<<n)):
    nr=0
    aux=i
    while (aux!=0):
        nr=nr+1
        if aux&1==1:
            print(nr, end=' ')
        aux = aux >> 1
    print('\n')
    i=i+1