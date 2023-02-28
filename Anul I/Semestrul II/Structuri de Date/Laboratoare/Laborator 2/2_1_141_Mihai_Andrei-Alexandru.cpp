#include <iostream>
using namespace std;

void heapify(int x[], int n, int i)
{
  int radacina = i;
  int fiu_stanga = 2 * i + 1;
  int fiu_dreapta = 2 * i + 2;

  if (fiu_stanga < n && x[fiu_stanga] > x[radacina])
    radacina = fiu_stanga;

  if (fiu_dreapta < n && x[fiu_dreapta] > x[radacina])
    radacina = fiu_dreapta;

  if (radacina != i)
  {
    swap(x[i], x[radacina]);
    heapify(x, n, radacina);
  }
}

void heapSort(int x[], int n)
{

  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(x, n, i);

  for (int i = n - 1; i >= 0; i--)
  {
    swap(x[0], x[i]);
    heapify(x, i, 0);
  }
}

void print(int x[], int n)
{
  for (int i = 0; i < n; ++i)
    cout << x[i] << " ";
  cout << "\n";
}

int main()
{
  int x[] = {2,7,4,4,5,10};
  int n = 6;
  heapSort(x, n);
  print(x, n);
  return 0;
}