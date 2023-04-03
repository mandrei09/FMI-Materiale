#include <bits/stdc++.h>
#include <fstream>
#define ll long long int
using namespace std;

struct Punct {

	ll x, y;

	//supraincarcam operatorul pentru sortarea lexicografica a punctelor
	bool operator<(Punct p)
	{
		return x < p.x || (x == p.x && y < p.y);
	}

};

//Functie care returneaza produsul scalar a 2 vectori
ll produsScalar(Punct O, Punct A, Punct B)
{
	return (A.x - O.x) * (B.y - O.y)
		- (A.y - O.y) * (B.x - O.x);
}

//Functie care calculeaza infasuratoarea.
vector<Punct> GrahamScan(vector<Punct> A)
{
	int n = A.size(), k = 0;

	//Pentru maxim 3 puncte, infasuratoarea le cuprinde pe toate.
	if (n <= 3)
		return A;

	vector<Punct> ans(2 * n);

	//Sortam punctele lexicografic
	sort(A.begin(), A.end());

	//Construim infasuratoarea de jos
	for (int i = 0; i < n; ++i) {

		//Adaugam primele 2 puncte sortate lexicografic ("cele mai din stanga")
		//Apoi verificam pentru fiecare 3 puncte daca fac viraj la dreapta
		//caz in care modificam vectorul de raspuns.
		while (k >= 2 && produsScalar(ans[k - 2],ans[k - 1], A[i]) <= 0)
			k--; //daca exista viraj la dreapta la ans[i-1] ans[i] ans[i+1]
				 //scadem k pentru a putea inlocui elementul ans[i]
		ans[k++] = A[i];
	}

	//Construim infasuratoarea de sus
	for (int i = n - 1, t = k + 1; i > 0; --i) {
		//acelasi lucru ca mai sus
		while (k >= t && produsScalar(ans[k - 2], ans[k - 1], A[i - 1]) <= 0)
			k--;
		ans[k++] = A[i - 1];
	}

	ans.resize(k - 1);

	return ans;
}

// Driver code
int main()
{

    int numarPuncte,i,x,y; vector<Punct> puncte;

    cin>>numarPuncte;
    for(i=0;i<numarPuncte;i++){
		cin>>x>>y;
        // f>>x>>y;
        puncte.push_back({ x, y });
    }

	vector<Punct> ans = GrahamScan(puncte);

	cout<<ans.size()<<endl;

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].x << " " << ans[i].y << endl;
    
	return 0;
}
