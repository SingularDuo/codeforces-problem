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
 
void solve()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n + 1), pref(n + 1);
        string s;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        cin >> s;
        s = '0' + s;
 
        vi ans(2, 0);
        for (int i = 1; i <= n; ++i) {
            ans[s[i] - '0'] ^= a[i];
            pref[i] = pref[i - 1] ^ a[i];
        }
 
        int q;
        cin >> q;
        int massxor = 0;
        while (q--) {
            int tp;
            cin >> tp;
            if (tp == 1) {
                int l, r;
                cin >> l >> r;
                massxor ^= pref[r] ^ pref[l - 1];
            } else {
                int g;
                cin >> g;
                cout << (massxor ^ ans[g])<<" ";
            }
        }
        cout<<endl;
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