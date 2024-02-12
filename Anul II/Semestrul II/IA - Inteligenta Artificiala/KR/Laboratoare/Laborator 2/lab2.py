class NodArbore:
    
    def __init__(self, info, parinte=None):
        self.info = info
        self.parinte = parinte

    def drumRadacina(self):
        l = []
        nod = self
        while nod is not None:
            l.insert(0, nod)
            nod = nod.parinte
        return l
    
    def vizitat(self):
        nod = self.parinte
        while nod is not None:
            if(nod.info == self.info):
                return True
            nod = nod.parinte
        return False
    

    # Exercitiul 3
    def afisSolFisier(self, f):
        
        drum = self.drumRadacina()
        
        for i in range(len(drum) - 1):
            nodCurent = drum[i]
            nodUrm = drum[i + 1]
            infoNodCurent = nodCurent.info
            infoNodUrm = nodUrm.info
            misCurent, canCurent, barcaCurent = infoNodCurent
            misUrm, canUrm, barcaUrm = infoNodUrm
            
            f.write(">>> Barca s-a deplasat de la malul ")
            if barcaCurent == 1:
                f.write("stang la malul drept ")
            else:
                f.write("drept la malul stang ")
                
            f.write(f"cu {abs(misUrm - misCurent)} misionari si {abs(canUrm - canCurent)} canibali.\n")
            f.write(f"(Stanga:{'' if barcaUrm == 1 else ''}{'barca' if barcaCurent == 1 else ''}) {misCurent} misionari {canCurent} canibali  ......  ")
            f.write(f"(Dreapta:{'barca' if barcaUrm == 1 else ''}{'' if barcaCurent == 1 else ''}) {misUrm} misionari {canUrm} canibali\n")
            f.write('\n')
    
    def __str__(self):
        return str(self.info)
    def __repr__(self):
        return "({}, {})".format(self.info, "->".join([str(x) for x in self.drumRadacina()]))
    
class Graf:

    def __init__(self, start, scopuri):
        self.start = start
        self.scopuri = scopuri

    def scop(self, informatieNod):
        return informatieNod in self.scopuri
    
    def succesori(self, nod):
        
        def test(m, c):
            return m == 0 or m >= c
        
        l = []
        if nod.info[2] == 1:  # malul initial = malul cu barca (curent)
            misMalCurent = nod.info[0]
            canMalCurent = nod.info[1]
            misMalOpus = Graf.N - nod.info[0]
            canMalOpus = Graf.N - nod.info[1]
        else:
            misMalOpus = nod.info[0]
            canMalOpus = nod.info[1]
            misMalCurent = Graf.N - nod.info[0]
            canMalCurent = Graf.N - nod.info[1]

        maxMisBarca = min(Graf.M, misMalCurent)
        for mb in range(maxMisBarca + 1):
            if mb == 0:
                minCanBarca = 1
                maxCanBarca = min(Graf.M, canMalCurent)
            else:
                minCanBarca = 0
                maxCanBarca = min(mb, Graf.M - mb, canMalCurent)
            for cb in range(minCanBarca, maxCanBarca + 1):
                misMalCurentNou = misMalCurent - mb
                canMalCurentNou = canMalCurent - cb
                misMalOpusNou = misMalOpus + mb
                canMalOpusNou = canMalOpus + cb
                if not test(misMalCurentNou, canMalCurentNou):
                    continue
                if not test(misMalOpusNou, canMalOpusNou):
                    continue

                if nod.info[2] == 1:
                    infoNod = (misMalCurentNou, canMalCurentNou, 0)
                else:
                    infoNod = (misMalOpusNou, canMalOpusNou, 1)

                nodNou = NodArbore(infoNod, nod)
                if not nodNou.vizitat():
                    l.append(nodNou)

        return l
    
def breadth_first(gr, nsol):
    c = [NodArbore(gr.start)]
    while c:
        nodcurent = c.pop(0)
        if(gr.scop(nodcurent.info)):
            print(repr(nodcurent))
            nsol -= 1
            if nsol == 0:
                return 
        c += gr.succesori(nodcurent)

#3 - bfs dar in loc sa afisezi adaugi in vector
def BFS_ex3(gr, nsol):
    c = [NodArbore(gr.start)]
    sol = []
    while c:
        nodcurent = c.pop(0)
        if(gr.scop(nodcurent.info)):
            sol.append(nodcurent)
            nsol -= 1
            if nsol == 0:
                return sol
        c += gr.succesori(nodcurent)
    return sol

f = open("input.txt","r")
continut = f.read().strip().split()
f.close()

Graf.N = int(continut[0])
Graf.M = int(continut[1])

start = (Graf.N, Graf.N, 1)
scopuri = [ (0, 0, 0) ]

gr = Graf(start, scopuri)

breadth_first(gr, 1)

# Exercitiul 3

g = open("rezultatEx3.txt", "w")
sol = BFS_ex3(gr, 1)[0]
sol.afisSolFisier(g)
g.close()