#include <iostream>
using namespace std;
int main(){
    int start[101],stop[101],i,n;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>start[i];
    for(i=0;i<n;i++)
        cin>>stop[i];
    int nr=1;
    cout<<0<<' ';
    for(i=1;i<n;i++)
        if(start[i]>=stop[i-1])
            {cout<<i<<' '; nr++;}
    cout<<endl<<nr;
    return 0;
}