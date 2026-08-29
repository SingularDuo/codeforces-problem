/*
Author: duxp
Version: 1
Created at: 2025-12-29 10:28
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
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
 
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
inline bool minimize(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
 
template <typename T>
inline bool maximize(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
 
const ll INF = 4e18;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAXN = 300000;
const int LOG = 19;
inline int log2int(int x)
{
    return 63 - __builtin_clzll(x); // chatgpt
}
int get_max(int l, int r, vector<vi> &st)
{
    int k = log2int(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}
void solve()
{
    int n;
    cin >> n;
    vi a(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vi f(n + 1, 0);
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] + i;
    ll sumRange = 0;
    for (int l = 1; l <= n; l++)
    {
        int sumRight = f[n] - f[l];
        sumRange += sumRight - l * (n - l);
    }
    vi leftBound(n + 1, 1), rightBound(n + 1, n);
    deque<int> dq;
    a[0] = a[n + 1] = -INF;
    dq.push_back(0);
    for (ll i = 1; i <= n; i++)
    {
        while (a[dq.back()] > a[i])
        {
            rightBound[dq.back()] = i - 1;
            dq.pop_back();
        }
        leftBound[i] = dq.back() + 1;
        dq.push_back(i);
    }
 
    vector<vi> st(LOG + 1, vi(n + 2));
    for (int i = 1; i <= n; i++)
        st[0][i] = a[i];
    for (int j = 1; j <= LOG; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
    }
 
    ll sumKhe = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = leftBound[i] - 1;
        int y = rightBound[i] + 1;
        int x = 0;
        if (k > 0)
        {
            int l = k;
            for (int j = LOG; j >= 0; j--)
            {
                int len = (1 << j);
                int nl = l - len + 1;
                if (nl >= 1 && get_max(nl, l, st) < a[i])
                {
                    l = nl - 1;
                }
            }
            x = l;
        }
        sumKhe += 1LL * (k - x) * (y - i);
    }
    //cout << sumRange << " " << sumKhe << endl;
    cout<<sumRange - sumKhe<<endl;
}
TDN
{
    fast;
    string fname = string(NAME);
    if (fopen((fname + ".inp").c_str(), "r"))
    {
        freopen((fname + ".inp").c_str(), "r", stdin);
        freopen((fname + ".out").c_str(), "w", stdout);
    }
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    KILL();
}