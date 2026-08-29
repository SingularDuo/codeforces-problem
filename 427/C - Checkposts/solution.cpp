#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
const int MOD = 1e9 + 7;
int n, m, a[100005];
vector<int> g[100100], rg[100100], scc[100100];
 
int scc_sz[100100], min_scc[100100] = {INT_MAX};
bool visited[100100];
vector<int> topo;
void dfs1(int u)
{
    visited[u] = true;
    for(auto v : g[u])
    {
        if(!visited[v])dfs1(v);
    }
    topo.pb(u);
}
void dfs2(int u, int id)
{
    min_scc[id] = min(min_scc[id], a[u]);
    visited[u] = true;
    scc[id].pb(u);
    for(auto v : rg[u])
    {
        if(!visited[v])dfs2(v, id);
    }
}
void solve()
{
    cin>>n;
    for(int i = 1; i <= n; i++)cin>>a[i];
    cin>>m;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        rg[v].pb(u);
    }
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])dfs1(i);
    }
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++) min_scc[i] = LLONG_MAX;
    reverse(all(topo));
    int cnt = 0, res = 0;
    for(auto u : topo)
    {
        if(!visited[u])
        {
            cnt++;
            dfs2(u, cnt);
            scc_sz[cnt] = scc[cnt].size();
            res += min_scc[cnt];
        }
    }
    int choose[cnt+1];
    for(int i = 1; i <= cnt; i++)
    {
        choose[i] = 0;
        int val = min_scc[i];
        for(auto u : scc[i])
        {
            if(a[u] == val)choose[i]++;
        }
    }
    ll cntt = 1;
    for(int i = 1; i <= cnt; i++)
    {
        cntt = (cntt % MOD * choose[i] % MOD) % MOD;
    }
 
    cout<<res<<" "<<cntt % MOD;
}
 
signed main()
{
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
    auto start = clock();
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
 
    cerr <<endl << (clock() - start) * 1000.0 / CLOCKS_PER_SEC<<' '<<'m'<<'s'<<endl;
 
    return 0;
}