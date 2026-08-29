#include <bits/stdc++.h>
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
const int LARGEPRIME = 998244353;
const int INF_INT = 2147483647;
const ll INF_LL = 2 * 1e18;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int dx8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy8[] = {0, 0, -1, 1, -1, 1, -1, 1};
template<typename T, typename T1> T amax(T &a, T1 b){if(b>a)a=b;return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b<a)a=b;return a;}
 
void solve()
{
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
 
    int ans = 0;
 
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (__builtin_popcount(mask) < 2) continue;
 
        int sum = 0;
        int min_val = INT_MAX;
        int max_val = INT_MIN;
 
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += a[i + 1];
                min_val = min(min_val, a[i + 1]);
                max_val = max(max_val, a[i + 1]);
            }
        }
 
        if (sum >= l && sum <= r && (max_val - min_val) >= x) {
            ans++;
        }
    }
 
    cout << ans << endl;
}
 
EYMK
{
    fast;
 
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
    solve();
 
    return 0;
}