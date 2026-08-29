/*
Author: duxp
"IT WORKED ON MY MACHINE!"
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define int ll
#define ld long double 
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define nall(x) (x).begin(), (x).end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define vpii vector<pii>
#define endl '
'
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, x) memset((a), (x), sizeof((a)))
 
#define _______TOISECOGIAIVOI_______ signed main()
#define KILL() exit(0)
#define NAME "duxp"
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
template <typename T> inline int getbit(T x, int k) { return (x >> k) & 1; }
template <typename T> inline T onbit(T x, int k) { return x | (T(1) << k); }
template <typename T> inline T offbit(T x, int k) { return x & ~(T(1) << k); }
 
const ll OO = 1e18;
const int oo = 1e9;
const int LOG = 20;
const int MOD = 1e9 + 7;
const int MAXN = 200000;
int st[MAXN + 5][LOG + 5];
int lg2[MAXN + 5];
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
void precompute_logs() 
{
    lg2[1] = 0;
    for (int i = 2; i < MAXN; i++)
        lg2[i] = lg2[i / 2] + 1;
}
void build(vi &f, int n)
{
    for(int i = 1; i <= n; i++) st[i][0] = f[i];
    for (int i = 1; i <= LOG; i++) 
    {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            st[j][i] = gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
        }
    }
}
int get(int l, int r)
{
    int k = lg2[r - l + 1];
    return gcd(st[l][k], st[r - (1 << k) + 1][k]);
}
void solve()
{
    int n,q ; cin>>n>>q;
    vi a(n + 1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    vi f(n + 3);
    for (int i = 1; i < n; i++) f[i] = abs(a[i] - a[i + 1]);
    build(f, n - 1);
    while(q--)
    {
        int l,r; cin>>l>>r;
        if(l == r) cout<<0<<" ";
        else cout<<get(l, r - 1)<<" ";
    }
    cout<<endl;
}
_______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    precompute_logs();
    int tc; cin>>tc;
    while(tc--)
    {
        solve();
    }
 
    return 0;
}