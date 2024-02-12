#include <bits/stdc++.h>
using namespace std;

// Functie care clasifica valorile de maxim / minim pentru un semiplan
void intersection(double a, double b, double c, bool pozitiv, vector <long double> &stanga, vector <long double> &dreapta, vector <long double> &jos, vector <long double> &sus) {
    double aux;
    pozitiv = true;
    if (a == 0) { // daca semiplanul este orizontal, are o ecuatie de forma by + c
        if (b < 0) pozitiv = false;
        aux = (double)(-c) / b; // calculam valoarea maximului.
        if (pozitiv) sus.push_back(aux);
        else jos.push_back(aux);
    } else {  // daca semiplanul este vertical, are o ecuatie de forma by + c
        if (a < 0) pozitiv = false;
        aux = (double)(-c) / a;
        if (pozitiv) dreapta.push_back(aux);
        else stanga.push_back(aux);
    }
}

//Returneaza pozitia celui mai mare numar < decat x. 
int celMaiMicMaiMarePoz(vector < long double >& lista, double x) {

    if (lista.empty() || x < lista[0]) {
        return -1;
    }
        int stanga = 0, dreapta = lista.size() - 1, poz = -1;
        while (dreapta >= stanga) {
            int mid = (stanga + dreapta) / 2;
            if (x > lista[mid]) {
                poz = mid;
                stanga = mid + 1;
            } else {
                dreapta = mid - 1;
            }
        }
        return poz;

}

//Returneaza pozitia celui mai mic numar > decat x. 
int celMaiMareMaiMicPoz(vector < long double >& lista, double x) {
    if (lista.empty() || x > lista.back()) {
        return -1;
    }

    // Pentru cautare aplicam cautarea binara.
    int stanga = 0, dreapta = lista.size() - 1, poz = -1;
    while (dreapta >= stanga) {
        int mid = (stanga + dreapta) / 2;
        if (x < lista[mid]) {
            poz = mid;
            dreapta = mid - 1;
        } else {
            stanga = mid + 1;
        }
    }

    return poz;
}

int main() {

    int n,m,a,b,c;
    bool pozitiv;
    double x,y;

    vector < long double > stanga, dreapta, jos, sus;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a >> b >> c;
        intersection (a, b, c, pozitiv, stanga, dreapta, jos, sus);
    }

    cin >> m;

    sort(stanga.begin(), stanga.end());
    sort(dreapta.begin(), dreapta.end());
    sort(jos.begin(), jos.end());
    sort(sus.begin(), sus.end());

    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;

        int stangaIndex = celMaiMicMaiMarePoz(stanga, x);  // determina cel mai mare x la stanga lui x
        int dreaptaIndex = celMaiMareMaiMicPoz(dreapta, x); // determina cel mai mic x la dreapta lui x
        int josIndex = celMaiMicMaiMarePoz(jos, y); // determina cel mai mare x sub y
        int susIndex = celMaiMareMaiMicPoz(sus, y); // determina cel mai mic x peste y

        // Daca cautarea a esuat.
        if (stangaIndex == -1 || dreaptaIndex == -1 || josIndex == -1 || susIndex == -1) {
            cout << "NO" << '\n';
        } else {
            long double area = (dreapta[dreaptaIndex] - stanga[stangaIndex]) * (sus[susIndex] - jos[josIndex]);
            cout << "YES" << '\n';
            cout << setprecision(6) << fixed << area << '\n';
        }
    }
}