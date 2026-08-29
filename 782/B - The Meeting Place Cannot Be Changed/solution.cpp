/*
Author: Kduckp
Version: 1
Created at: 2025-12-15 23:27
*/
#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
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
int getbit(int x, int k){return (x >> k) & 1;}
int offbit(int x, int k){return x & (~(1 << k));}
const ll INF = 2e9;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAXN = 200000;
int n;
int x[MAXN], v[MAXN];
bool ok(double time)
{
    double L = -1e18, R = 1e18;
    for(int i = 1; i <= n; i++)
    {
        L = max(L, x[i] - time * v[i]);
        R = min(R, x[i] + time * v[i]);
    }
    return L <= R;
}
 
 
 
TDN
{
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= n; i++) cin >> v[i];
 
    double l = 0, r = 1e9;
    for(int it = 0; it < 100; it++)
    {
        double mid = (l + r) / 2;
        if(ok(mid)) r = mid;
        else l = mid;
    }
 
    cout << fixed << setprecision(10) << r;
}