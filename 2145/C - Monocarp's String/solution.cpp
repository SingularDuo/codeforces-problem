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
 
int mid(const vector<int>& p, int n, int d) {
    map<int,int> m; m[0] = 0;
    int res = n;
    for (int j = 1; j <= n; ++j) {
        int need = p[j] - d;
        if (m.count(need)) res = min(res, j - m[need]);
        m[p[j]] = j;
    }
    return res;
}
 
int prefx(const vector<int>& p, int n, int d) {
    for (int i = 1; i < n; ++i)
        if (p[i] == d) return i;
    return n;
}
 
int sufx(const vector<int>& p, int n) {
    for (int i = n - 1; i > 0; --i)
        if (p[i] == 0) return n - i;
    return n;
}
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> p(n + 1);
    for (int i = 0; i < n; ++i)
        p[i + 1] = p[i] + (s[i] == 'a' ? 1 : -1);
 
    if (p[n] == 0) { cout << 0 << '
'; return; }
    int d = p[n];
    int ans = min({ mid(p, n, d), prefx(p, n, d), sufx(p, n) });
    cout << (ans < n ? ans : -1) << '
';
}
 
 
signed main()
{
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
 
    return 0;
}