#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int MOD = 1e9 + 7;
 
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 0) { 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
 
    bool vis[n + 1];
    memset(vis, false, sizeof(vis));
    vector<int> comp_sizes;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int cnt = 0;
            stack<int> st;
            st.push(i);
            vis[i] = 1;
            while (!st.empty()) {
                int u = st.top(); st.pop();
                cnt++;
                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        st.push(v);
                    }
                }
            }
            comp_sizes.push_back(cnt);
        }
    }
 
    ll total = binpow(n, k);
    ll bad = 0;
    for (int sz : comp_sizes) {
        bad = (bad + binpow(sz, k)) % MOD;
    }
    ll ans = (total - bad + MOD) % MOD;
    cout << ans << "
";
}