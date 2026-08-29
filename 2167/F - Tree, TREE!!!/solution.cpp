#include <bits/stdc++.h>
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
#define TDN signed main()
 
void solve() {
    int n, k; cin>>n>>k;
    vector<vector<int>> g(n+1);
    vector<pii> ed;
 
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        ed.pb({u, v});
    }
    vector<int> par(n+1, 0);
    vector<int> ord;
    ord.assign(n, 0);
    ord.push_back(1);
    par[1] = 0;
    for (int idx = 0; idx < ord.size(); ++idx) {
        int v = ord[idx];
        for (int to : g[v]) if (to != par[v]) {
            par[to] = v;
            ord.push_back(to);
        }
    }
    vector<int> sub(n+1, 0);
    for (int i = (int)ord.size() - 1; i >= 0; i--) {
        int v = ord[i];
        sub[v] = 1;
        for (int to : g[v]) if (to != par[v]) sub[v] += sub[to];
    }
    ll ans = 0;
    if (n >= k) ans += n;
    for (auto &e : ed) {
        int u = e.fi, v = e.se;
        int con = (par[u] == v ? u : (par[v] == u ? v : -1));
        if (con == -1) {
            continue;
        }
        int s = sub[con];
        int last = n - s;
        if (s >= k) ans += last;
        if (last >= k) ans += s;
    }
 
    cout << ans << '
';
}
 
TDN {
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    int tc;
    if (!(cin >> tc)) return 0;
    while (tc--) solve();
    return 0;
}