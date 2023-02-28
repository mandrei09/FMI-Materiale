#include <iostream>
#include <cstring>
using namespace std;

//subprogram ajutator conversie hexa ==> binar

void binar(int x,int r[]){
    int i;
    for (i=1;i<=4;i++)
        r[i]=-1;
    i=4;
    while(x){
        r[i]=x%2;
        i--;
        x/=2;
    } 
}

//subprogram ajutator conversie binar ==> zecimal

void zecimal(int r[],int start,int stop,int &z){
    int i,p=1;
    z=0;
    for (i=start;i>stop;i--){
        z=z+r[i]*p;
        p=p*2;
    }
}

int main(){
    char s[101];
    int b[404],i,r[5],j,p=1,L;
    cin.getline(s,401);
    L=strlen(s);
    //formare vector b ==> conversie din hexa in binar
    
    for (i=0;i<L;i++)
        if(s[i]=='A'){
            binar(10,r);
            for (j=1;j<=4;j++){
                b[p]=r[j];
                p++;
            }
        }
        else 
            if(s[i]=='B'){
                binar(11,r);
                for (j=1;j<=4;j++){
                    b[p]=r[j];
                    p++;
                }
            }
            else
                if(s[i]=='C'){
                    binar(12,r);
                    for (j=1;j<=4;j++){
                        b[p]=r[j];
                        p++;
                    }
                }
                else
                    if(s[i]=='D'){
                        binar(13,r);
                        for (j=1;j<=4;j++){
                            b[p]=r[j];
                            p++;
                        }
                    }
                    else
                        if(s[i]=='E'){
                            binar(14,r);
                            for (j=1;j<=4;j++){
                                b[p]=r[j];
                                p++;
                            }
                        }
                        else
                            if(s[i]=='F'){
                                binar(15,r);
                                for (j=1;j<=4;j++){
                                    b[p]=r[j];
                                    p++;
                                }
                            }
                            else{
                                binar(s[i]-48,r);
                                for (j=1;j<=4;j++){
                                    if(r[j]==-1)
                                        b[p]=0;
                                    else 
                                        b[p]=r[j];
                                    p++;
                                }
                            }    
            /*
            b0 este mereu 1
            b1 si b2 ==> 
                00 - numar intreg 
                    b3 = 0 pentru numere pozitive
                    b3 = 1 pentru numere negative
                01 - variabila
                    b3 = 0
                10 - operatie
            de la b4 in colo ==>
                pentru 00 ==> numarul in baza 10
                pentru 01 ==> numele variabilei, codul ASCII asociat
                pentru 10 ==> codificarea operatiei
                    let 000000000 ==> 0 
                    add 000000001 ==> 1
                    sub 000000010 ==> 2
                    mul 000000011 ==> 3
                    div 000000100 ==> 4
            */
    int l=4*L,z,nr=0;

    /* VERIFICARE VECTOR B ==> BINAR 
    for (i=1;i<=l;i++){
        cout<<b[i];
        nr++;
        if(nr==12) cout<<' ',nr=0;
    }
    cout<<endl;
    */

    for (i=0;i<=l;i+=12)
        if(b[1+i+1]==0)
            if(b[2+i+1]==0){
                //este o valoare, convertim in baza 10 
                zecimal(b,i+12,i+4,z);
                if (b[3+i+1]==1) z=-z;
                cout<<z<<' ';
            }
            else
                if(b[2+i+1]==1){
                    //este o variabila, convertim codul ascii la numele variabilei ; b3 este mereu 0
                    zecimal(b,i+12,i+4,z);
                    cout<<(char)z<<' ';
                }
                else;
        else{
                //este o operatie
                zecimal(b,i+12,i+4,z);
                if (z==0) cout<<"let ";
                else 
                    if(z==1) cout<<"add ";
                    else
                        if(z==2) cout<<"sub ";
                        else
                            if(z==3) cout<<"mul ";
                            else 
                                if(z==4) cout<<"div ";
            }
    return 0;
}