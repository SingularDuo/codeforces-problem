#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define int long long
#define EYMK signed main()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define each(x) for(auto & i : x)
#define vvi vector<vi>
#define pb push_back
#define endl '
'
#define yesno(x) cout << ((x) ? "YES
" : "NO
")
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
 
const int MOD = 1e9 + 7;
const int LARGEPRIME = 998244353;
const int INF_INT = 2147483647;
const ll INF_LL = 2 * 1e18;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int dx8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy8[] = {0, 0, -1, 1, -1, 1, -1, 1};
 
void solve()
{
    int n; cin>>n;
    ll s = 0;
    vi od;
    for(int i = 0; i < n; i++)
    {
        int x; cin>>x;
        s += x;
        if(x % 2 != 0)
        {
            od.pb(x);
        }
    }
    if(od.empty())
    {
        cout<<0<<endl;
        return;
    }
    sort(all(od));
    ll ss = 0, del = od.size() / 2;
    for(int i = 0; i < del; ++i)
    {
        ss+=od[i];
    }
    int v = s - ss;
    cout<<v <<endl;
 
}
 
EYMK
{
    fast;
 
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    int tc; cin>>tc;
    while(tc--) solve();
    return 0;
}