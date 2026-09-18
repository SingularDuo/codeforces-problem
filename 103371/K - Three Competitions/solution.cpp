/*
====================================
Version: 1
Author: duxp
Date created: 24/03/2026 08:02:48
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
#define _______TOISECOGIAIVOI_______ signed main()
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
int n, m, sz = 0;
set<int> notGraph[MAXN + 5];
set<int> nxt;
bool used[MAXN + 5];
void reset()
{
    nxt.clear();
    for(int i = 1; i <= n; i++)
    {
        notGraph[i].clear();
        nxt.insert(i);
        used[i] = false;
    }
}
void bfs(int s)
{
    used[s] = true;
    queue<int> q;
    q.push(s);
    nxt.erase(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        auto it = nxt.begin();
        while(it != nxt.end()) 
        {
            if(notGraph[u].find(*it) == notGraph[u].end()) 
            {
                int v = *it;
                used[v] = true;
                sz++;
                q.push(v);
                it = nxt.erase(it); 
            } else {
                it++;
            }
        }
    }
}
void solve()
{
    cin>>n>>m;
    reset();
    for(int i = 1; i <= m; i++)
    {
        int u,v; cin>>u>>v;
        notGraph[u].insert(v);
        notGraph[v].insert(u);
    }
    int res = 0;
    vi ans;
    for(int i = 1; i <= n; i++)
    {
        if(!used[i])
        {
            sz = 1;
            bfs(i);
            res++;
            ans.pb(sz);
        }
    }
    cout<<res<<endl;
    sort(nall(ans));
    for(auto i : ans) cout<<i<<" ";
    cout<<endl;
}
_______TOISECOGIAIVOI_______
{
    fast;
    if (FILE *f = fopen(NAME ".inp", "r")) {
        fclose(f);
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    int tc = 1;
    while(tc--)
    {
        solve();
    }
}