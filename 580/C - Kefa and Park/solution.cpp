#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using vi = vector<int>;
 
const int MAXN = 1e5 + 5;
vi g[MAXN];
bool cat[MAXN];
int n, m;
int res = 0;
 
void dfs(int u, int parent, int catcnt) {
    if (cat[u]) catcnt++;
    else catcnt = 0;
 
    if (catcnt > m) return;
 
    bool leaf = true;
    for (int v : g[u]) {
        if (v != parent) {
            leaf = false;
            dfs(v, u, catcnt);
        }
    }
 
    if (leaf) res++;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        cat[i] = (x == 1);
    }
 
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    dfs(1, 0, 0);
    cout << res << '
';
    return 0;
}