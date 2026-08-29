/*
Author: duxp
Version: 1
Created at: 2025-12-27 19:37
*/
#include <bits/stdc++.h>
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
#define debug3(x, y, z) cerr << #x g<< " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
#define traillingzero(x) __builtin_ctzll(x)
#define cntbit1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
#define TDN signed main()
 
TDN
{
    fast;
    int n;cin >> n;
    vector<ll> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
 
    if (sum % 3 != 0)
    {
        cout << 0;
        return 0;
    }
 
    ll part = sum / 3;
    ll cur = 0;
    ll cnt1 = 0;
    ll res = 0;
    for (int i = 1; i < n; i++)
    {
        cur += a[i];
        if (cur == 2 * part)
            res += cnt1;
        if (cur == part)
            cnt1++;
    }//haha
 
    cout << res;
}