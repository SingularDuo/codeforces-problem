#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define EYMK signed main()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define each(x) for(auto & i : x)
#define vvi vector<vi>
#define pb push_back
#define endl '
'
#define yesno(x) cout << ((x) ? "YES
" : "NO
")
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
 
const int MOD = 1e9 + 7;
const int LARGEPRIME = 998244353;
const int INF_INT = 2147483647;
const ll INF_LL = 2 * 1e18;
 
void rd(int &n, ll &k, ll &L, ll &R, vi &a) {
    cin >> n >> k >> L >> R;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
}
 
inline void add(map<int,int> &mp, int x) {
    mp[x]++;
}
 
inline void rm(map<int,int> &mp, int x) {
    auto it = mp.find(x);
    if (it != mp.end()) {
        if (--(it->second) == 0) mp.erase(it);
    }
}
 
void shk(map<int,int> &mp, const vi &a, int &lp, int k) {
    while ((int)mp.size() > k) {
        rm(mp, a[lp]);
        lp++;
    }
}
 
void shk1(map<int,int> &mp, const vi &a, int &lp, int k) {
    while ((int)mp.size() >= k) {
        rm(mp, a[lp]);
        lp++;
    }
}
 
inline ll calc(int i, int l1, int l2, ll L, ll R) {
    ll Lpos = max((ll)l1, (ll)i - R + 1);
    ll Rpos = min((ll)l2 - 1, (ll)i - L + 1);
    if (Lpos <= Rpos) return (Rpos - Lpos + 1);
    return 0;
}
 
void one() {
    int n; ll k, L, R;
    vi a;
    rd(n, k, L, R, a);
 
    ll ans = 0;
    int l1 = 0, l2 = 0;
    map<int,int> c1, c2;
 
    for (int i = 0; i < n; i++) {
        add(c1, a[i]);
        shk(c1, a, l1, (int)k);
 
        add(c2, a[i]);
        shk1(c2, a, l2, (int)k);
 
        ans += calc(i, l1, l2, L, R);
    }
 
    cout << ans << endl;
}
 
void solve() {
    int T; cin >> T;
    while (T--) one();
}
 
EYMK {
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    solve();
    return 0;
}