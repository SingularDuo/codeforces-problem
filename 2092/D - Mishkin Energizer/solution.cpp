/*
Author: duxp
Version: 1
Created at: 2026-01-10
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define all(x) x.begin() + 1, x.end()
#define nall(x) x.begin(), x.end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
 
#define trailingzero(x) __builtin_ctzll(x)
#define cntbit1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
 
#define TDN signed main()
#define KILL() exit(0)
#define NAME "task"
 
template <typename T>
inline int getbit(T x, int k) { return (x >> k) & 1; }
 
template <typename T>
inline T onbit(T x, int k) { return x | (T(1) << k); }
 
template <typename T>
inline T offbit(T x, int k) { return x & ~(T(1) << k); }
 
template <typename T>
inline bool minimize(T &a, const T &b) {
    if (a > b) { a = b; return true; }
    return false;
}
 
template <typename T>
inline bool maximize(T &a, const T &b) {
    if (a < b) { a = b; return true; }
    return false;
}
 
const ll INF = 1e18;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAXN = 200000;
 
vector<char> a = {'L', 'I', 'T'};
 
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    set<char> se;
    for (auto u : s) se.insert(u);
    if (se.size() == 1) {
        cout << -1 << endl;
        return;
    }
 
    vector<int> ans;
    map<char, int> mp;
    for (auto u : s) {
        mp[u]++;
    }
 
    int max_ops = 2 * n;
    int total_ops = 0;
 
    while (total_ops < max_ops) {
        int mn = min({mp['L'], mp['I'], mp['T']});
        int mx = max({mp['L'], mp['I'], mp['T']});
 
        if (mn == mx) break;
 
        bool found = false;
 
        for (int i = 0; i < s.size() - 1; i++) {
            char x = 'X';
            for (auto u : a) {
                if (s[i] != u && s[i + 1] != u) {
                    x = u;
                    break;
                }
            }
            if (x == 'X') continue;
            if (s[i] != s[i + 1] && mp[x] == mn) {
                mp[x]++;
                s.insert(s.begin() + i + 1, x);
                ans.push_back(i);
                found = true;
                total_ops++;
                break;
            }
        }
 
        if (found) continue;
 
        for (int i = 0; i < s.size() - 1; i++) {
            char x = 'X';
            for (auto u : a) {
                if (s[i] != u && s[i + 1] != u) {
                    x = u;
                    break;
                }
            }
            if (x == 'X') continue;
            if (s[i] != s[i + 1] && mp[x] == mx) {
                mp[x]++;
                s.insert(s.begin() + i + 1, x);
                ans.push_back(i);
                found = true;
                total_ops++;
                break;
            }
        }
 
        if (!found) break;
    }
 
    if (mp['L'] == mp['I'] && mp['I'] == mp['T']) {
        cout << ans.size() << endl;
        for (auto u : ans) {
            cout << u + 1 << endl;
        }
    } else {
        cout << -1 << endl;
    }
}
 
TDN
{
    fast;
    string fname = string(NAME);
    if (fopen((fname + ".inp").c_str(), "r")) {
        freopen((fname + ".inp").c_str(), "r", stdin);
        freopen((fname + ".out").c_str(), "w", stdout);
    }
 
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
 
    KILL();
}