#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define all(x) x.begin() + 1, x.end()
#define nall(x) x.begin(), x.end()
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, x) memset(a, x, sizeof(a))
 
#define trailingzero(x) __builtin_ctzll(x)
#define cntbit1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
 
#define _______TOISETHIVOI_______ signed main()
#define KILL() exit(0)
#define NAME "duxp"
 
template <typename T>
inline int getbit(T x, int k) { return (x >> k) & 1; }
template <typename T>
inline T onbit(T x, int k) { return x | (T(1) << k); }
template <typename T>
inline T offbit(T x, int k) { return x & ~(T(1) << k); }
 
const ll OO = 1e18;
const int oo = 1e9;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAXN = 200000;
 
vector<int> par, szz;
 
void init_dsu(int n) {
    par.resize(n + 1);
    szz.assign(n + 1, 1);
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
 
struct Edge {
    int u, v;
    ll w;
};
 
_______TOISETHIVOI_______
{
    fast;
    if (FILE *f = fopen(NAME ".inp", "r")) {
        fclose(f);
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
 
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
 
        vector<Edge> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }
 
        ll mask = 0;
        for (int i = 0; i <= 30; i++) mask = onbit(mask, i);
 
        for (int bit = 30; bit >= 0; bit--) {
 
            ll new_mask = offbit(mask, bit);
 
            init_dsu(n);
            int cnt = 0;
 
            for (auto &e : edges) {
 
                bool ok = true;
 
                for (int j = 0; j <= 30; j++) {
                    if (getbit(e.w, j) && !getbit(new_mask, j)) {
                        ok = false;
                        break;
                    }
                }
 
                if (ok) {
                    if (join(e.u, e.v)) cnt++;
                }
            }
 
            if (cnt == n - 1) {
                mask = new_mask;
            }
        }
 
        cout << mask << endl;
    }
}