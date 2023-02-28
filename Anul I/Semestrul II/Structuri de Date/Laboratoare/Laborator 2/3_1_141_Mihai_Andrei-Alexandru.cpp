#include <iostream>
using namespace std;

void Merge(int x[], int n, int y[], int m)
{
    int i = 1, j = 1;
    p = 0;
    while (i <= n && j <= m)
        if (x[i] < y[j])
            z[++p] = x[i++];
        else
            z[++p] = y[j++];
    for (; i <= n; i++)
        z[++p] = x[i];
    for (; j <= m; j++)
        z[++p] = y[j];
}

void Input(int x[], int &n, int y[], int &m)
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> x[i];
    cin >> m;
    for (i = 1; i <= m; i++)
        cin >> y[i];
}

int main()
{
    int x[101], n, y[101], m, z[201], p, i, j;

    Input(x, n, y, m);

    Merge(x, n, y, m, z, p);

    for (i = 1; i <= p; i++)
        cout << z[i] <<' ';
}