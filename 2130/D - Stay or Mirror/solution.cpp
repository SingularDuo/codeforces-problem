#include <bits/stdc++.h>
using namespace std;
#define int long long
#define R return
#define U ios::sync_with_stdio(0);cin.tie(0);
 
int32_t main() {
    U int z; cin >> z;
    while (z--) {
        int n; cin >> n;
        vector<int> a(n+9), b(n+9), c(n+9), d(n*2+19);
        for (int i = 1; i <= n; ++i) cin >> a[i];
 
        auto A = [&](int x) {
            for (; x < d.size(); x += x & -x) ++d[x];
        };
        auto B = [&](int x) {
            int r = 0;
            for (; x > 0; x -= x & -x) r += d[x];
            R r;
        };
 
        for (int j = n; j; --j) {
            b[j] = B(a[j] - 1);
            A(a[j]);
        }
 
        fill(d.begin(), d.end(), 0);
 
        for (int j = 1; j <= n; ++j) {
            c[j] = (j - 1) - B(a[j]);
            A(a[j]);
        }
 
        int m = 0, v = 0;
        for (int j = 1; j <= n; ++j) {
            int x = (n - j) - b[j] - c[j];
            if (x < 0) m += x;
            v += b[j];
        }
 
        cout << v + m << " 
";
    }
    R 0;
}