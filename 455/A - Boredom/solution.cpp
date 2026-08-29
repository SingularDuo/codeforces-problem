#include<bits/stdc++.h>
 
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
int cnt[100000 + 5];
                                _______TOISETHIVOI_______
{
    fast;
    if (FILE *f = fopen(NAME ".inp", "r")) {
        fclose(f);
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    int n; cin>>n;
    vi a(n + 1);
    for(int i =1 ; i <=n; i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    vi dp(1e5 + 5, 0);
    dp[0] = 0;
    dp[1] = cnt[1];
    int res = -oo;
    for(int i = 2; i <= 1e5; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
        res = max(res, dp[i]);
    }
    cout<<res;
 
    KILL();
}