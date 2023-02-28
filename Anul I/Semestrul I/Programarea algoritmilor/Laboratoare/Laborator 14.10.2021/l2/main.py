n=int(input("n="))
i=2
x=float(input())
Max=0.0
while i<=n:
    y = float(input())
    d=y-x
    if d>Max:
        Max=d
        p=i
    i+=1
Max="{:.2f}".format(Max)
print(Max,p,p-1)