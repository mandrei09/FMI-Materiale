def suma_cifre(x):
    s=0
    while x:
        s+=x%10
        x//=10
    return s

def cifra_control(n):
    while n>9:
        n=suma_cifre(n)
    return n
    #sau return n%9 direct

def insereaza_cifra_control(lista):
    i=0
    lungime=len(lista)
    for element in range(lungime):
        lista.insert(i+1,cifra_control(lista[i]))
        i+=2
    return lista

lis=[312414,124125,123124,5342,1325]
print(insereaza_cifra_control(lis))