#include <iostream>
using namespace std;

int n, m, v[101];
int x[101];
int ap[101];
int ok = 0;

int valid(int k)
{
    //if (x[k] && v[k] != x[k]) return 0; ///cele puse initial

    if (ap[v[k]]>3) return 0;

    //int ap = 1; /// sa apara de cel mult 3 ori
    //for(int i=1; i<k; i++)
        //if (v[k] == v[i]) ap++;
    //if (ap > 3) return 0;

    for (int i=k-1; i>0; i--) ///distanta dintre 2 egale sa fie > m
        if (v[k] == v[i]){
            if (k - i <= m) return 0;
            break;
        }
    return 1;
}


void tipar(int k){
    for(int i=1; i<=k; i++)
        cout << v[i] << " ";
    cout << "\n";
}

void back(int k){
    if(ok==0)
        if(x[k]!=0){

            v[k]=x[k];
            ap[x[k]]++;

            if(valid(k))

                if(k==3*n){

                    ok=1;
                    tipar(k);

                }
                else back(k+1);
            ap[v[k]]--;
        }
        else
            for(int i=1; i<=n && ok==0; i++){

                v[k] = i;
                ap[i]++;

                if (valid(k)){

                    if (k == 3*n) ok=1, tipar(k);
                    else back(k+1);

                }

                ap[v[k]]--;
            } 
}

int main()
{
    int i;
    cin >> n >> m;
    for(int i=1; i<=3*n; ++i)
    	cin >> x[i];

    back(1);

    if(ok==0) cout<<"-1"; 

    return 0;
}