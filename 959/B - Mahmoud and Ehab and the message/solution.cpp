/*
Author: Kduckp
Version: 1
Created at: 2025-12-15 23:15
*/
#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TDN signed main()
 
const ll INF = 1e18;
const int MOD = 1000000007;
const int MAXN = 200000;
 
int n, k, m;
vector<string> letters;
int a[MAXN], par[MAXN], szz[MAXN], minn[MAXN];
 
int findset(int u)
{
    if(u == par[u]) return u;
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
        minn[u] = min(minn[u], minn[v]);
    }
}
 
TDN
{
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
    cin >> n >> k >> m;
    letters.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> letters[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
        szz[i] = 1;
        minn[i] = a[i];
    }
    for(int i = 1; i <= k; i++)
    {
        int x; cin >> x;
        int first; 
        cin >> first;
        for(int j = 2; j <= x; j++)
        {
            int node; cin >> node;
            join(first, node);
        }
    }
    vector<pair<int, int>> sets;
    for(int i = 1; i <= n; i++)
    {
        if(findset(i) == i)sets.pb({i, minn[i]});
    }
    unordered_map<string, int> id;
    for(int i = 1; i <= n; i++)
    {
        id[letters[i]] = i;
    }
    ll ans = 0;
    for(int i = 1; i <= m; i++)
    {
        string w;
        cin >> w;
        int idx = id[w];
        ans += minn[ findset(idx) ];
    }
 
    cout << ans;
}