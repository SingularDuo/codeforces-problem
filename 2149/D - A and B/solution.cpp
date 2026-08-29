#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define EYMK signed main()
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define pb push_back
#define endl '
'
 
 
 
static ll INF_LL = (ll)4e18;
 
ll c(const string &str, char ch) {
    int n = (int)str.size();
    vector<ll> pos;
    pos.reserve(n);
    for (int i = 0; i < n; ++i)
        if (str[i] == ch) pos.pb(i);
 
    if (pos.size() <= 1) return 0LL;
 
    vector<ll> t;
    t.reserve(pos.size());
    for (size_t i = 0; i < pos.size(); ++i)
        t.pb(pos[i] - (ll)i);
 
    size_t k = t.size();
    nth_element(t.begin(), t.begin() + k/2, t.end());
    ll med = t[k/2];
 
    ll ans = 0;
    for (ll x : t) ans += llabs(x - med);
    return ans;
}
 
void solve() {
    int T;
    if (!(cin >> T)) return;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
 
        ll ca = c(s, 'a');
        ll cb = c(s, 'b');
        cout << min(ca, cb) << '
';
    }
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