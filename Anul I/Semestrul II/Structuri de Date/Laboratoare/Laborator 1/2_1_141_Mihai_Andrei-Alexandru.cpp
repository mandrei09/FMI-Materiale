//Cautare secventiala implementare
#include <iostream>
using namespace std;
int main(){

    int v[100],n,i,x,ok=0;
    cin>>x>>n;
    for(i=1;i<=n;i++) cin>>v[i];

    for(i=1;i<=n;i++)
        if(v[i]==x) {ok=1; break; }

    if(ok==1) cout<<"Element gasit";
    else cout<<"Nu exista elementul in sir";
    
    return 0;
}