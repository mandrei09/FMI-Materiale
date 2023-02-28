import heapq
h=[]
f=open("interclasare.in")
n=int(f.readline().rstrip("\n"))
for linie in f:
    for x in linie.split():
        heapq.heappush(h,int(x))
f.close()
print(h)

suma=0

while len(h)>0:
    x=heapq.heappop(h)
    if(len(h)==0):
        break
    y=heapq.heappop(h)
    suma+=x+y
    heapq.heappush(h,x+y)

print(suma)
