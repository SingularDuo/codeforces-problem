#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << #x << " = " << (x) << endl
#define int long long
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
#define traillingzero(x) __builtin_ctzll(x)
#define cntbit1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
#define TDN signed main()
const int INF = 1e18; const int MOD = 1e9+7;
int getbit(int x, int k){return (x >> k) & 1;}
int offbit(int x, int k){return x & (~(1 << k));}
 
 
int n, m;
 
struct edge {
    int u, v, w, id;
};
 
vector<edge> ed;
bool cmp(edge a, edge b) { return a.w < b.w; }
 
vector<int> par, szz;
 
void init_dsu(int n) {
    par.resize(n+1);
    szz.assign(n+1, 1);
    iota(par.begin(), par.end(), 0);
}
 
int findset(int u) {
    if (u == par[u]) return u;
    return par[u] = findset(par[u]);
}
 
bool join(int u, int v) {
    u = findset(u);
    v = findset(v);
    if (u == v) return false;
    if (szz[u] < szz[v]) swap(u, v);
    par[v] = u;
    szz[u] += szz[v];
    return true;
}
 
const int N = 100000 + 5;
int up[N][20], h[N], sum[N][20];
vector<pii> g[N];     
vector<pii> fg[N];
vector<int> spec;
 
void dfs_lca(int u)
{
    for (auto [v, w] : g[u]) {
        if (v == up[u][0]) continue;
        h[v] = h[u] + 1;
 
        up[v][0] = u;
        sum[v][0] = w;
 
        for (int j = 1; j < 20; ++j) {
            up[v][j] = up[ up[v][j-1] ][j-1];
            sum[v][j] = sum[v][j-1] + sum[ up[v][j-1] ][j-1];
        }
 
        dfs_lca(v);
    }
}
 
pair<int, ll> find_LCA(int u, int v)
{
    ll total_sum = 0;
 
    if (h[u] < h[v]) swap(u, v);
    int k = h[u] - h[v];
    for (int j = 0; j < 20; j++) {
        if (k >> j & 1) {
            total_sum += sum[u][j];
            u = up[u][j];
        }
    }
 
    if (u == v) return {u, total_sum};
    for (int j = 19; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            total_sum += sum[u][j];
            total_sum += sum[v][j];
            u = up[u][j];
            v = up[v][j];
        }
    }
 
    total_sum += sum[u][0];
    total_sum += sum[v][0];
 
    return {up[u][0], total_sum};
}
 
int dist[45][100005];
void compute_dist()
{
    int idx = 0;
    for(auto &u : spec)
    {
        for(int i = 1; i <= n; i++) {
            dist[idx][i] = INF;
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[idx][u] = 0;
        pq.push({0, u});
        while(!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if(d > dist[idx][v]) continue;
            for(auto &i: fg[v]) {
                int to = i.fi, w = i.se;
                if(dist[idx][v] + w < dist[idx][to]) {
                    dist[idx][to] = dist[idx][v] + w;
                    pq.push({dist[idx][to], to});
                }
            }
        }
 
        idx++;
    }
}
 
void solve()
{
    cin >> n >> m;
 
    ed.resize(m+1);
    for (int i = 1; i <= m; i++) {
        cin >> ed[i].u >> ed[i].v >> ed[i].w;
        ed[i].id = i;
        fg[ed[i].u].pb({ed[i].v, ed[i].w});
        fg[ed[i].v].pb({ed[i].u, ed[i].w});
    }
 
    init_dsu(n);
 
    sort(all(ed), cmp);
 
    bool marked[m+1];
    memset(marked, false, sizeof(marked));
    for (auto &i : ed) {
        int u = i.u, v = i.v, w = i.w;
        if (findset(u) != findset(v)) {
            join(u, v);
            marked[i.id] = true;
            g[u].pb({v, w});
            g[v].pb({u, w});
        }
    }
 
    for(auto &i : ed) {
        if(!marked[i.id]) {
            spec.pb(i.u);
            spec.pb(i.v);
        }
    }
 
    compute_dist();
    dfs_lca(1);
 
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        auto [lca, res] = find_LCA(u, v);
 
        int idx = 0;
        for(auto i : spec) {
            res = min(res, find_LCA(u, i).second + dist[idx][v]);
            res = min(res, find_LCA(v, i).second + dist[idx][u]);
            idx++;
        }
        cout << res << "
";
    }
}
 
TDN
{
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    solve();
}