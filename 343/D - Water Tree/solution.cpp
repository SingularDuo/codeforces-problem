#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin() + 1, (x).end()
#define nall(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define getbit(mask, i) (((mask) >> (i)) & 1LL)
#define onbit(mask, i) ((mask)  (1LL << (i)))
#define offbit(mask, i) ((mask) & ~(1LL << (i)))
#define endl '
'
 
template<class T> bool maximize(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
template<class T> bool minimize(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
constexpr int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
const int INF = 2e9;
const int INFLL = 2e18;
const int MOD = 1e9 + 7;
const int MAXN = 200000;
const int LOG = 20;
const int BLOCK = 420;
int n, q;
vector<vi> g;
struct SegmentTree
{
    int n;
    vi st, lazy;
 
    SegmentTree(int _n) : n(_n)
    {
        st.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, -1);
    }
 
    void push(int id)
    {
        if (lazy[id] != -1)
        {
            st[id * 2] = lazy[id];
            lazy[id * 2] = lazy[id];
            st[id * 2 + 1] = lazy[id];
            lazy[id * 2 + 1] = lazy[id];
            lazy[id] = -1;
        }
    }
 
    void updateRange(int ql, int qr, int val, int id = 1, int l = 1, int r = -1)
    {
        if (r == -1) r = n;
        if (r < ql || l > qr) return;
        if (l >= ql && r <= qr)
        {
            st[id] = val;
            lazy[id] = val;
            return;
        }
        push(id);
        int mid = (l + r) / 2;
        updateRange(ql, qr, val, id * 2, l, mid);
        updateRange(ql, qr, val, id * 2 + 1, mid + 1, r);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }
    int getPoint(int pos, int id = 1, int l = 1, int r = -1)
    {
        if (r == -1) r = n;
        if (l == r) return st[id];
        push(id);
        int mid = (l + r) / 2;
        if (pos <= mid) return getPoint(pos, id * 2, l, mid);
        else return getPoint(pos, id * 2 + 1, mid + 1, r);
    }
};
struct HLD
{
    int n;
    int timerHLD = 1;
    vi heavy, sz, head, posHLD, par, depth;
    vector<vi> adj;
    HLD(int _n, const vector<vi> &graph) : n(_n), adj(graph)
    {
        heavy.assign(n + 1, 0);
        sz.assign(n + 1, 0);
        head.assign(n + 1, 0);
        posHLD.assign(n + 1, 0);
        par.assign(n + 1, 0);
        depth.assign(n + 1, 0);
    }
 
    void dfs1(int u, int p = 0)
    {
        sz[u] = 1;
        for (int v : adj[u])
        {
            if (v == p) continue;
            par[v] = u;
            depth[v] = depth[u] + 1;
            dfs1(v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[heavy[u]]) heavy[u] = v;
        }
    }
 
    void dfs2(int u, int h)
    {
        head[u] = h;
        posHLD[u] = timerHLD++;
        if (heavy[u]) dfs2(heavy[u], h);
        for (int v : adj[u]) if (v != par[u] && v != heavy[u]) dfs2(v, v);
    }
 
    void init(int root = 1)
    {
        dfs1(root);
        dfs2(root, root);
    }
    void updatePath(int u, int v, int val, SegmentTree &st)
    {
        while (head[u] != head[v])
        {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            st.updateRange(posHLD[head[u]], posHLD[u], val);
            u = par[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        st.updateRange(posHLD[u], posHLD[v], val);
    }
    void updateSubtree(int u, int val, SegmentTree &st)
    {
        st.updateRange(posHLD[u], posHLD[u] + sz[u] - 1, val);
    }
};
void input()
{
    cin >> n;
    g.resize(n + 5);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen("duxp.inp", "r"))
    {
        freopen("duxp.inp", "r", stdin);
        freopen("duxp.out", "w", stdout);
    }
 
    input();
//    int t; cin>>t; while(t--) solve();
    HLD hld(n, g);
    hld.init(1);
    SegmentTree st(n);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int type, v;
        cin >> type >> v;
        if (type == 1) hld.updateSubtree(v, 1, st);
        else if (type == 2) hld.updatePath(1, v, 0, st);
        else cout << st.getPoint(hld.posHLD[v]) << endl;
 
    }
    return 0;
}