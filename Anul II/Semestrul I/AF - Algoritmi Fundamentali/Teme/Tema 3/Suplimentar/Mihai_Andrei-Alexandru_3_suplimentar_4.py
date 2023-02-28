#DFS------------------------------------------------
def dfs(s):
    global pasi
    while len(adiacenta[s]):
        nodUrmator,indiceDrumUrmator = adiacenta[s].pop()
        if viz[indiceDrumUrmator]==0:
            viz[indiceDrumUrmator]=1
            dfs(nodUrmator)
    if s==0:
        #Daca ajungem la nodul de inceput,inseamna 
        #ca vom merge pe un alt drum.
        pasi+=1
    else:
        drumuri[pasi].append(s)
        
#---------------------------------------------------

#CITIRE DATE----------------------------------------
f=open("johnie.in")
n,m=[int(x) for x in f.readline().split()]

adiacenta=[[] for _ in range(n+1)]
viz=[0 for _ in range(2*n+1)]
pasi=0
drumuri=[[] for i in range(n+1)]
#CREEARE LISTE DE ADIACENTA-------------------------
for i in range(m):
    x,y=[int(z) for z in f.readline().split()]
    adiacenta[x].append((y,i))
    adiacenta[y].append((x,i))
f.close()
#---------------------------------------------------

#Selectam doar nodurile cu numar impar de adiacenti
#deoarece ar putea reprezenta un capat de drum.
for i in range(1,n+1):
    if len(adiacenta[i])%2:
        adiacenta[0].append((i,i+m))
        adiacenta[i].append((0,i+m))

dfs(0) #consideram cautarea din nodul 0

#AFISAREA SOLUTIEI----------------------------------
g=open("johnie.out","w")
g.write(str(pasi-1)+"\n")
for i in range(1,pasi):
    g.write(str(len(drumuri[i]))+" ")
    for j in range(len(drumuri[i])):
        g.write(str(drumuri[i][j])+" ")
    g.write("\n")
g.close()
#---------------------------------------------------