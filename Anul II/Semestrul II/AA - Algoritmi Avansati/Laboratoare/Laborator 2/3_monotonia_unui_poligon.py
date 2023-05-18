def xMonotone(puncte):
    #Gasim pozitia punctului cu x minim
    xmin=puncte[0][0]
    for punct in puncte:
        if punct[0]<xmin:
            xmin=punct[0]

    for i in range(n):
        if puncte[i][0]==xmin:
            xMinPoz=i
    
    ok=0
    punctCurent=puncte[xMinPoz][0]
    
    #Parcurgem punctele de la cel cu x minim pana la ultimul punct
    for i in range(xMinPoz+1,n):
        #Daca x-ul creste, este ok. In schimb daca acesta scade, prima data semnalizam acest lucru.
        if puncte[i][0]<punctCurent:
            if ok==0:
                ok=1
        #Daca x-ul a crescut dupa ce a scazut, poligonul nu este x monoton.
        elif puncte[i][0]>punctCurent and ok==1:
            return 0
        punctCurent=puncte[i][0]
        
    punctCurent=puncte[xMinPoz][0]
    
    #Parcurgem punctele de la cel cu x minim pana la primul punct si verificam acelasi lucru ca mai sus.
    for i in reversed(range(0,xMinPoz-1)):
        if puncte[i][0]<punctCurent:
            if ok==0:
                ok=1
        elif puncte[i][0]>punctCurent and ok==1:
            return 0
        punctCurent=puncte[i][0]
    
    return 1 

#Pentru y monotonie se verifica acelasi lucru.
def yMonotone(puncte):
    #Gasim pozitia punctului cu y minim
    ymin=puncte[0][1]
    for punct in puncte:
        if punct[1]<ymin:
            ymin=punct[1]

    for i in range(n):
        if puncte[i][1]==ymin:
            yMinPoz=i
    
    ok=0
    punctCurent=puncte[yMinPoz][1]
    
    for i in range(yMinPoz+1,n):
        if puncte[i][1]<punctCurent:
            if ok==0:
                ok=1
        elif puncte[i][1]>punctCurent and ok==1:
            return 0
        punctCurent=puncte[i][1]
        
    punctCurent=puncte[yMinPoz][1]
    
    for i in reversed(range(0,yMinPoz-1)):
        if puncte[i][1]<punctCurent:
            if ok==0:
                ok=1
        elif puncte[i][1]>punctCurent and ok==1:
            return 0
        punctCurent=puncte[i][1]
    
    return 1 

#Input
n = int(input())
puncte = []
for _ in range(n):
    x, y = [int(z) for z in input().split()] 
    puncte.append((x,y))
    
#Output-ul corespunzator pentru fiecare caz.
if xMonotone(puncte)==1:
    print("YES")
else:
    print("NO")
    
if yMonotone(puncte)==1:
    print("YES")
else:
    print("NO")

