#include <iostream>
using namespace std;
int cmmdc(int a,int b){
    while(a && b)
        if(a>b) a%=b;
        else b%=a;
    return a+b;
}
int main(){
    //fie x numaratorul si y numitorul
    int x,y,aux;
    cin>>x>>y;
    while (x!=1){
        aux=y/x+1;
        cout<<1<<'/'<<aux<<'+';
        x=x*aux-y;
        y*=aux;
        aux=cmmdc(x,y);
        //x/=aux; y/=aux;
    }
    cout<<1<<'/'<<y;
    return 0;
}