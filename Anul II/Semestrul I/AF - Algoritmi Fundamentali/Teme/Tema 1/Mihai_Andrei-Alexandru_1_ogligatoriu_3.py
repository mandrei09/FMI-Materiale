def cheie(x):
    return -x[2]

numCourses=4 #numarul de noduri
prerequisites = [[1,0],[2,0],[3,1],[3,2]] 
adiacente=[]

#formam listele de adiacenta
for i in range(numCourses):
    adiacente.append([])
for muchie in prerequisites:
    adiacente[muchie[1]].append(muchie[0])

grad=[]
for i in range(numCourses):
    grad.append((i,adiacente[i],len(adiacente[i])))

print(grad)

grad=sorted(grad,key=cheie)

print(grad)

for nod in grad:
    print(nod[0],end=" ")


