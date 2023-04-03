#include <iostream>
using namespace std;

long long calculDeterminant(long p1,long p2,long q1,long q2,long r1,long r2){
    long long a=(long long)q1*r2,b=(long long)p1*q2,c=(long long)r1*p2,d=(long long)q1*p2,e=(long long)r1*q2,f=(long long)p1*r2;
    return (a+b+c-d-e-f);
}

int main(){
    int numarCazuri; 
    cin>>numarCazuri;
    long p1x,p1y,p2x,p2y,p3x,p3y;
    for(int i=1;i<=numarCazuri;i++){
        cin>>p1x>>p1y>>p2x>>p2y>>p3x>>p3y;
        long long rezultat=calculDeterminant(p1x,p1y,p2x,p2y,p3x,p3y);
        if (rezultat==0)
            cout<<"TOUCH";
        else
            if (rezultat<0) 
                cout << "RIGHT";
            else
                cout<<"LEFT";

        if(i!=numarCazuri) 
            cout<<endl;
    }
    return 0;
}