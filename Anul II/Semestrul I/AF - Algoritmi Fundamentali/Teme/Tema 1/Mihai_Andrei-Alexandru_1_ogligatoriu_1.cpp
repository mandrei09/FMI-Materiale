//Pentru aceasta problema vom verifica daca un graf este bipartit, practic daca nodurile sale se pot 
//imparti in 2 multimi distinte.
//Abordare este urmatoarea : avem o parcurgere obisnuita (BFS) doar ca mai avem in plus vectorul CULORI.
//Practic, se parcurge prin BFS graful, in momentul cand se viziteaza un nod, il "vopsim" intr-o culoare
//(notez valoarea 1 in vectorul de culori cu rosu si 2 cu albastru). Revenind, vopsim nodul intr-o culoare
//sa zicem rosu, apoi toti vecinii sai ii vopsim in cealalta culoare (albastru), si tot asa. Daca la un moment
//dat vom da de 2 noduri vecine avand aceeasi culoare, graful nu este bipartit deci raspunsul pentru problema
//este fals, in caz contrar este adevarat.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

    //n si dislikes sunt datele de intrare
    bool possibleBipartition(int n, vector<vector<int>> &dislikes) 
    {
        vector<vector<int>> adiacente(n + 1);  //un vector care contine pentru fiecare nod o lista cu nodurile adiacente lui
        vector<int> culori(n + 1, 0);  //vectorul de culori de care vorbeam mai sus
        vector<int> vizitate(n + 1, 0);  //vectorul prin care verificam daca un nod a fost vizitat sau nu

        //b
        vector <int> grup1,grup2;

        for (auto &dislike : dislikes) //parcurgem fiecare muchie
        {
            int u = dislike[0];
            int v = dislike[1];
            adiacente[u].push_back(v);
            adiacente[v].push_back(u);

            //si formam listele de adiacenta
        }
      
        //declaram o coada pentru BFS
        queue <int> coada;
        
        //parcurgem toate nodurile
        for (int i = 1; i <= n; ++i)
        {
            //daca nodul i nu este vizitat
            if (!vizitate[i])
            {
                //il coloram intr-o culoare si il punem in coada
                culori[i] = 1; grup1.push_back(i);
                coada.push(i);
                
                // BFS
                while (!coada.empty())
                {
                    int u = coada.front();
                    coada.pop();
                    
                    if (vizitate[u])
                    {
                        continue;
                    }
                    
                    //vizitam
                    vizitate[u] = 1;
                    
                    // pentru fiecare vecin al nodului curent
                    for (auto adiacent: adiacente[u])
                    {
                        //daca intalnim 2 vecini cu aceeasi culoare deja am terminat, graful nu este bipartit
                        if (culori[adiacent] == culori[u])
                        {
                            return false;
                        }
                        
                        //in caz contrar coloram in culoarea opusa celei pe care o are nodul curent
                        if (culori[u] == 1)
                        {
                            if(vizitate[adiacent]==0)
                                grup2.push_back(adiacent);
                            culori[adiacent] = 2;
                        }
                        else 
                        {
                            if(vizitate[adiacent]==0)
                                grup1.push_back(adiacent);
                            culori[adiacent] = 1;
                        }
                        
                        //punem vecinii pe coada si se reia loop-ul
                        coada.push(adiacent);
                    }
                }
            }
        }
        //b
        for (int i=0;i<grup1.size();i++)
            cout<<grup1[i]<<' ';
        cout<<endl;
        for (int i=0;i<grup2.size();i++)
            cout<<grup2[i]<<' ';
        cout<<endl;
        return true;
    }

int numarNoduri;
vector<vector<int>> muchii;

int main(){
    
    numarNoduri=4;
    muchii={
        {1,2},
        {1,3},
        {2,4}
    };
    cout<<possibleBipartition(numarNoduri,muchii);
}