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
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAXN = 200000;
 
 
const int N = 501;
int n, k;
int c[N];
bitset<501> dp[N];
bool used[N];
 
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> c[i];
 
    used[0] = true;
    dp[0][0] = 1;
 
    for (int i = 0; i < n; ++i) {
        for (int j = k; j >= c[i]; --j) {
            if (!used[j - c[i]]) continue;
            used[j] = true;
            dp[j] |= dp[j - c[i]];
            dp[j] |= (dp[j - c[i]] << c[i]);
        }
    }
 
    cout << dp[k].count() << '
';
    for (int i = 0; i <= k; ++i)
        if (dp[k][i])
            cout << i << ' ';
}
 
 
_______TOISETHIVOI_______ {
    fast;
    if (FILE *f = fopen(NAME ".inp", "r")) {
        fclose(f);
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
 
    solve();
    KILL();
}