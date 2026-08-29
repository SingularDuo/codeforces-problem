#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define FAST_IO   ios::sync_with_stdio(false), cin.tie(nullptr)
#define YES       cout << "Yes
"
#define NO        cout << "No
"
 
ll bin_gcd(ll u, ll v) {
    if (u == 0) return v;
    if (v == 0) return u;
    int shift = __builtin_ctzll(u | v);
    u >>= __builtin_ctzll(u);
    do {
        v >>= __builtin_ctzll(v);
        if (u > v) swap(u, v);
        v -= u;
    } while (v);
    return u << shift;
}
 
bool check_prefix(const vector<ll>& pre) {
    for (auto i = 1u; i < pre.size(); ++i)
        if (pre[i-1] % pre[i] != 0) return false;
    return true;
}
 
bool check_suffix(const vector<ll>& suf) {
    for (auto i = 1u; i < suf.size(); ++i)
        if (suf[i] % suf[i-1] != 0) return false;
    return true;
}
 
bool check_coprime_splits(const vector<ll>& pre, const vector<ll>& suf) {
    size_t n = pre.size();
    for (size_t i = 0; i < n; ++i) {
        ll g = bin_gcd(pre[i], suf[i]);
        if (i > 0) {
            if (bin_gcd(pre[i-1]/pre[i], suf[i]/g) != 1) return false;
        }
        if (i + 1 < n) {
            if (bin_gcd(pre[i]/g, suf[i+1]/suf[i]) != 1) return false;
        }
    }
    return true;
}
 
int main() {
    FAST_IO;
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<ll> pre(n), suf(n);
        for (ll& x : pre) cin >> x;
        for (ll& x : suf) cin >> x;
 
 
        ll overall = pre.back();
        if (suf.front() != overall) {
            NO;
            continue;
        }
 
        bool valid = true;
        valid &= check_prefix(pre);
        valid &= check_suffix(suf);
        if (valid) valid &= check_coprime_splits(pre, suf);
 
        valid ? YES : NO;
    }
    return 0;
}