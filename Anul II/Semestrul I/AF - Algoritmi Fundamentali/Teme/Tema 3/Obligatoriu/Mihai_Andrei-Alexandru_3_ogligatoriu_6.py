def shortestCommonSupersequence(A,B):

        rezultat, i, j = "", 0, 0

            #intai se determina cea mai lunga secventa comuna a celor 2 cuvinte
        secventa=longestCommonSubsequence(A, B)

            #adaugam la rezultat din fiecare cuvant secventa diferita de litere diferita de 
            #litera curenta din cea mai lunga secventa comuna a celor 2 cuvinte
        for c in secventa:
            while A[i] != c:
                rezultat += A[i]
                i += 1
            while B[j] != c:
                rezultat += B[j]
                j += 1
            rezultat+=c; i+=1; j+=1
            #la final adaugam la rezultat ce a mai ramas din fiecare cuvant
        return rezultat + A[i:] + B[j:]

def longestCommonSubsequence(A,B):

        n, m = len(A), len(B)
        matrice = [["" for _ in range(m + 1)] for _ in range(n + 1)]

        for i in range(n):
            for j in range(m):
                if A[i] == B[j]:
                        #daca gasim o litera noua comuna o adaugam la string pe pozitia curenta in matrice
                    matrice[i + 1][j + 1] = matrice[i][j] + A[i]
                else:
                        #altfel adugam pe pozitia curenta stringul de lungime maxima
                    matrice[i + 1][j + 1] = max(matrice[i + 1][j], matrice[i][j + 1], key=len)

        return matrice[-1][-1]

print(len(longestCommonSubsequence("abcde","ace"))) #A

print(longestCommonSubsequence("abac","cab"))
print(shortestCommonSupersequence("abac","cab")) #B
