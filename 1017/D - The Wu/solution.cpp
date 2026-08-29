/*
========================================================
   Author  : duxp
   Purpose : Competitive Programming
   Note    : Think first. Code once.
   Rule    : Once AC, never touch
   Created at: 2026-01-20 15:07
========================================================
*/
#include <bits/stdc++.h>
 
#ifdef __APPLE__
#include <mach/mach.h>
#else
#include <unistd.h>
#endif
 
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
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mem(a, x) memset(a, x, sizeof(a))
 
#ifndef ONLINE_JUDGE
bool __LOCAL__ = true;
#else
bool __LOCAL__ = false;
#endif
 
#define dbg(x)     \
    if (__LOCAL__) \
    cerr << #x << " = " << (x) << '
'
#define dbg2(x, y)             \
    if (__LOCAL__)             \
    cerr << #x << " = " << (x) \
         << ", " << #y << " = " << (y) << '
'
#define dbg3(x, y, z)                  \
    if (__LOCAL__)                     \
    cerr << #x << " = " << (x)         \
         << ", " << #y << " = " << (y) \
         << ", " << #z << " = " << (z) << '
'
#define el         \
    if (__LOCAL__) \
    cerr << '
'
 
template <typename T>
void dbgvec(const vector<T> &v, const string &name = "")
{
    if (!__LOCAL__) return;
    if (!name.empty()) cerr << name << " = ";
    cerr << "[ ";
    for (auto &x : v) cerr << x << " ";
    cerr << "]
";
}
 
const ll OO = 1e18;
const int oo = 1e9;
const int MOD1 = 1000000007;
const int MOD9 = 998244353;
const int MAXN = 200000;
 
int n, m, q;
int a[20];
 
map<int, int> dem;
vector<vector<int>> ma;
 
int main()
{
    fast;
 
    // Codeforces không dùng freopen
    // #ifndef ONLINE_JUDGE
    // freopen(NAME ".inp", "r", stdin);
    // freopen(NAME ".out", "w", stdout);
    // #endif
 
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
 
    int nmask = 1 << n;
    int mx = n * 100;
 
    ma.assign(nmask, vector<int>(mx + 1, 0));
 
    for (int i = 0; i < m; i++)
    {
        string s; cin >> s;
        int mask = 0;
        for (int j = 0; j < n; j++)
            if (s[j] == '1')
                mask |= (1 << j);
        dem[mask]++;
    }
 
    for (int t = 0; t < nmask; t++)
    {
        for (auto &it : dem)
        {
            int s = it.first;
            int cnt = it.second;
 
            int x = s ^ t;
            int sum = 0;
            for (int j = 0; j < n; j++)
                if (((x >> j) & 1) == 0)
                    sum += a[j];
 
            if (sum <= mx)
                ma[t][sum] += cnt;
        }
 
        for (int i = 1; i <= mx; i++)
            ma[t][i] += ma[t][i - 1];
    }
 
    while (q--)
    {
        string s;
        int k;
        cin >> s >> k;
 
        int mask = 0;
        for (int j = 0; j < n; j++)
            if (s[j] == '1')
                mask |= (1 << j);
 
        if (k > mx) k = mx;
        cout << ma[mask][k] << '
';
    }
 
    return 0;
}
// I LOVE MYSELF