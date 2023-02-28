//BubbleSort implementare
#include <iostream>
using namespace std;
void inter(int &a,int &b){
    int aux=a; a=b; b=aux;
}
void BubbleSort(int v[],int n){
    int i,j;
    for (i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(v[j]<v[i]) inter(v[j],v[i]);
}
int main()
{
    int v[11],n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i];
    BubbleSort(v,n);
    for(int i=1;i<=n;i++) cout<<v[i]<<' ';
    return 0;
}
