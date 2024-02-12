class NodArbore:
    def __init__(self, info, parinte=None,g=0,h=0):
        self.info = info
        self.parinte = parinte
        self.g=g
        self.h=h
        self.f=g+h

    def drumRadacina(self) :
        l=[]
        nod=self
        while nod is not None:
            l.insert(0,nod)
            nod=nod.parinte
        return l

    def vizitat(self) :
        nod=self.parinte
        while nod is not None:
            if nod.info==self.info:
                return True
            nod=nod.parinte
        return False

    def __str__(self):
        return str(self.info)

    def __repr__(self):
        return "({}, ({}))".format(self.info, "->".join([str(x) for x in self.drumRadacina()]))


class Graf:
    def __init__(self, matr, start, scopuri,h):
        self.matr=matr
        self.start=start
        self.scopuri=scopuri
        self.estimatii=h

    def scop(self, infoNod):
        return infoNod in self.scopuri

    def succesori(self, nod):
        l=[]
        for i in range(len(self.matr)):
            if self.matr[nod.info][i]>0:
                nodNou=NodArbore(i,nod,nod.g + self.matr[nod.info][i],self.calculeaza_h(i))
                if not nodNou.vizitat():
                    l.append(nodNou)
        return l

    def calculeaza_h(self,infonod):
        return self.estimatii[infonod]


def breadth_first(gr, nsol):
    c=[NodArbore(gr.start)]
    while c:
        nodCurent=c.pop(0)
        if gr.scop(nodCurent.info):
            print(repr(nodCurent))
            nsol-=1
            if nsol==0:
                return
        lSuccesori=gr.succesori(nodCurent)
        c+=lSuccesori
        
def aStarSolMultiple(gr, nsol):
    c=[NodArbore(gr.start)]
    while c:
        nodCurent=c.pop(0)
        if gr.scop(nodCurent.info):
            print(repr(nodCurent))
            nsol-=1
            if nsol==0:
                return
        lSuccesori=gr.succesori(nodCurent)
        for s in lSuccesori:
            indice=bin_search(c, s,0, len(c)-1)
            if indice==len(c):
                c.append(s)
            else:
                c.insert(indice, s)
 
def bin_search(listaNoduri, nodNou, ls, ld):
   if len(listaNoduri)==0:
       return 0
   if ls==ld:
       if nodNou.f<listaNoduri[ls].f:
           return ls
       elif nodNou.f>listaNoduri[ls].f:
           return ld+1
       else: # f-uri egale
           if nodNou.g < listaNoduri[ls].g:
               return ld + 1
           else:
               return ls
   else:
       mij=(ls+ld)//2
       if nodNou.f<listaNoduri[mij].f:
           return bin_search(listaNoduri, nodNou, ls, mij)
       elif nodNou.f>listaNoduri[mij].f:
           return bin_search(listaNoduri, nodNou, mij+1, ld)
       else:
           if nodNou.g < listaNoduri[mij].g:
               return bin_search(listaNoduri, nodNou, mij + 1, ld)
           else:
               return bin_search(listaNoduri, nodNou, ls, mij)
           
def astar(start, goal, graph, heuristic):
    open = [start]
    closed = set()
    g_scores = {start: 0}
    f_scores = {start: heuristic(start, goal)}

    while open:
        current = min(open, key=f_scores.get)
        if current == goal:
            path = [current]
            while current in graph:
                current = min(graph[current], key=g_scores.get)
                path.append(current)
            return path[::-1]

        open.remove(current)
        closed.add(current)

        for neighbor in graph.get(current, []):
            if neighbor in closed:
                continue

            g_score = g_scores[current] + 1
            if neighbor not in open or g_score < g_scores[neighbor]:
                g_scores[neighbor] = g_score
                f_scores[neighbor] = g_score + heuristic(neighbor, goal)
                if neighbor not in open:
                    open.append(neighbor)

    return None


m = [
    [0, 1, 0, 1, 1, 0, 0, 0, 0, 0],
    [1, 0, 1, 0, 0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 1, 0, 1, 0, 0],
    [1, 0, 0, 0, 0, 0, 1, 0, 0, 0],
    [1, 0, 0, 0, 0, 0, 0, 1, 0, 0],
    [0, 1, 1, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 0, 1, 0, 0, 0, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 0, 0]
]

m = [
[0, 3, 5, 10, 0, 0, 100],
[0, 0, 0, 4, 0, 0, 0],
[0, 0, 0, 4, 9, 3, 0],
[0, 3, 0, 0, 2, 0, 0],
[0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 4, 0, 5],
[0, 0, 3, 0, 0, 0, 0],
]
start = 0
scopuri = [4,6]
h=[0,1,6,2,0,3,0]

gr=Graf(m, start, scopuri,h)
breadth_first(gr,3)