#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define all(x) x.begin() + 1, x.end()
#define nall(x) x.begin(), x.end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define endl '
'
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, x) memset(a, x, sizeof(a))
 
#define trailingzero(x) __builtin_ctzll(x)
#define cntbit1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
 
#define _______TOISETHIVOI_______ signed main()
#define KILL() exit(0)
#define NAME "duxp"
 
template <typename T>
inline int getbit(T x, int k) { return (x >> k) & 1; }
template <typename T>
inline T onbit(T x, int k) { return x | (T(1) << k); }
template <typename T>
inline T offbit(T x, int k) { return x & ~(T(1) << k); }
 
const ll OO = 1e18;
const int oo = 1e9;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAXN = 200000;
 
bool case12[MAXN + 5];
bool forced[MAXN + 5];
 
struct edge
{
    int u,v,w;
};
 
int n, m;
 
int low[MAXN + 5], num[MAXN + 5];
int timer = 0;
 
vector<pair<int,int>> g[MAXN + 5]; 
 
vector<int> par, szz;
 
void init_dsu(int n) {
    par.resize(n + 1);
    szz.assign(n + 1, 1);
    iota(par.begin(), par.end(), 0);
}
 
int findset(int u) {
    if (u == par[u]) return u;
    return par[u] = findset(par[u]);
}
 
bool join(int u, int v) {
    u = findset(u);
    v = findset(v);
    if (u == v) return false;
    if (szz[u] < szz[v]) swap(u, v);
    par[v] = u;
    szz[u] += szz[v];
    return true;
}
 
void reset(vi &used)
{
    for(int i = 0; i < (int)used.size(); i++)
    {
        int u = used[i];
        g[u].clear();
        num[u] = 0;
        low[u] = 0;
    }
    timer = 0;
}
 
void dfs(int u, int parent_edge)
{
    num[u] = low[u] = ++timer;
 
    for(int i = 0; i < (int)g[u].size(); i++)
    {
        int v = g[u][i].fi;
        int id = g[u][i].se;
 
        if(id == parent_edge) continue;
 
        if(!num[v])
        {
            dfs(v, id);
            low[u] = min(low[u], low[v]);
 
            if(low[v] > num[u])
            {
                forced[id] = true; 
            }
        }
        else low[u] = min(low[u], num[v]);
    }
}
 
                                _______TOISETHIVOI_______
{
    fast;
    if (FILE *f = fopen(NAME ".inp", "r")) {
        fclose(f);
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    cin>>n>>m;
    vector<edge> a(m + 1);
    map<int, vi> mp;
    for(int i = 1; i <= m; i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
        mp[a[i].w].pb(i);
    }
    init_dsu(n);
    for(auto &i : mp)
    {
        int w = i.fi;
        vi eds = i.se;
        vector<pair<int, pii>> current;
        vi used;
        for(int k = 0; k < (int)eds.size(); k++)
        {
            int j = eds[k];
            int u = a[j].u, v = a[j].v;
            int ru = findset(u);
            int rv = findset(v);
            if(ru != rv)
            {
                used.pb(ru);
                used.pb(rv);
            }
        }
        sort(nall(used));
        used.erase(unique(nall(used)), used.end());
        reset(used);
        for(int k = 0; k < (int)eds.size(); k++)
        {
            int j = eds[k];
            int u = a[j].u, v = a[j].v;
            int ru = findset(u);
            int rv = findset(v);
            if(ru != rv)
            {
                current.pb({j, {ru, rv}});
                case12[j] = true;
                g[ru].pb({rv, j});
                g[rv].pb({ru, j});
            }
        }
        for(int k = 0; k < (int)current.size(); k++)
        {
            int u = current[k].se.fi;
            if(!num[u]) dfs(u, -1);
        }
        for(int k = 0; k < (int)eds.size(); k++)
        {
            int j = eds[k];
            int u = a[j].u, v = a[j].v;
            if(findset(u) != findset(v))
            {
                join(u, v);
            }
        }
    }
 
    for(int i = 1; i <= m; i++)
    {
        if(!case12[i]) cout<<"none"<<endl;
        else if(case12[i] && forced[i]) cout<<"any"<<endl;
        else cout<<"at least one"<<endl;
    }
 
    KILL();
}