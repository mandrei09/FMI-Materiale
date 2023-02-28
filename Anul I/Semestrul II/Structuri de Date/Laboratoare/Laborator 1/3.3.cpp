#include <iostream>
using namespace std;

int pivot(int v[],int s,int d){
    int m;

    while(s<=d){

        m=(s+d)/2;

        if(v[m]>=v[m+1]) return m;
        else
            if(v[s]>v[m]) d=m-1;
            else s=m+1;
    }
}

int BinarySearch(int v[],int s,int d,int x){

    int m;

    while(s<=d){

        m=(s+d)/2;
        if(v[m]==x) return m;
        if(x<v[m]) d=m-1;
        else s=m+1;

    }

    return -1;
}
int main(){
    int n,v[101],i,x;

    cin>>n>>x;
    for(i=1;i<=n;i++) cin>>v[i];

    int piv=pivot(v,1,n),rez;
    if(x<v[1]) rez=BinarySearch(v,piv+1,n,x);
    else rez=BinarySearch(v,1,piv,x);

    if(rez!=-1) cout<<"Elementul "<<x<<" se afla in sir pe pozitia "<<rez-1;
    else cout<<"Elementul "<<x<<" nu se afla in sir";

    return 0;
}