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
const int LARGEPRIME = 998244353;
const int INF_INT = 2147483647;
const ll INF_LL = 2 * 1e18;
const int dx[] = {-1, 1, 0, 0};
#define start_time auto start = clock();
#define cerr_time cerr <<endl<< "Time: " << (clock() - start) * 1000.0 / CLOCKS_PER_SEC << " ms
";
const int dy[] = {0, 0, -1, 1};
const int dx8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy8[] = {0, 0, -1, 1, -1, 1, -1, 1};
template<typename T, typename T1>T amax(T &a, T1 b){if(b>a)a=b;return a;}
template<typename T, typename T1>T amin(T &a, T1 b){if(b<a)a=b;return a;}
 
const int N = 1e5 + 5;
 
ll a[N], p[N], x[N];
 
ll calc(ll l, ll r) {
    return p[r] - p[l - 1] - (x[r] ^ x[l - 1]);
}
 
void solve()
{
    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> vec = {0}; // lưu các vị trí != 0
 
        p[0] = x[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            p[i] = p[i - 1] + a[i];
            x[i] = x[i - 1] ^ a[i];
            if (a[i]) vec.push_back(i);
        }
        vec.push_back(n + 1); // sentinel
 
        while (q--) {
            int L, R;
            cin >> L >> R;
 
            int l = lower_bound(all(vec), L) - vec.begin();
            int r = upper_bound(all(vec), R) - vec.begin() - 1;
 
            // khong co phan tu != 0
            if (!(1 <= l && r < (int)vec.size() && l <= r)) {
                cout << L << ' ' << L << endl;
                continue;
            }
 
            ll fmax = calc(vec[l], vec[r]);
            pii ans = {vec[r] - vec[l] + 1, vec[l]}; // do dai + bat dau
 
            for (int u = l; u <= min(r, l + 32 - 1); u++) {
                for (int v = r; v >= max(u, r - 32 + 1); v--) {
                    if (calc(vec[u], vec[v]) == fmax) {
                        ans = min(ans, {vec[v] - vec[u] + 1, vec[u]});
                    }
                }
            }
            cout << ans.se << ' ' << ans.se + ans.fi - 1 << endl;
        }
        vec.clear();
    }
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