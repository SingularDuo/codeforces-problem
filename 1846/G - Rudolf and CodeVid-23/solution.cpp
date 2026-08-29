/*
====================================
Version: 1
Author: duxp
Date created: 22/03/2026 10:13:24
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
const int FULL = 1024;
struct med
{
    int d;
    string t1, t2;
};
bool s1 = true;
vector<med> a;
int n, m;
string sym;
namespace sub1 
{
    void solve() 
    {
        int start_mask = 0;
        for (int i = 0; i < n; i++) 
        {
            if (sym[i] == '1') start_mask |= (1 << i);
        }
        int max_mask = (1 << n);
        vector<int> dp(max_mask, oo); 
        dp[start_mask] = 0;
        vector<int> t1_masks(m + 1, 0);
        for(int i = 1; i <= m; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                if(a[i].t1[j] == '1') t1_masks[i] |= (1 << j);
            }
        }
 
        for (int i = max_mask - 1; i >= 0; i--) 
        {
            if (dp[i] == oo) continue;
            for (int j = 1; j <= m; j++) 
            {
                int v = i & (~t1_masks[j]);
                if (dp[v] > dp[i] + a[j].d) dp[v] = min(dp[v], dp[i] + a[j].d);
            }
        }
        if (dp[0] == oo) cout << -1 << endl;
        else cout << dp[0] << endl;
    }
}
long long binToDec(const string &s) 
{
    long long res = 0;
    for (char c : s) {
        res = res * 2 + (c - '0');
    }
    return res;
}
namespace brute
{
    vpii g[MAXN + 5];
 
    
    int d[FULL + 5];
    void dijkstra(int start_mask)
    {
        fill(d, d + (1 << n), oo);
        priority_queue<pii> pq;
 
        d[start_mask] = 0;
        pq.push({0, start_mask});
 
        while(!pq.empty())
        {
            int u = pq.top().se;
            int du = pq.top().fi;
            pq.pop();
            du = -du;
            if(du > d[u]) continue;
            for(auto &edge : g[u])
            {
                int v = edge.fi;
                int w = edge.se;
 
                if(d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                    pq.push({-d[v], v});
                }
            }
        }
 
        if(d[0] == oo) cout << -1 << endl;
        else cout << d[0] << endl;
    }
 
    void solve()
    {
        int max_mask = (1 << n);
        for(int i = 0; i < max_mask; i++) g[i].clear();
 
        for(int i = 0; i <= max_mask - 1; i++)
        {
            for(auto &j : a)
            {
                int fix = binToDec(j.t1), cause = binToDec(j.t2);
                int maskB = (i & (~fix)) | cause;
                g[i].pb({maskB, j.d});
            }
        }
 
        int start_mask = binToDec(sym);
        dijkstra(start_mask);
 
    }
}
void solve()
{
    cin>>n>>m;
    cin>>sym;
    a.resize(m + 1);
    for(int i = 1; i <= m; i++)
    {
         cin>>a[i].d>>a[i].t1>>a[i].t2;
         if(binToDec(a[i].t2) != 0) s1 = false;
    }
    if(s1)
    {
        sub1::solve();
        return;
    }
    else brute::solve();
    
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