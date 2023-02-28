p = input()
l = len(p)
nr=0
a='1234567890'
for i in range(0,l):
    if (p[i] in a)==True:
        nr=nr*10+int(p[i])
    else:
        for j in range(0, nr):
            print(p[i], end="")
        nr=0