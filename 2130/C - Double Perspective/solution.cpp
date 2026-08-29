/*
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⡿⢿⡿⠿⠿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⡿⣿⣿
Created on : hh/mm/ss/dd/mm/yy by kduckp
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vi>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '
'
#define FOR(i, n) for (int i = 1; i <= (n); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define EACH(x, a) for (auto& x : a)
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define yes cout << "YES
"
#define no cout << "NO
"
#define YESNO(x) cout << ((x) ? "YES
" : "NO
")
#define bitcount(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)
#define debug(x)
#define lb lower_bound
#define ub upper_bound
#define __TOISETHIVOI__ signed main()
#define vec(a, b, c, d) vector<a> b(c, d)
 
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = 2e18;
const int N = 6e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;
 
int parent[N], sz[N];
 
void init() {
    fast;
}
 
void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}
 
int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
 
bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}
 
struct Edge {
    int a, b, id;
};
 
void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
 
        vector<Edge> edges;
        set<int> coords;
 
        FOR(i, n) {
            int u, v;
            cin >> u >> v;
            edges.pb({u, v, i});
            coords.insert(u);
            coords.insert(v);
        }
 
        map<int, int> compress;
        int idx = 1;
        for (int x : coords) compress[x] = idx++;
 
        for (int i = 1; i <= idx; ++i) make_set(i);
 
        sort(all(edges), [](const Edge &x, const Edge &y) {
            return (x.b - x.a) < (y.b - y.a);
        });
 
        vi ans;
        for (Edge &e : edges) {
            int u = compress[e.a];
            int v = compress[e.b];
            if (union_sets(u, v)) {
                ans.pb(e.id);
            }
        }
 
        cout << sz(ans) << endl;
        REP(i, 0, sz(ans) - 1)
            cout << ans[i] << " 
"[i == sz(ans) - 1];
    }
}
 
__TOISETHIVOI__ {
    init();
    solve();
    return 0;
}