#include <bits/stdc++.h>
using namespace std;
ifstream fin("cuplaj.in");
ofstream fout("cuplaj.out");
int n,m,k,i,x,y,j,cuplat[20010],viz[20010],cnt,ans;
vector<int>v[20010];
void cuplare(int a,int b)
{
    cuplat[cuplat[a]]=0;
    cuplat[a]=b;
    cuplat[cuplat[b]]=0;
    cuplat[b]=a;
}
int dfs(int nod)
{
    viz[nod]=cnt;
    for(auto it:v[nod])
        if(viz[it]!=cnt)
        {
            viz[it]=cnt;
            if(cuplat[it] && dfs(cuplat[it]))
            {
                cuplare(nod,it);
                return 1;
            }
            else if(!cuplat[it])
            {
                cuplare(nod,it);
                return 1;
            }
        }
    return 0;
}
int main()
{
    fin>>n>>m>>k;
    for(i=1;i<=k;i++)
    {
        fin>>x>>y;
        v[x].push_back(y+n);
        v[y+n].push_back(x);
    }
    int ok=1;
    while(ok)
    {
        ok=0;
        cnt++;
        for(int i=1;i<=n+m;i++)
            if(!cuplat[i] && viz[i]!=cnt)
                ok=ok|dfs(i);
    }
    for(i=1;i<=n;i++)
        if(cuplat[i])
            ans++;
    fout<<ans<<'\n';
    for(i=1;i<=n;i++)
        if(cuplat[i])
            fout<<i<<" "<<cuplat[i]-n<<'\n';
    return 0;
}