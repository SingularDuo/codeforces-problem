#include <bits/stdc++.h>
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
 
const int MAX = 200000 + 5;
int n, k;
vector<int> s;
vector<int> t;
vector<int> cnt(MAX, 0);
 
bool ok(int mid)
{
    if (mid <= 0) return false;
    t.clear();
    for (int i = 0; i < MAX; ++i)
    {
        if (cnt[i] == 0) continue;
        int can = cnt[i] / mid;
        int need = min(can, k - (int)t.size());
        for (int j = 0; j < need; ++j)
            t.pb(i);
        if ((int)t.size() == k) break;
    }
    return (int)t.size() == k;
}
 
void solve()
{
    cin >> n >> k;
    s.assign(n, 0);
 
    int maxx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        if (s[i] >= 0 && s[i] < MAX) {
            cnt[s[i]]++;
            if (s[i] > maxx) maxx = s[i];
        }
    }
 
    if (!ok(1)) {
        for (int i = 0; i < k; ++i) {
            cout << 0 << (i + 1 == k ? '
' : ' ');
        }
        return;
    }
 
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (ok(mid)) l = mid;
        else r = mid - 1;
    }
 
    ok(l);
    for (int i = 0; i < (int)t.size(); ++i) {
        cout << t[i] << (i + 1 == (int)t.size() ? '
' : ' ');
    }
}
 
int main()
{
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
    auto start = clock();
 
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
 
    cerr << endl << (clock() - start) * 1000.0 / CLOCKS_PER_SEC << ' ' << 'm' << 's' << endl;
    return 0;
}