/*
Author: duxp
Version: 1
Created at: 2026-01-14 19:58
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define int long long 
#define pb push_back
#define all(x) x.begin() + 1, x.end()
#define nall(x) x.begin(), x.end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
 
#define trailingzero(x) __builtin_ctzll(x)
#define cntbit1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
 
#define TDN signed main()
#define KILL() exit(0)
#define NAME "task"
 
template <typename T>
inline int getbit(T x, int k) { return (x >> k) & 1; }
 
template <typename T>
inline T onbit(T x, int k) { return x | (T(1) << k); }
 
template <typename T>
inline T offbit(T x, int k) { return x & ~(T(1) << k); }
 
template <typename T>
inline bool minimize(T &a, const T &b) {
    if (a > b) { a = b; return true; }
    return false;
}
 
template <typename T>
inline bool maximize(T &a, const T &b) {
    if (a < b) { a = b; return true; }
    return false;
}
 
const ll INF = 1e18;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAXN = 200000;
 
TDN
{
    fast;
    string fname = string(NAME);
    if (fopen((fname + ".inp").c_str(), "r")) {
        freopen((fname + ".inp").c_str(), "r", stdin);
        freopen((fname + ".out").c_str(), "w", stdout);
    }
    int n; cin>>n;
    int a[15][15][15];
    for(int x = 1; x <= n; x++)
    {
        for(int y = 1; y  <= n; y++)
        {
            for(int z = 1; z <= n; z++) cin>>a[x][y][z];
        }
    }   
    const int MAXMASK = (1<<n) - 1;
    vector<vi> dp(MAXMASK + 1, vi(MAXMASK + 1, INF));
    dp[0][0] = 0;
    for(int y = 0; y <= MAXMASK; y++)
    {
        for(int z = 0; z <= MAXMASK; z++)
        {
            if(cntbit1(y) != cntbit1(z)) continue;
            if(dp[y][z] == INF) continue;
            int k = cntbit1(y) + 1;
            //debug(k);
            if(k > n) continue; // deo can nhieu den vay dau
            for(int i = 1; i <= n; i++)
            {
                if(getbit(y,i - 1))continue;
                for(int j = 1; j <= n; j++)
                {
                    if(getbit(z,j - 1)) continue;
                    int newY = y | (1 << (i-1));
                    int newZ = z | (1 << (j-1));
                    dp[newY][newZ] = min(dp[newY][newZ],  dp[y][z] + a[k][i][j]);
                    //debug2(newY, newZ);
                    //debug(dp[newY][newZ]);
                }
            }
        }
    }
    cout<<dp[MAXMASK][MAXMASK];
    KILL();
}