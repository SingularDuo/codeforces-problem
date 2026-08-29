#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vi>
#define vii vector<pii>
#define ull unsigned long long
#define ld long double
#define setp(x) fixed << setprecision(x)
#define setp2(x, y) fixed << setprecision(x) << y
#define endl "
"
#define __TOISETHIVOI__ signed main()
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define yes cout << "YES
"
#define no cout << "NO
"
#define YESNO(x) cout << ((x) ? "YES
" : "NO
")
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define kill cout << "end" << endl;
#define traillingzero(x) __builtin_ctzll(x)
#define count_bit_1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
 
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = INT_MAX;
const int N = 2e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;
 
void OJ() {
    fast;
}
void THEMIS() {
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}
 
int n, m;
vi g[N], k;
int low[N], num[N], out[N], h[N], par[N], dep;
 
void dfs(int u, int pre) {
    h[u] = h[pre] + 1;
    par[u] = pre;
    num[u] = ++dep;
    low[u] = num[u];
    for (int v : g[u]) {
        if (v == pre) continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
    out[u] = dep;
}
 
bool is_ancestor(int u, int v) {
    return num[u] <= num[v] && out[u] >= out[v];
}
 
void sol() {
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
 
    memset(num, 0, sizeof(num));
    memset(low, 0, sizeof(low));
    dep = 0;
    dfs(1, 0);
 
    while (m--) {
        int ki;
        cin >> ki;
        vi curr(ki);
        int deepest = 1;
        for (int i = 0; i < ki; i++) {
            cin >> curr[i];
            if (h[curr[i]] > h[deepest]) deepest = curr[i];
        }
 
 
        bool ok = true;
        for (int i = 0; i < ki; i++) {
            int u = curr[i];
            if (u == 1) continue; 
            if (!is_ancestor(par[u], deepest)) {
                ok = false;
                break;
            }
        }
 
        YESNO(ok);
    }
}
 
__TOISETHIVOI__ {
    //THEMIS();
    int t = 1;
    // cin >> t;
    while (t--) sol();
}