//SelecionSort implementare
#include <iostream>
using namespace std;

void inter(int &a,int &b){

    int aux=a; a=b; b=aux;
}

void SelectionSort(int v[],int n){

    int i,j,min_ind;

    for(i=1;i<n;i++){

        min_ind=i;

        for(j=i+1;j<=n;j++)

            if(v[j]<v[min_ind])
                min_ind=j;

        inter(v[i],v[min_ind]);

    }
}

int main(){
    int v[11],n;

    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i];

    SelectionSort(v,n);
    for(int i=1;i<=n;i++) cout<<v[i]<<' ';
    
    return 0;
}
