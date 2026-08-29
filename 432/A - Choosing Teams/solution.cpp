#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
 
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int N = 1e5;
const int MAXA = 1e9;
const int INF = 1e9; // change to 1e18 if using long long 
void solve()
{
    int n, k; cin>>n>>k;
    
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    
    if(k > 5)
    {
        cout<<0;
        return;
    }
    int cnt = 0, AtMost = 5 - k;
    for(int i = 0; i < n; i++)
    {
        if(a[i] <= AtMost) cnt++;
    }
    cout<<cnt  / 3;
 
}
 
signed main()
{
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
 
    return 0;
}
// TDN LOVER