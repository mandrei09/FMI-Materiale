import math

def calculFunctie(x):
    return a*x**2 + b*x + c 

def truncate(f, n):
    return math.floor(f * 10 ** n) / 10 ** n

f=open("input.txt","r")
a,b,c=[int(x) for x in f.readline().split()] # coeficientii functiiei de gradul 2
n=[int(x) for x in f.readline().split()][0] # dimensiunea populatiei de cromozomi
crom=[float(x) for x in f.readline().split()] # valoare decodificata a unui cromozom din populatie

# a,b,c=[int(x) for x in input().split()]
# n=[int(x) for x in input().split()][0]
# crom=[float(x) for x in input().split()]

fitness=[calculFunctie(x) for x in crom]
F=sum(fitness)

sumePartiale=[sum(fitness[:i+1])/F for i in range(0,len(fitness))]

sumePartiale.insert(0,0/F)

for suma in sumePartiale:
    print(truncate(suma,4))

# f.close()