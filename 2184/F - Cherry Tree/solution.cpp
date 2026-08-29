#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 200001;
 
int n;
vector <int> graph[MAXN];
vector <bool> dp[MAXN];
 
void merge_dp(vector <bool>& lhs, vector <bool>& rhs, vector <bool>& result) {
    for (int i = 0; i < 3; ++i) {
        if (!lhs[i]) continue;
        for (int j = 0; j < 3; ++j) {
            if (!rhs[j]) continue;
            result[(i + j) % 3] = true;
        }
    }
}
 
void dfs(int u, int p) {
    vector <int> child;
 
    for (auto v : graph[u]) if (v != p) {
        dfs(v, u);
        child.push_back(v);
    }
 
    dp[u].resize(3);
 
    if (!child.empty()) {
        dp[u][0] = true;
        for (auto v : child) {
            vector <bool> result(3, false);
 
            merge_dp(dp[u], dp[v], result);
            dp[u] = result;
        }
    }
 
    dp[u][1] = true;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            graph[i].clear();
            dp[i].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
 
        dfs(1, -1);
 
        cout << (dp[1][0] ? "YES" : "NO") << '
';
    }
 
    return 0;
}