/*
Author: Kduckp
Version: 1
Created at: 2025-12-16 14:39
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
int getbit(int x, int k){return (x >> k) & 1;}
int offbit(int x, int k){return x & (~(1 << k));}
const ll INF = 1e18;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAXN = 200000;
 
TDN
{
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(all(a));
    int minValue = a[0], maxValue = a[n - 1];
    int l = 0, r = n - 1;
    ll cntL = 1, cntR = 1;
    while (l < r && k > 0) {
        if (cntL <= cntR) 
        {
            int nextVal = a[l + 1];
            ll need = 1LL * (nextVal - a[l]) * cntL;
 
            if (need <= k) 
            {
                k -= need;
                l++;
                cntL++;
            } 
            else 
            {
                ll add = k / cntL;
                a[l] += add;
                k = 0;
            }
        } 
        else 
        {
            int nextVal = a[r - 1];
            ll need = 1LL * (a[r] - nextVal) * cntR;
 
            if (need <= k) {
                k -= need;
                r--;
                cntR++;
            } 
            else {
                ll sub = k / cntR;
                a[r] -= sub;
                k = 0;
            }
        }
    }
    cout << max(0LL, a[r] - a[l]);
 
}