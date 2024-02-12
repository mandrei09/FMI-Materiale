# f=open("input.txt","r")
# l=[int(x) for x in f.readline().split()][0] # dimensiunea cromozomilor 
# x1=f.readline().strip()
# x2=f.readline().strip()
# i=[int(x) for x in f.readline().split()][0]

l=[int(x) for x in input().split()][0] # dimensiunea cromozomilor 
x1=input()
x2=input()
i=[int(x) for x in input().split()][0]

# f.close()

newX1=x1[:i]+x2[i:]
newX2=x2[:i]+x1[i:]

print(newX1,newX2,sep="\n")