#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
void dfs(int u, int p, vector<vector<int>> &g, vector<ll> &v, vector<ll> &pval, vector<ll> &thr, vector<int> &lvl, ll &mn, ll &mx) {
    thr[u] = (lvl[u] % 2 == 0) ? pval[u] - mn : mx - pval[u];
 
    ll prevMn = mn, prevMx = mx;
    mn = min(mn, pval[u]);
    mx = max(mx, pval[u]);
 
    for (int x : g[u]) {
        if (x == p) continue;
        lvl[x] = lvl[u] + 1;
        pval[x] = (lvl[x] % 2 == 0) ? pval[u] + v[x] : pval[u] - v[x];
        dfs(x, u, g, v, pval, thr, lvl, mn, mx);
    }
 
    mn = prevMn;
    mx = prevMx;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> v(n + 1);
        for (int i = 1; i <= n; i++) cin >> v[i];
 
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, x;
            cin >> u >> x;
            g[u].pb(x);
            g[x].pb(u);
        }
 
        vector<ll> pval(n + 1), thr(n + 1);
        vector<int> lvl(n + 1);
        ll mn = 0, mx = 0;
 
        lvl[1] = 0;
        pval[1] = v[1];
        dfs(1, 0, g, v, pval, thr, lvl, mn, mx);
 
        for (int i = 1; i <= n; i++) cout << thr[i] << " ";
        cout << "
";
    }
    return 0;
}