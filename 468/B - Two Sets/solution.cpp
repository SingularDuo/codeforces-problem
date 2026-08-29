#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define vi vector<int>
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define __TOISETHIVOI__ signed main()
 
const int N = 2e5 + 5;
 
vi par, szz;
 
void init_dsu(int n) {
    par.resize(n + 1);
    szz.assign(n + 1, 1);
    for (int i = 0; i <= n; ++i) par[i] = i;
}
 
int findset(int u) {
    if (par[u] == u) return u;
    return par[u] = findset(par[u]);
}
 
void join(int u, int v) {
    u = findset(u);
    v = findset(v);
    if (u != v) {
        if (szz[u] < szz[v]) swap(u, v);
        par[v] = u;
        szz[u] += szz[v];
    }
}
 
__TOISETHIVOI__ {
    fast;
    int n, a, b;
    cin >> n >> a >> b;
 
    vi p(n);
    unordered_map<int, int> val_to_index;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        val_to_index[p[i]] = i;
    }
 
    init_dsu(n);
    for (int i = 0; i < n; ++i) {
        if (val_to_index.count(a - p[i])) {
            join(i, val_to_index[a - p[i]]);
        }
        if (val_to_index.count(b - p[i])) {
            join(i, val_to_index[b - p[i]]);
        }
    }
 
    vector<int> color(n, -1);
    vector<vector<int>> comp(n);
 
    for (int i = 0; i < n; ++i) {
        comp[findset(i)].push_back(i);
    }
 
    for (int root = 0; root < n; ++root) {
        if (comp[root].empty()) continue;
 
        bool can_a = true, can_b = true;
 
        for (int idx : comp[root]) {
            int x = p[idx];
            if (!val_to_index.count(a - x)) can_a = false;
            if (!val_to_index.count(b - x)) can_b = false;
        }
 
        if (!can_a && !can_b) {
            cout << "NO
";
            return 0;
        }
 
        int assign_color = can_a ? 0 : 1;
        for (int idx : comp[root]) {
            color[idx] = assign_color;
        }
    }
 
    cout << "YES
";
    for (int i = 0; i < n; ++i) cout << color[i] << " ";
    cout << "
";
 
    return 0;
}