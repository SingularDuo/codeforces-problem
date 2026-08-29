#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define int long long
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
int binpow(int a, int b)
{
    int res = 1;
    while(b)
    {
        if(b&1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n; cin>>n;
    int res = 0;
    vector<int> ans;
    for(int k = 1; k <= 17; k++)
    {
        int v = binpow(10, k) + 1;
        if(n % v == 0)
        {
            res++;
            ans.pb(n / v);
        }
    }
    cout << res << endl;
    if(res == 0) return;
    sort(all(ans));
    for(auto x : ans) cout << x << ' ';
    cout << endl;
}
 
signed main()
{
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
        auto start = clock();
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
 
    cerr <<endl << (clock() - start) * 1000.0 / CLOCKS_PER_SEC<<' '<<'m'<<'s'<<endl;
 
    return 0;
}