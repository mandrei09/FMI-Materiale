#include <iostream>
using namespace std;

void Merge(int x[], int s, int d, int m)
{
    int y[101], i = s, j = m + 1,
    p = 0;
    while (i <= m && j <= d)
        if (x[i] < x[j])
            y[++p] = x[i++];
        else
            y[++p] = x[j++];
    for (; i <= m; i++)
        y[++p] = x[i];
    for (; j <= d; j++)
        y[++p] = x[j];
    p = 1;
    for (i = s; i <= d; i++)
        x[i] = y[p++];
}

void MergeSort(int x[], int s, int d)
{
    if (s == d)
        return;
    else
    {
        int m = (s + d) / 2;
        MergeSort(x, s, m);
        MergeSort(x, m + 1, d);
        Merge(x, s, d, m);
    }
}

void Input(int x[], int &n)
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> x[i];
}

int main()
{
    int x[101], n, i;

    Input(x, n);

    MergeSort(x, 1, n);

    for (i = 1; i <= n; i++)
        cout << x[i] << ' ';
}