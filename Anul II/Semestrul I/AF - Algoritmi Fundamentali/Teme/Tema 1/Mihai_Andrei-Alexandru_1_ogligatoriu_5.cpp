#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

    // int numarNoduri=9;
    // vector<vector<int>> muchii={
    //     {1,2},
    //     {1,3},
    //     {1,4},
    //     {2,5},
    //     {2,9},
    //     {3,5},
    //     {3,7},
    //     {5,7},
    //     {6,7},
    //     {6,8},
    //     {4,6}
    // };
    

    int numarNoduri,numarMuchii;
    vector<vector<int>> muchii;
    vector<vector<int>> adiacente(numarNoduri+1); //pentru fiecare nod contine o lista cu nodurile adiacente lui  
    vector<int> vizitate(numarNoduri+1, 0); //vector care retine daca nodul i a fost sau nu vizitat
    queue <int> coada; //coada pentru parcurgere

    vector<int> distante(numarNoduri+1); //solutia problemei

    vector <int> puncteControl;

    void citireDate(){
        int x,y;
        ifstream f("graf.in");
        f>>numarNoduri>>numarMuchii;
        for(int i=1;i<=numarMuchii;i++){
            vector<int>aux;
            f>>x>>y;
            aux.push_back(x); aux.push_back(y);
            muchii.push_back(aux);
        }
        while(f>>x) puncteControl.push_back(x);
        f.close();
    }

    void init()  // initializarea listelor de adiacenta
    {
        
        for(int i=0;i<muchii.size();i++){ //parcurgem fiecare muchie
            cout<<muchii[i][0]<<' '<<muchii[i][1];
            adiacente[muchii[i][0]].push_back(muchii[i][1]);
            adiacente[muchii[i][1]].push_back(muchii[i][0]);
        }
    }

    void BFS(int nodStart,int distanta,int index)
    {
        coada.push(nodStart);
        distante[nodStart]=0;

        while(!coada.empty()){

            nodStart=coada.front();
            coada.pop();

            if(vizitate[nodStart]) continue;
            vizitate[nodStart]=1;

            distanta++;

            for(auto adiacent : adiacente[nodStart]){

                //actualizam distanta pentru toti vecinii nodului curent
                coada.push(adiacent);
                if(!vizitate[adiacent])
                    if(index==1)
                        distante[adiacent]=distanta;
                    else
                        if(distanta<distante[adiacent])
                            distante[adiacent]=distanta;
            }
        }
    }

    void rezolvare(){
        int index=1;
        for(auto& punct: puncteControl){
            //facem BFS plecand din fiecare punct de control
            BFS(punct,0,index);
            //reactulizam vectoru
            for (int i=0;i<vizitate.size();i++)
                vizitate[i]=0;
            index++;
        }

        ofstream g("graf.out");
        for(auto &indice :distante)
            cout<<indice<<' '; 
        cout<<endl;
        g.close();
    }

int main(){

    citireDate();
    init();
    rezolvare();
    return 0;
}
