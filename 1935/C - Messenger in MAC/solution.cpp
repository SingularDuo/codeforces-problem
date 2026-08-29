/*
Author: duxp
Version: 1
Created at: 2026-01-07 15:00
*/
#include <bits/stdc++.h>
 
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
/*
* giả sử chọn ra k vật p1,p2,...,pk
* cách tối ưu nhất là lấy theo thứ tự b[pi] tăng dần vì các phần tử xếp kề nhau sẽ cho difference bé nhất (abs)
 
*/
bool cmp(pii a, pii b)
{
    if(a.se != b.se) return a.se < b.se;
    else return a.fi < b.fi;
}
void solve()
{
    int n, l; cin>>n>>l;
    vector<pii> a(n + 1);
    for(int i = 1; i <= n; i++) cin>>a[i].fi>>a[i].se;
    sort(all(a), cmp);
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        int sum = 0;
        multiset<int> ms;
        for(int j = i; j <= n; j++)
        {
            sum+=a[j].fi;
            ms.insert(a[j].fi);
            while(!ms.empty() && a[j].se - a[i].se + sum > l)
            {
                int mx = *ms.rbegin();
                sum -= mx;
                auto it = ms.find(mx);
                ms.erase(it);
            }
            maximize(res, (int)ms.size());
        }
    }
    cout<<res<<endl;
}
TDN
{
    fast;
    string fname = string(NAME);
    if (fopen((fname + ".inp").c_str(), "r")) {
        freopen((fname + ".inp").c_str(), "r", stdin);
        freopen((fname + ".out").c_str(), "w", stdout);
    }
    int tc; cin>>tc;
    while(tc--)
    {
        solve();
    }
    
    KILL();
}