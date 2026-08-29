#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '
'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;
 
bool mt = false;
 
void init() {
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}
 
void solve() {
    const int LIM = 6000000;
    const int PRM = 400000;
 
    vector<bool> isp(LIM + 1, true);
    isp[0] = isp[1] = false;
    for (int i = 2; i * i <= LIM; i++) {
        if (isp[i]) {
            for (int j = i * i; j <= LIM; j += i) {
                isp[j] = false;
            }
        }
    }
 
    vector<int> pr;
    pr.reserve(PRM);
    for (int i = 2; i <= LIM && pr.size() < PRM; i++) {
        if (isp[i]) pr.push_back(i);
    }
 
    int np = pr.size();
    vector<ll> psum(np + 1, 0);
    for (int i = 1; i <= np; i++) {
        psum[i] = psum[i - 1] + pr[i - 1];
    }
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
 
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(all(a), greater<ll>());
 
        vector<ll> csum(n + 1, 0);
        for (int i = 1; i <= n; i++) csum[i] = csum[i - 1] + a[i - 1];
 
        int k = 0;
        for (int i = 1; i <= n && i <= np; i++) {
            if (csum[i] >= psum[i]) k = i;
            else break;
        }
        cout << (n - k) << endl;
    }
}
 
KING_PHAT {
    // Set mt state
    // mt = true;
    // Set I/O style
    // I_O("test1", "test1");
    fast;
    if (mt) {
        int t;
        cin >> t;
        while (t--) {
            solve();
        }
    } else {
        solve();
    }
    return 0;
}