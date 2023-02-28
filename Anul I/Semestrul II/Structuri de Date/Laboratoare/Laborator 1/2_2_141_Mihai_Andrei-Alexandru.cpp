//Cautare binara implementare
#include <iostream>
using namespace std;

int BinarySearch(int v[],int s,int d,int x){

    int m;

    while(s<=d){

        m=(s+d)/2;
        if(v[m]==x) return 1;
        if(x<v[m]) d=m-1;
        else s=m+1;

    }

    return 0;
}

int main(){
    int v[100],n,x,i;

    cin>>x>>n;
    for(i=1;i<=n;i++) cin>>v[i];

    if(BinarySearch(v,1,n,x)==1) cout<<"Elementul este in sir";
    else cout<<"Elementul nu este in sir";
    
    return 0;
}