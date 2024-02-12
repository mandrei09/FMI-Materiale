def rucsac(greutati, preturi, capacitate):
    #matrice care retine valoarea maxima pentru fiecare subproblema
    dp = [[0] * (capacitate + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for g in range(1, capacitate + 1):
            #dorim sa adaugam obiecte cat mai valoroase, de greutate cat mai mica
            if greutati[i - 1] <= g:
                dp[i][g] = max(preturi[i - 1] + dp[i - 1][g - greutati[i - 1]], dp[i - 1][g])
            else:
                dp[i][g] = dp[i - 1][g]
    # print(dp)
    return dp[n][capacitate]


# f=open("input.txt")
# n,c=[int(x) for x in f.readline().split()]
# preturi=[int(x) for x in f.readline().split()]
# greutati=[int(x) for x in f.readline().split()]
# f.close()

n,c=[int(x) for x in input().split()]
preturi=[int(x) for x in input().split()]
greutati=[int(x) for x in input().split()]

# print(preturi,greutati,sep="\n")

print(rucsac(greutati,preturi,c))