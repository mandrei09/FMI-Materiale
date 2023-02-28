a=int(input())
b=int(input())
#crescator
for i in range(5,96,5):
    if not(a<i<b):
        print(i,end=" ")
#descrescator
print('\n')
for i in range(95,4,-5):
    if not(a<i<b):
        print(i,end=" ")