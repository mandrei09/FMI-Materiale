#include <bits/stdc++.h>

using namespace std;

// Structura pentru a retine ecuatia care determina un semiplan
struct semiplan
{
    long long a, b, c;
};

int main()
{
    // ifstream f("date.in");

    int n;
    vector<semiplan> puncte;
    cin>>n;
    // f >> n;
    puncte.resize(n);

    for (int i = 0; i < n; i++)
        cin >> puncte[i].a >> puncte[i].b >> puncte[i].c;
        // f >> puncte[i].a >> puncte[i].b >> puncte[i].c;

    long long YMAX, YMIN, XMAX, XMIN;
    YMAX = XMAX = -9999999;
    YMIN = XMIN = 9999999;

    for (int i = 0; i < n; i++)
        if (puncte[i].b == 0) // daca semiplanul este vertical, are o ecuatie de forma ax + c
        {

            long long aux = (-puncte[i].c / puncte[i].a);
            // semiplan vertical la dreapta a<0
            if (puncte[i].a < 0)
                if (aux > XMAX)
                    XMAX = aux;
                else;
                // semiplan vertical la stanga a>0
            else 
                if (puncte[i].a > 0)
                    if (aux < XMIN)
                        XMIN = aux;
        }
        else if (puncte[i].a == 0) // daca semiplanul este orizontal, are o ecuatie de forma by + c
        {
            long long aux = (-puncte[i].c / puncte[i].b);
            // semiplan orizontal in sus b<0
            if (puncte[i].b < 0)
                if (aux > YMAX)
                    YMAX = aux;
                else;
                // semiplan orizontal la jos b>0
            else 
                if (puncte[i].b > 0)
                    if (aux < YMIN)
                        YMIN = aux;
        }
    // cout<<XMIN<<' '<<XMAX<<' '<<YMIN<<' '<<YMAX<<endl;
    
    // Sigur nu sunt intersectate intr-o arie limitata
    if(XMAX == -9999999 || XMIN == 9999999 || YMAX == -9999999 || YMIN == 9999999)
    {
        if(XMIN < XMAX || YMIN < YMAX)
            cout << "VOID";
        else
            cout << "UNBOUNDED";
    }
    else
    {
        if(XMIN >= XMAX && YMIN >= YMAX)
            cout << "BOUNDED";
        else
        {
            if(XMIN < XMAX || YMIN < YMAX)
                cout << "VOID";
            else
                cout << "UNBOUNDED";
        }
    }
}