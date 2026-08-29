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
 
template<typename T, typename T1>T amax(T &a, T1 b){if(b>a)a=b;return a;}
template<typename T, typename T1>T amin(T &a, T1 b){if(b<a)a=b;return a;}
 
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1), f(n+1, 0), xo(n+1, 0);
 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i-1] + a[i];
        xo[i] = xo[i-1] ^ a[i];
    }
 
      while (q--) {
        int L, R;
        cin >> L >> R;
 
        ll total_sum = f[R] - f[L - 1];
        ll total_xor = xo[R] ^ xo[L - 1];
        ll val = total_sum - total_xor;
 
        if (val == 0) {
            cout << L << " " << L << endl;
            continue;
        }
 
        pii ans = {L, R};
        int i = L;
 
        for (int j = L + 1; j <= R; j++) {
            ll cur_sum = f[j] - f[i - 1];
            ll cur_xor = xo[j] ^ xo[i - 1];
            ll tmp = cur_sum - cur_xor;
 
            while (tmp == val && i <= j) {
                if (j - i < ans.second - ans.first) {
                    ans = {i, j};
                }
                if (ans.second - ans.first == 0) break;
                i++;
                if (i <= j) {
                    cur_sum = f[j] - f[i - 1];
                    cur_xor = xo[j] ^ xo[i - 1];
                    tmp = cur_sum - cur_xor;
                } else break;
            }
            if (ans.second - ans.first == 0) break;
        }
 
        cout << ans.first << " " << ans.second << endl;
    }
}
 
EYMK
{
    fast;
 
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    start_time
    int tc; cin>>tc;
    while(tc--)
    {
        solve();
    }
    cerr_time
    return 0;
}