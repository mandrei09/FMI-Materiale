x=int(input("x="))
y=x
if x&x-1==0:
    print("Putere a lui 2 ")
    k = 0
    while (x & 1 != 1):
        k = k + 1
        x=x>>1
    print(y, "este de forma 2 la",k)
else:
    print("Nu este putere a lui 2")
