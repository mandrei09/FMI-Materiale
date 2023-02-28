n=int(input("n="))
Max1=int(input())
Max2=Max1
for i in range(1,n):
    x=int(input())
    if x>Max1:
        Max2=Max1
        Max1=x
    else:
        if x>Max2:
            Max2=x
if Max1 != Max2:
    print(Max1, Max2)
else:
    print("Imposibil")
