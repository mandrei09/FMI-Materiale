#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int kNmax = 1005;

class Task {
 public:
	void show() {
		read_input();
		solve();
	}

 private:
	int n;
	int count = 0;
	int plecare[kNmax];
	int intoarcere[kNmax];
	int q[kNmax];
	int l[kNmax][kNmax];
	
	void read_input() {
		ifstream fin("harta.in");
		fin >> n;
		for (int i = 1; i <= n; i++) {
			fin >> plecare[i];
			fin >> intoarcere[i];
			count += plecare[i];
		}
		
		fin.close();
	}
	
	void solve() {
		ofstream fout("harta.out");
		fout << count << "\n";
		
		int i, j, k, ok;
		for (i = 1; i <= n; i++) {
			// memset(q, 0, sizeof(q));
			for (j = 1; j <= n; j++)
				q[j]=0;

			for (j = 1; j <= n; j++) {
				if (intoarcere[j] && i != j) {
                    q[intoarcere[j]]++;
					l[intoarcere[j]][q[intoarcere[j]]] = j;
				}
			}

			for (j = n ; j && plecare[i]; j--) {
				for (k = q[j]; k && plecare[i]; k--) {
                    ok = l[j][k];
					plecare[i] --;
					intoarcere[ok] --;
					fout << i << " " << ok << "\n";
				}
			}
		}
	}
};

int main() {
	Task *task = new Task();
	task->show();
	delete task;
	return 0;
}