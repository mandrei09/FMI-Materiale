# f=open("input.txt","r")
# l,k=[int(x) for x in f.readline().split()] # dimensiunea cromozomilor 
# c=int(f.readline().strip(),2)
# biti=[int(x) for x in f.readline().split()]
# f.close()

l,k=[int(x) for x in input().split()] # dimensiunea cromozomilor 
c=int(input().strip(),2)
biti=[int(x) for x in input().split()]

transBiti=[l-1-bit for bit in biti]

masca=0
for bit in transBiti:
    if (1<<bit)&masca!=(1<<bit):
        masca+=1<<bit
    else:
        masca-=1<<bit

print("{:0>{}}".format(str(bin(c^masca)[2:]),l))