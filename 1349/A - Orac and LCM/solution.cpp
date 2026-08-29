#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
 
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int N = 1e5;
const int MAXA = 1e9;
const int INF = 1e9;
 
/*
 
  Gọi v_p(x) là mũ của p trong phân tích x.
  - v_p(lcm(a_i,a_j)) = max(v_p(a_i), v_p(a_j))
  - v_p(G) = min_{i<j} max(v_p(a_i), v_p(a_j))
  Sắp xếp các mũ của p tăng dần: b1 <= b2 <= ... <= bn
  -> v_p(G) = b2 (phần tử nhỏ thứ 2)
  Nếu có ≥2 số không chia p => b2 = 0 (p không đóng góp)
  Nếu có đúng 1 số không chia p => b2 = min(mũ dương)
  Nếu tất cả đều chia p => b2 = phần tử nhỏ thứ 2
*/
 
vector<int> spf;
 
vector<int> build_spf(int mx) {
    vector<int> s(mx + 1);
    for (int i = 2; i <= mx; ++i) {
        if (!s[i]) {
            s[i] = i;
            if ((ll)i * i <= mx)
                for (int j = i * i; j <= mx; j += i)
                    if (!s[j]) s[j] = i;
        }
    }
    return s;
}
 
ll pw(ll a, int b) {
    ll r = 1;
    while (b--) r *= a;
    return r;
}
 
void sol() {
    int n; cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (auto &x : a) cin >> x, mx = max(mx, x);
    if (mx < 2) { cout << 1 << '
'; return; }
 
    spf = build_spf(mx);
    vector<vector<int>> mu(mx + 1);
 
    for (int x : a) {
        int y = x;
        if (y <= 1) continue;
        while (y > 1) {
            int p = spf[y];
            if (!p) p = y;
            int c = 0;
            while (y % p == 0) y /= p, ++c;
            mu[p].pb(c);
        }
    }
 
    ll ans = 1;
    for (int p = 2; p <= mx; ++p) {
        if (mu[p].empty()) continue;
        int cnt = mu[p].size();
        int z = n - cnt; 
        if (z >= 2) continue;
        if (z == 1) {
            int mn = *min_element(all(mu[p]));
            if (mn > 0) ans *= pw(p, mn);
        } else {
            sort(all(mu[p]));
            int b2 = mu[p][1];
            if (b2 > 0) ans *= pw(p, b2);
        }
    }
 
    cout << ans << '
';
}
 
signed main() {
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
    int tc = 1;
    while (tc--) sol();
    return 0;
}
// TDN LOVER