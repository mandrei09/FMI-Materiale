#include <iostream>
#include <vector>

using namespace std;

struct punct {long long x,y;};

// Functie care genereaza determinantul unei matrici 4x4
long long determinant(vector<vector<long long>> mat) {
    if (mat.size() == 2) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    long long det = 0;
    for (int i = 0; i < mat.size(); i++) {
        vector<vector<long long>> subMat(mat.size()-1, vector<long long>(mat.size()-1, 0));
        for (int j = 1; j < mat.size(); j++) {
            int index = 0;
            for (int k = 0; k < mat.size(); k++) {
                if (k != i) {
                    subMat[j-1][index++] = mat[j][k];
                }
            }
        }
        long long subDet = determinant(subMat);
        if (i % 2 == 0) {
            det += mat[0][i] * subDet;
        } else {
            det -= mat[0][i] * subDet;
        }
    }

    return det;
}


int main() {

    punct a,b,c; //cele 3 puncte care definesc triunghiul
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;

    int i,m;

    cin>>m;
    punct puncte[m];

    for(i=0;i<m;i++)
        cin>>puncte[i].x>>puncte[i].y;

    for(i=0;i<m;i++){
        punct d=puncte[i];

        //Matricea pentru care calculam determinantul.

        vector<vector<long long>> matrice={
            {a.x,a.y,a.x*a.x+a.y*a.y,1},
            {b.x,b.y,b.x*b.x+b.y*b.y,1},
            {c.x,c.y,c.x*c.x+c.y*c.y,1},
            {d.x,d.y,d.x*d.x+d.y*d.y,1}
        };

        long long rezultat=determinant(matrice);

        //In functie de rezultatul determinantului ne dam seama de pozitia punctului.

        if(rezultat==0)
            cout<<"BOUNDARY\n";
        else if(rezultat>0)
            cout<<"INSIDE\n";
        else cout<<"OUTSIDE\n";
    }
    return 0;
}