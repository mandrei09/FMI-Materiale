//InsertionSort implementare
#include <iostream>
using namespace std;
void InsertionSort(int v[], int n)
{
    int i,curent,j;

    for (i=2;i<=n;i++){

        curent=v[i];
        j=i-1;

        while (j>=0 && v[j]>curent){

            v[j+1]=v[j];
            j--;
        }

        v[j+1]=curent;

    }
}

int main(){
    int v[11],n;

    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i];

    InsertionSort(v,n);
    for(int i=1;i<=n;i++) cout<<v[i]<<' ';
    
    return 0;
}
