#include <iostream>
#include <cstring>
using namespace std;

void inter(char a[],char b[]){

    char aux[101];
    strcpy(aux,a); strcpy(a,b); strcpy(b,aux);

}

int este_anagrama(char s[]){

    if(!strcmp(s,strrev(s))) return 1;
    return 0;

}

void BubbleSort(char v[][101],int n){

    int i,j;
    for (i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(este_anagrama(v[j])==1) inter(v[j],v[i]);

}

int main(){

    int n; char c[101][101];

    cin>>n; cin.get();
    for(int i=1;i<=n;i++) 
        cin.getline(c[i],101);

    BubbleSort(c,n);
    for(int i=1;i<=n;i++) cout<<c[i]<<' ';
    
    return 0;
}
