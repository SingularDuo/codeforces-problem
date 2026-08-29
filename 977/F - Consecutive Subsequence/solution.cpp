#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
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
#define NAME "duxp"
const int LARGEPRIME = 998244353;
const int INF_INT = 2147483647;
const ll INF_LL = 2 * 1e18;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int dx8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy8[] = {0, 0, -1, 1, -1, 1, -1, 1};
 
void solve()
{
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
 
    unordered_map<int, int> dp;      
    unordered_map<int, int> last_pos;  
    vector<int> pre(n, -1);
 
    int best_len = 0;
    int best_pos = -1;
 
    for(int i = 0; i < n; i++)
    {
        int x = a[i];
        if(dp.count(x - 1))
        {
            dp[x] = dp[x - 1] + 1;
            pre[i] = last_pos[x - 1];
        }
        else
        {
            dp[x] = 1;
            pre[i] = -1;
        }
 
        last_pos[x] = i;
 
        if(dp[x] > best_len)
        {
            best_len = dp[x];
            best_pos = i;
        }
    }
 
    cout << best_len << endl;
 
    vector<int> res;
    int cur = best_pos;
    while(cur != -1)
    {
        res.pb(cur + 1); 
        cur = pre[cur];
    }
 
    reverse(all(res));
    for(int x : res) cout << x << " ";
}
 
 
EYMK
{
    fast;
    if (FILE *f = fopen(NAME ".inp", "r")) {
        fclose(f);
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    solve();
    return 0;
}