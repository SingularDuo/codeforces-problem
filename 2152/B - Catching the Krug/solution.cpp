#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
 
ll L, xa, ya, xb, yb;
 
bool can(ll d) {
    ll lx = max(0LL, xa - d);
    ll rx = min(L, xa + d);
    ll ly = max(0LL, ya - d);
    ll ry = min(L, ya + d);
 
    ll dx = max(abs(lx - xb), abs(rx - xb));
    ll dy = max(abs(ly - yb), abs(ry - yb));
 
    return max(dx, dy) <= d;
}
 
ll solveOne() {
    if (xa == xb && ya == yb) return 0;
 
    ll lo = 0, hi = 2 * L + 10, ret = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (can(mid)) {
            ret = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ret;
}
 
void process() {
    int q; 
    if (!(cin >> q)) return;
    while (q--) {
        cin >> L >> xa >> ya >> xb >> yb;
        cout << solveOne() << "
";
    }
}
 
int main() {
    fastio;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    process();
    return 0;
}