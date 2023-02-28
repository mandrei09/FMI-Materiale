a=int(input("a="))
b=int(input("b="))
f1=0
f2=1
f3=1
while not(a<=f3<=b):
    f1=f2
    f2=f3
    f3=f1+f2
print(f3)