#include <iostream>
using namespace std;

void inter(int &x, int &y)
{
    int aux = x;
    x = y;
    y = aux;
}

int pivot(int x[], int s, int d)
{
    int i = s, j = d, ok = 0;
    while (i != j)
        if (!ok)
            if (x[j] < x[i])
            {
                inter(x[i], x[j]);
                inter(i, j);
                ok = 1;
            }
            else
                j--;
        else 
            if (x[j] > x[i])
        {
            inter(x[i], x[j]);
            inter(i, j);
            ok = 0;
        }
        else
            j++;
    return i;
}

void QuickSort(int x[], int s, int d)
{
    if (s >= d)
        return;
    int m = pivot(x, s, d);
    QuickSort(x, s, m);
    QuickSort(x, m + 1, d);
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

    QuickSort(x, 1, n);

    for (i = 1; i <= n; i++)
        cout << x[i] << ' ';
}