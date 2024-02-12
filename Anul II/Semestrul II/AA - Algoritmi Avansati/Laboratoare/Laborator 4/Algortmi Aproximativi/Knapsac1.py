def max_sum(k, elemente):
    total = 0
    sume = set()
    sume.add(0)

    for valoare in elemente:
        sumeCopy = set(sume)

        for suma in sumeCopy:
            print(sumeCopy)
            if suma + valoare <= k:
                total = max(total, suma + valoare)
                print(total)
                sume.add(suma + valoare)

    return total


print(max_sum(20,[1,5,7,2]))
