#include <bits/stdc++.h>
using namespace std;

//Structura pentru punct + supraincarcarea operatorului pentru compararea a 2 puncte
struct Punct
{
    long long x, y;
    bool operator<(Punct const &b)
    {
        return (x < b.x || (x == b.x && y < b.y));
    }
};

// Functie care calculeaza determinantul
long long determinant(Punct P, Punct Q, Punct R)
{
    return Q.x * R.y + P.x * Q.y + R.x * P.y - Q.x * P.y - R.x * Q.y - P.x * R.y;
}

//Functie care verifica daca P este pe segmentul AB, intre A si B
bool onSegment (Punct A, Punct B, Punct p){
    if (determinant(A, B, p) == 0) { //Daca cele 3 puncte sunt coliniare
        if (p.x >= min(A.x, B.x) && p.x <= max(A.x, B.x) && p.y >= min(A.y, B.y) && p.y <= max(A.y, B.y)) {
            return 1;
        }
    }
    return 0;
}

//Functia principala a programului
int pozitiePunct(Punct p, vector<Punct>& poligon, int n) {

    int prim = 1;
    int ultim = n-1;

    //Daca punctul se afla pe o latura, semnalizam acest lucru inainte sa incepem cautarea binara
    if (onSegment(poligon[0], poligon[prim], p) || onSegment(poligon[0], poligon[ultim], p)) {
        return 0;
    }
    
    if (determinant(poligon[0], poligon[prim], p) > 0 && determinant(poligon[0], poligon[ultim], p) < 0) {
        //aplicam cautarea binara
        while (ultim - prim != 1) {
            //calculam mijlocul
            int mij = (ultim + prim) / 2;
            //daca p se afla in stanga segmentului poligon[0] poligon[mij] 
            if (determinant(poligon[0], poligon[mij], p) > 0) {
                prim = mij;
            }
            //in dreapta
            else {
                ultim = mij;
            }
        }
        
        //Punctul este pe o latura a poligonului
        if (onSegment(poligon[prim], poligon[ultim], p)) {
            return 0;
        }

        //Punctul este in interior
        if (determinant(poligon[prim], poligon[ultim], p) > 0) {
            return 1;
        }
    }
    //Punctul p este in afara poligonolui
    return -1;
           
}

int main()
{
    // Initializare variabile + input
    int n, m, i;
    vector<Punct> poligon;
    cin >> n;
    poligon.resize(n);

    for (i = 0; i < n; i++)
        cin >> poligon[i].x >> poligon[i].y;

    int stanga = 0;
    // Gasim cel mai  din stanga punct (cu cel mai mic x)
    // Daca punctele au x egla, le comparam dupa y.
    for (i = 1; i < n; i++)
    {
        if (poligon[i] < poligon[stanga])
            stanga = i;
    }

    for(int i = 0; i < n; i++){
        if (determinant(poligon[i], poligon[(i+1)%n], poligon[(i+2)%n]) == 0){
            poligon.erase(poligon.begin() + (i+1) % n);
            n--;
            i--;
        }
    }

    // Citim restul datelor
    Punct puncte[100001];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> puncte[i].x >> puncte[i].y;
    for (int i = 0; i < m; i++){
        int rez = pozitiePunct(puncte[i], poligon, n);
        if (rez == 1) {
            cout<<"INSIDE\n";
        }
        if (rez == 0) {
            cout<<"BOUNDARY\n";
        }
        if (rez == -1) {
            cout<<"OUTSIDE\n";
        }
    }
}