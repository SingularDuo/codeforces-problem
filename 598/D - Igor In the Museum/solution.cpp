 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '
'
#define FOR(i, n) for (int i = 1; i <= (n); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define __TOISETHIVOI__ signed main()
 
const int INF = 2e18;
const int N = 1005;
 
void init() {
    fast;
}
 
int n, m, k;
string a[N];
int par[N * N], szz[N * N], pic[N * N];
 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
 
int cell_id(int x, int y) {
    return x * m + y;
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
        pic[u] += pic[v];
    }
}
 
void solve() {
    cin>>n>> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    int total = n * m;
    for (int i = 0; i < total; i++) {
        par[i] = i;
        szz[i] = 1;
        pic[i] = 0;
    }
 
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '.') continue;
            int u = cell_id(i, j);
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (a[ni][nj] == '.') {
                    int v = cell_id(ni, nj);
                    join(u, v);
                }
            }
        }
    }
 
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '.') continue;
            int u = findset(cell_id(i, j));
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (a[ni][nj] == '*') {
                    pic[u]++;
                }
            }
        }
    }
 
    while (k--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int u = findset(cell_id(x, y));
        cout << pic[u] << '
';
    }
}
__TOISETHIVOI__ {
    init();
    solve();
    return 0;
}