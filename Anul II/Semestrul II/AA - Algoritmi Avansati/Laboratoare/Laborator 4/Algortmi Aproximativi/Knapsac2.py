with open("date.in", "r") as fin:
    k = int(fin.readline().strip())
    sol = 0

    for line in fin:
        x = int(line.strip())
        if sol + x <= k:
            sol += x
        else:
            sol = max(sol, x)
        print(sol)

print(sol)
