#include <iostream>
#include <fstream>
using namespace std;

struct punct{int x,y;};

int calculViraj(int xp,int yp,int xq,int yq){
    return xp*yq-xq*yp;
}

int viraj(punct x,punct y, punct z){
    return calculViraj((z.x-x.x),(z.y-x.y),(y.x-x.x),(y.y-x.y));
}
void solutie(){
    int numarPuncte,i,stanga=0,dreapta=0,inainte=0;
    // ifstream f("roby11.in");
    cin>>numarPuncte;
    // f>>numarPuncte;
    punct puncte[100001];
    for(i=1;i<=numarPuncte;i++){
        // f>>puncte[i].x>>puncte[i].y;
        cin>>puncte[i].x>>puncte[i].y;
    }
    int vj;
    for(i=1;i<numarPuncte;i++){
        vj=viraj(puncte[i],puncte[i+1],puncte[i+2]);
        if (vj==0) 
                inainte++;
        else
            if (vj>0)
                dreapta++;
            else 
                stanga++;
        cout<<stanga<<' '<<dreapta<<' '<<inainte<<endl;
    }
    cout<<stanga<<' '<<dreapta<<' '<<inainte;
    // f.close();
}

int main(){
    solutie();
    return 0;
}