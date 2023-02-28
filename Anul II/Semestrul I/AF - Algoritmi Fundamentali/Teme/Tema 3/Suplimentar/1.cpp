#include <bits/stdc++.h>
using namespace std;
ifstream f("fmcm.in");
ofstream o("fmcm.out");
#define dimensiuneMaxima 360
#define inf 1e9 + 7

int n, m, s, d, minCost = 0, flow, altNod;
int a[dimensiuneMaxima][dimensiuneMaxima], cost[dimensiuneMaxima][dimensiuneMaxima], tata[dimensiuneMaxima], dBellman[dimensiuneMaxima], dPlus[dimensiuneMaxima], dReal[dimensiuneMaxima];
vector<vector<int>> la(dimensiuneMaxima);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pCoada;

void BellmanFord() {
    vector<bool> inCoada(dimensiuneMaxima, false);
    queue<int> coada;
    memset(dBellman, inf, sizeof(dBellman));

    coada.push(s);
    inCoada[s] = true;
    dBellman[s] = 0;

    while (!coada.empty()) {
        int nod = coada.front();
        coada.pop();

        inCoada[nod] = false;
        
        for (auto adiacent: la[nod]) {
            if (a[nod][adiacent])
                if (dBellman[adiacent] > dBellman[nod] + cost[nod][adiacent]) {
                    dBellman[adiacent] = dBellman[nod] + cost[nod][adiacent];
                    if (!inCoada[adiacent]) {
                        coada.push(adiacent);
                        inCoada[adiacent] = true;
                    }
                }
        }
    }
}
bool Dijkstra() {
    for (int i = 1; i <= n; i++)
        dPlus[i] = inf;

    dPlus[s] = 0;
    dReal[s] = 0;

    pCoada.push(make_pair(0, s));

    while (!pCoada.empty()) {

        pair<int, int> front = pCoada.top();
        pCoada.pop();
        int nod = front.second;

        if (dPlus[nod] == front.first)
            for (auto adiacent: la[nod])
                if (a[nod][adiacent] > 0)
                    if (dPlus[adiacent] > dPlus[nod] + cost[nod][adiacent] + dBellman[nod] - dBellman[adiacent]) {
                        dPlus[adiacent] = dPlus[nod] + cost[nod][adiacent] + dBellman[nod] - dBellman[adiacent];
                        pCoada.push(make_pair(dPlus[adiacent], adiacent));
                        dReal[adiacent] = dReal[nod] + cost[nod][adiacent];
                        tata[adiacent] = nod;
                    }
    }
    for (int i = 1; i <= n; i++) {
        dBellman[i] = dReal[i];
    }

    // for (int i = 1; i <= n; i++) {
    //     cout<<dBellman[i]<<' ';
    // }
    // cout<<endl;

//Daca nu se poate face path
    if (dPlus[d] == inf) return false;

    flow = inf;
    //Aflam minimul iP
    for (int nod = d; nod != s; nod = tata[nod]) {
        flow = min(flow, a[tata[nod]][nod]);
    }
    //updatam graful

    for (int nod = d; nod != s; nod = tata[nod]) {
        a[tata[nod]][nod] -= flow;
        a[nod][tata[nod]] += flow;
    }
    //incrementam costul minim

    minCost += flow * dReal[d];
    cout<<minCost<<endl;
    return true;
}
void citireDate() {
    f >> n >> m >> s >> d;
    for (int i = 0; i < m; i++) {
        int x, y, c, z;
        f >> x >> y >> c >> z;
        la[x].push_back(y);
        la[y].push_back(x);
        a[x][y] = c;
        cost[x][y] = z;
        cost[y][x] = -z;
    }
}
int main() {
    citireDate();
    BellmanFord();
    while(Dijkstra());
    o<<minCost;


    return 0;
}