/*
====================================
Version: 1
Author: duxp
Date created: 19/03/2026 12:55:05
Note (If needed): 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin() + 1, x.end()
#define nall(x) x.begin(), x.end()
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define endl '
'
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, x) memset(a, x, sizeof(a))
#define working cerr<<"If u see this message, your code is working orz "<<endl;
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
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
const ll OO = 1e18;
const int oo = 1e9;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAXN = 200000;
struct ed
{
    int t,u,v;
};
int n, m;
int color[MAXN + 5], order[MAXN + 5];
vi g[MAXN + 5], topo;
vector<ed> eds;
bool cycle = false;
void reset()
{
    cycle = false;
    for(int i = 1; i <= n; i++)
    {
         g[i].clear();
         color[i] = 0;
         order[i] = 0;
    }
    topo.clear();
    eds.clear();
}
void dfs(int u)
{
    color[u] = 1;
    for(int v : g[u])
    {
        if(color[v] == 1)
        {
            cycle = true;
            return;
        }
        else if(color[v] == 0)
        {
            dfs(v);
            if(cycle) return;
        }
    }
    topo.pb(u);
    color[u] = 2;
}
void solve()
{
    cin>>n>>m;
    reset();
    for(int i = 1; i <= m; i++)
    {
        int t, u, v; cin>>t>>u>>v;
        eds.pb({t,u,v});
        if(t == 1)
        {
            g[u].pb(v);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!color[i])dfs(i);
    }
    if(cycle)
    {
        cout<<"NO"<<endl;
        return;
    }
    reverse(nall(topo));
    for(int i = 0; i < topo.size(); i++)
    {
        order[topo[i]] = i;
    }
    cout<<"YES"<<endl;
    for(int i = 0; i < m; i++)
    {
        int t = eds[i].t, u = eds[i].u, v = eds[i].v;
        if(t == 1)
        {
            cout<<u<<" "<<v<<endl;
        }
        else
        {
            if(order[u] < order[v]) cout<<u<<" "<<v<<endl;
            else cout<<v<<" "<<u<<endl;
        }
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
    int tc; cin>>tc;
    while(tc--)
    {
        solve();
    }
    
}