/*
Author: Kduckp
Version: 1
Created at: 2025-12-20 09:52
*/
#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
#define traillingzero(x) __builtin_ctzll(x)
#define cntbit1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
#define TDN signed main()
 
int getbit(int x, int k){ return (x >> k) & 1; }
int offbit(int x, int k){ return x & (~(1 << k)); }
 
const ll INF = 1e18;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAXN = 200000;
 
int n, m;
vector<vector<int>> a;
 
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
pair<int, int> ok(int bk)
{
    int full = (1LL << m) - 1;
    vector<int> pos(1LL << m, -1);
    for (int i = 1; i <= n; i++)
    {
        int mask = 0;
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] >= bk)
                mask |= (1LL << (j - 1));
        }
        pos[mask] = i;  
    }
    for (int x = 0; x <= full; x++)
    {
        if (pos[x] == -1) continue;
        for (int y = x; y <= full; y++)
        {
            if (pos[y] == -1) continue;
            if ((x | y) == full)
            {
                return {pos[x], pos[y]};
            }
        }
    }
 
    return {0, 0};
}
 
 
TDN
{
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
    cin >> n >> m;
    int maxVal = -1, maxIndex = -1;
    a.resize(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if(a[i][j] > maxVal)
            {
                maxVal = a[i][j];
                maxIndex = i;
            }
        }
    }
 
    if(m == 1)
    {
        cout<<maxIndex<<" "<<maxIndex;
        return 0;
    }
    int l = 0, r = maxVal;
    pair<int, int> res = {0, 0};
 
    while(l <= r)
    {
        int mid = (l + r) / 2;
        pair<int, int> val = ok(mid);
        pair<int , int> check = {0, 0};
        if(val != check)
        {
            res = val;
            l = mid + 1;
        }
        else r = mid - 1;
    }
 
    cout << res.first << " " << res.second;
}