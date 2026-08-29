#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
 
void solve() {
    int n; 
    cin >> n;
 
    vector<int> res;
    int prod = 1;
 
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) {
            res.pb(i);
            prod = (prod * i) % n;
        }
    }
 
    if (prod == 1) {
        cout << res.size() << "
";
        for (auto x : res) cout << x << " ";
        cout << "
";
    } else {
        cout << res.size() - 1 << "
";
        for (auto x : res)
            if (x != prod)
                cout << x << " ";
        cout << "
";
    }
}
 
signed main() {
    fast;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
// TDN LOVER