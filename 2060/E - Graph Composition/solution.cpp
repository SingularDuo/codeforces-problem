#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
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
const int N = 200005;
int par[N], szz[N];
int findset(int u)
{
    if(u == par[u])return u;
    return par[u] = findset(par[u]);
}
void join(int u, int v)
{
    u = findset(u);
    v = findset(v);
    if(u != v)
    {
        if(szz[u] < szz[v]) swap(u, v);
        par[v] = u;
        szz[u] += szz[v];
    }
}
void solve()
{
    int n,m1,m2; cin>>n>>m1>>m2;
    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
        szz[i] = 1;
    }
    vector<pii> a(m1 + 1);
    for(int i =1 ; i <=m1; i++)
    {
        cin>>a[i].fi>>a[i].se;
    }
    for(int i = 1; i <= m2; i++)
    {
        int x,y; cin>>x>>y;
        join(x,y);
    }
    vector<int> idx(n + 1);
    set<int> sz1;
    for (int i = 1; i <= n; i++) {
        idx[i] = findset(i);
        sz1.insert(idx[i]);
    }
    int res = 0;
    vector<char> marked(m1 + 1, 1);
    for (int i = 1; i <= m1; i++) {
        int u = a[i].fi, v = a[i].se;
        if (idx[u] != idx[v]) {
            res++;
            marked[i] = 0;
        }
    }
 
    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
        szz[i] = 1;
    }
    for(int i = 1; i <= m1; i++)
    {
        if(marked[i])
        {
            int u = a[i].fi, v = a[i].se;
            join(u,v);
        }
    }
    set<int> sz2;
    for (int i = 1; i <= n; i++) {
        idx[i] = findset(i);
        sz2.insert(idx[i]);
    }
    cout<<res + abs((int)(sz2.size() - sz1.size()))<<'
';
 
 
 
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
    cin >> tc;
    while (tc--)
    {
        solve();
    }
 
    cerr <<endl << (clock() - start) * 1000.0 / CLOCKS_PER_SEC<<' '<<'m'<<'s'<<endl;
 
    return 0;
}