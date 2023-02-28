""" 1. Cuburi. Se dau n cuburi cu laturile diferite două câte două. Fiecare cub are o culoare, codificată cu
un număr de la 1 la p (p dat).
a) Să se construiască un turn de înălțime maximă de cuburi în care un cub nu poate fi așezat pe un cub
de aceeași culoare sau cu latură mai mică decât a sa - O(n logn). Pe prima linie a fișierului de intrare
se dau n şi p, iar pe următoarele linii latura şi culoarea fiecărui cub. În fișierul de ieșire se vor afișa
înălțimea turnului obținut şi indicele cuburilor folosite (de la bază la vârf)
"""

f=open("date.in")
n,p=f.readline().split()
n=int(n)
p=int(p)

cuburi=[]
i=1
for linie in f:
    split=linie.split()
    cub=(int(split[0]),int(split[1]),i)
    cuburi.append(cub)
    i+=1
f.close()
cuburi=sorted(cuburi,reverse=True)

split=[cuburi[0][2]]
h=cuburi[0][0]
cub=1
lungime=len(cuburi)
while cub<=lungime-1:
    if cuburi[cub][1]!=cuburi[cub-1][1]:
        h+=cuburi[cub][0]
        split.append(cuburi[cub][2])
    cub+=1

print(cuburi)
print(h)
print(*split)