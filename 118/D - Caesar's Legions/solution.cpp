#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define all(x) x.begin() + 1, x.end()
#define nall(x) x.begin(), x.end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
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
const int MOD = 100000000;
const int MOD2 = 998244353;
const int MAXN = 200000;
int dp[105][105][2][210];
                                _______TOISETHIVOI_______
{
    fast;
    if (FILE *f = fopen(NAME ".inp", "r")) {
        fclose(f);
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    int n, m, k1, k2; cin>>n>>m>>k1>>k2;
    dp[1][0][0][1] = 1;
    dp[0][1][1][1] = 1;
    for(int f = 0; f <= n; f++)
    {
        for(int h = 0; h <= m; h++)
        {
            // ng ng
            for(int k = 2; k <= k1; k++)
            {
                if(f > 0) dp[f][h][0][k] = (dp[f][h][0][k] + dp[f-1][h][0][k-1]) % MOD;
            }
            // ng ngua
            for(int kk = 1; kk <= k2; kk++)
            {
                if(f > 0) dp[f][h][0][1] = (dp[f][h][0][1] + dp[f-1][h][1][kk]) % MOD;
            }
            // ngua ngua
            for(int k = 2; k <= k2; k++)
            {
                if(h > 0) dp[f][h][1][k] = (dp[f][h][1][k] + dp[f][h-1][1][k-1]) % MOD;
            }
            // ngua ng
            for(int kk = 1; kk <= k1; kk++)
            {
                if(h > 0) dp[f][h][1][1] = (dp[f][h][1][1] + dp[f][h-1][0][kk]) % MOD;
            }
        }
    }
 
    int ans = 0;
    for(int k = 1; k <= k1; k++) ans = (ans + dp[n][m][0][k]) % MOD;
    for(int k = 1; k <= k2; k++) ans = (ans + dp[n][m][1][k]) % MOD;
 
    cout << ans;
    KILL();
}
/*
dp[f][h][i][k]
số cách sắp xếp thỏa mãn khi i là quân cuối (i là 0 hoặc 1 thể hiện người và ngựa), 
khi đó đã dùng f người và h ngựa, và k là số quân i liên tiếp ở cuối
*/