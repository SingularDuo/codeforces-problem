#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
 
struct Node {
    int z, o, eq;
};
 
vector<Node> prep(const vector<int>& a) {
    int n = a.size();
    vector<Node> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        if (a[i - 1] == 0) pref[i].z++;
        if (a[i - 1] == 1) pref[i].o++;
        if (i < n && a[i - 1] == a[i]) pref[i].eq++;
    }
    pref[n].eq = pref[n - 1].eq;
    return pref;
}
 
int calc(const vector<Node>& pf, int l, int r) {
    int z = pf[r].z - pf[l - 1].z;
    int o = pf[r].o - pf[l - 1].o;
    if (z % 3 || o % 3) return -1;
    int len = r - l + 1, k = len / 3;
    int eqSeg = pf[r - 1].eq - pf[l - 1].eq;
    return eqSeg ? k : k + 1;
}
 
void run() {
    int T; cin >> T;
    while (T--) {
        int n, q; cin >> n >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        auto pref = prep(arr);
        while (q--) {
            int L, R; cin >> L >> R;
            cout << calc(pref, L, R) << "
";
        }
    }
}
 
int main() {
    fastio;
    run();
    return 0;
}