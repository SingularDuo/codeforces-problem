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
const int MAXN = 100000;
int n, k;
int dp[MAXN + 5];
                                _______TOISETHIVOI_______
{
    fast;
    if (FILE *f = fopen(NAME ".inp", "r")) {
        fclose(f);
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    cin>>n>>k;
    dp[0] = 1;// số cách để ăn hết i bông hoa
    for(int i = 1; i <=  MAXN; i++) 
    {
        //dp[i] = (dp[i - 1] % MOD + dp[max(0LL, i - k)] % MOD)%MOD;
        dp[i] = dp[i - 1] % MOD;
        if(i - k >= 0)
        {
            dp[i] = (dp[i] % MOD + dp[i - k] % MOD) % MOD;
        }
    }
    vi f(MAXN + 1,0);
    for(int i = 1; i <= MAXN; i++)
    {
        f[i] = (f[i - 1] % MOD + dp[i] % MOD) % MOD;
    }
    while(n -- )
    {
        int a,b; cin>>a>>b;
        cout<<(f[b] - f[a - 1] + MOD * MOD) % MOD<<endl;
    }
    KILL();
}