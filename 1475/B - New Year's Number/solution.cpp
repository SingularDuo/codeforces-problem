#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define endl '
'
#define EYMK signed main()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define precision(x) cout << fixed << setprecision(x)
#define yes() cout << "YES
"
#define no() cout << "NO
"
#define yesno(x) cout << ((x) ? "YES
" : "NO
")
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
#define debugv(v)                \
    cerr << #v << " = ";         \
    trav(x, v) cerr << x << " "; \
    cerr << endl
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const ll INF = 1e18;
const int MAXN = 2e5 + 5;
const int N = 1e6;
const int LOG = 20;
const ld PI = acos(-1.0L);
const ld EPS = 1e-9L;
// direct
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int dx8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy8[] = {0, 0, -1, 1, -1, 1, -1, 1};
ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
ll binpowmod(ll a, ll b, ll mod)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
template <typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }
ll mod_inverse(ll a, ll mod = MOD) { return binpowmod(a, mod - 2, mod); }
template <typename T>
bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }
template <typename T>
bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
int popcount(ll x) { return __builtin_popcountll(x); }
int clz(ll x) { return __builtin_clzll(x); }
int ctz(ll x) { return __builtin_ctzll(x); }
 
vi dp(N + 1, 0);
void preprocess()
{
    for (int i = 1; i < 2020; i++)
        dp[i] = 0;
 
    dp[2020] = dp[2021] = 1;    
    for (int i = 2022; i <= N; i++)
    {
        dp[i] = (dp[i - 2020] + dp[i - 2021]);
        //cout<<i<<" "<<i - 2020<<" "<<dp[i-2020]<<" "<<dp[i-2021]<<endl;
       
        //cout<<endl;
    }
}
void solve()
{
    int n;
    cin >> n;
    yesno(dp[n] != 0);
}
 
EYMK
{
    
    fast();
 
    preprocess();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}