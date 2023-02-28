from collections import Counter
from collections import defaultdict

def validArrangement(pairs):

    g = defaultdict(list)  # structura de date in care vom memora graful
    din, dout = Counter(), Counter()  #pentru fiecare nod, retine gradul interior si exterior

    #formam listele de adiacenta
    for u, v in pairs:
        g[u].append(v)
        dout[u] += 1
        din[v] += 1

    start = pairs[0][0]  
    for p in dout:
        if dout[p] - din[p] == 1:  # Cautam un nod de start (din care doar pleca un arc)
            start = p
            break
    
    #Dupa ce l-am gasit aplicam Algoritmul lui Hierholzer:
    lant = []
    st = [start]
    while st:
        while g[st[-1]]:
            st.append(g[st[-1]].pop())
        lant.append(st.pop())
    #Deoarece scoatem cate un nod din listele de adiacenta dupa ce il vizitam, vom obtine un lant eulerian
    lant.reverse()

    #Returnam lista perechilor
    return [[lant[i], lant[i+1]] for i in range(len(lant)-1)]

pairs = [[5,1],[4,5],[11,9],[9,4]]
print(validArrangement(pairs))