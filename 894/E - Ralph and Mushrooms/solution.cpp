#include <bits/stdc++.h>
 
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
 
int n, m, s, scc = 0, timeDFS = 0, low[1000005], num[1000005], scc_id[1000005], scc_val[1000005];
struct E {
    int u, v, w;
};
vector<pii> g[1000005];
vector<pii> scc_g[1000005];
vector<E> edge;
stack<int> st;
bool deleted[1000005];
const int LIMIT = 20000;
int value[LIMIT + 5];
int dp[1000005];
 
void pre() {
    value[0] = 0;
    for (int i = 1; i <= LIMIT; i++) {
        value[i] = value[i - 1] + i;
    }
}
int calc_t(long long x) {
    if (x < 1) return 0;
    long double D = 1.0L + 8.0L * (long double)x;
    long double r = (sqrt(D) - 1.0L) / 2.0L;
    long long t = (long long)floor(r);
    if (t > LIMIT) t = LIMIT;
    while (t + 1 <= LIMIT && value[t + 1] <= x) ++t;
    while (t >= 0 && value[t] > x) --t;
    return (int)t;
}
 
int calc_edge(int x) {
    int t = calc_t(x);
    long long prefix = (long long)t * (t + 1) * (t + 2) / 6;
    long long res = (long long)(t + 1) * x - prefix;
    return (int)res;
}
 
void dfs(int u) {
    num[u] = low[u] = ++timeDFS;
    st.push(u);
    for (auto &i : g[u]) {
        int v = i.fi, w = i.se;
        if (deleted[v]) continue;
        if (!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        scc++;
        int v;
        do {
            v = st.top();
            st.pop();
            deleted[v] = true;
            scc_id[v] = scc;
        } while (v != u);
    }
}
 
int solve_dp(int u) {
    if (dp[u] != -1e9) return dp[u];
 
    int best = 0;
    for (auto &i : scc_g[u]) {
        int v = i.fi, w = i.se;
        best = max(best, solve_dp(v) + w);
    }
    dp[u] = scc_val[u] + best;
    return dp[u];
}
void solve() {
    pre();
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        edge.pb({u, v, w});
    }
    cin >> s;
 
    dfs(s);
    for (int i = 1; i <= n; i++) {
        if (!deleted[i]) dfs(i);
    }
 
    for (auto &i : edge) {
        int u = i.u, v = i.v;
        if (scc_id[u] == scc_id[v]) {
            scc_val[scc_id[u]] += calc_edge(i.w);
        }
    }
 
    for (auto &i : edge) {
        int u = i.u, v = i.v;
        if (scc_id[u] != scc_id[v]) {
            scc_g[scc_id[u]].pb({scc_id[v], i.w});
        }
    }
 
    for (int i = 1; i <= scc; i++) {
        sort(all(scc_g[i]));
        scc_g[i].erase(unique(all(scc_g[i])), scc_g[i].end());
    }
 
    fill(dp + 1, dp + scc + 1, (int)-1e9);
    int ans = solve_dp(scc_id[s]);
 
    cout << ans << endl;
}
 
signed main() {
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
    auto start = clock();
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
 
    cerr << endl << (clock() - start) * 1000.0 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}