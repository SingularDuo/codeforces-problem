/*
Author: duxp
"The king has returned, and the throne has been reclaimed.",
"The racer has returned, and the track is ready to be fired up again.",
"The coder has returned, and new problems are ready to be solved.",
*/
#include <cassert> 
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <iostream>
#include <list>
#include <sstream>
#include <iterator>
#include <chrono>
using namespace std;
#define int long long
#define ll long long
#define ld long double 
#define pb push_back
#define fi first
#define se second
#define endl '
'
#define all(x) x.begin() + 1, x.end()
#define nall(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, x) memset(a, x, sizeof(a))
#define YESNO(x) cout << ((x) ? "YES" : "NO")
#define KILL() exit(0)
#define NAME "duxp"
#define _______TOISECOGIAIVOI_______ signed main()
using vi = vector<int>; using pii = pair<int, int>; using vpii = vector<pii>;
template<typename T, typename = void> struct is_it : std::false_type {}; template<typename T> struct is_it<T, typename std::conditional<true, void, decltype(std::begin(std::declval<T>()))>::type> : std::true_type {};
void _db(long long x) { std::cerr << x; } void _db(double x) { std::cerr << x; } void _db(char x) { std::cerr << '\'' << x << '\''; } void _db(const std::string &x) { std::cerr << '"' << x << '"'; } void _db(bool x) { std::cerr << (x ? "true" : "false"); } template<typename A, typename B> void _db(const std::pair<A, B> &p) { std::cerr << "("; _db(p.first); std::cerr << ", "; _db(p.second); std::cerr << ")"; } template<typename T, typename std::enable_if<is_it<T>::value && !std::is_same<T, std::string>::value, int>::type = 0> void _db(const T &v) { std::cerr << "["; bool f = 1; for (const auto &x : v) { if (!f) std::cerr << ", "; _db(x); f = 0; } std::cerr << "]"; }
void _pr() { std::cerr << "
"; } template <typename T, typename... V> void _pr(T t, V... v) { _db(t); if (sizeof...(v)) std::cerr << ", "; _pr(v...); } 
#ifndef ONLINE_JUDGE
#define debug(x...) std::cerr << "[" << #x << "] = ", _pr(x)
#else
#define debug(x...)
#endif
template <typename T> constexpr int getbit(T x, int k) { return (x >> k) & 1; }
template <typename T> constexpr T onbit(T x, int k) { return x | (T(1) << k); }
template <typename T> constexpr T offbit(T x, int k) { return x & ~(T(1) << k); }
constexpr int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
constexpr long long OO = 0x7FFFFFFFFFFFFFFFLL;
constexpr int oo = 0x7FFFFFFF, INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 1000000007, MOD2 = 998244353, MAXN = 200000, LOG = 20, BLOCK = 450;
constexpr int ALPHA = 26, BIT = 30;
const unsigned long long NEXT_PRIME[] = {0, 11ULL, 101ULL, 1009ULL, 10007ULL, 100003ULL, 1000003ULL, 10000019ULL, 100000007ULL, 1000000007ULL, 10000000019ULL};
 
template <class T, class U> inline bool minimize(T &x, const U &y) { return x > y ? (x = y, true) : false; }
template <class T, class U> inline bool maximize(T &x, const U &y) { return x < y ? (x = y, true) : false; }
struct StringHash {
    static const int MOD1 = 1000000007;
    static const int MOD2 = 1000000009;
    int n, BASE;
    vector<int> h1, h2, pw1, pw2;
    StringHash() {}
    StringHash(const string &s, int base = 311) {
        init(s, base);
    }
    void init(const string &s, int base = 311) {
        BASE = base;
        n = s.size();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        pw1.assign(n + 1, 1);
        pw2.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pw1[i] = 1LL * pw1[i - 1] * BASE % MOD1;
            pw2[i] = 1LL * pw2[i - 1] * BASE % MOD2;
 
            h1[i] = (1LL * h1[i - 1] * BASE + s[i - 1]) % MOD1;
            h2[i] = (1LL * h2[i - 1] * BASE + s[i - 1]) % MOD2;
        }
    }
 
    pair<int, int> getHash(int l, int r) {
        ++l;
        ++r;
 
        int x1 = (h1[r] - 1LL * h1[l - 1] * pw1[r - l + 1] % MOD1 + MOD1) % MOD1;
        int x2 = (h2[r] - 1LL * h2[l - 1] * pw2[r - l + 1] % MOD2 + MOD2) % MOD2;
 
        return {x1, x2};
    }
 
    pair<int, int> getPrefix(int len) {
        if (len <= 0) return {0, 0};
        return getHash(0, len - 1);
    }
 
    pair<int, int> getSuffix(int len) {
        if (len <= 0) return {0, 0};
        return getHash(n - len, n - 1);
    }
    bool ok(int len)
    {
        if(len <= 0) return true;
        pii hp = getPrefix(len), hsu = getSuffix(len);
        return (hp.fi == hsu.fi && hp.se == hsu.se);
    }
};
string s;
int  res[MAXN + 5], diff[MAXN + 5];
StringHash hs;
bool ok(int i, int len)
{
    pii prefix = hs.getPrefix(len);
    pii hc = hs.getHash(i, i + len - 1);
    return (prefix.fi == hc.fi && prefix.se == hc.se);
}
int f[MAXN + 5];
void calcF()
{
    int n = s.size();
    f[0] = n;
    int l = 0, r = 0;
    for(int i = 1; i < n; i++)
    {
        if(i > r)
        {
            l = r = i;
            while(r < n && s[r] == s[r - l]) r++;
            f[i] = r - l;
            r--;
        }
        else if(f[i - l] < r - i + 1) f[i] = f[i - l];
        else 
        {
            l = i;
            r++;
            while(r < n && s[r] == s[r - l]) r++;
            f[i] = r - l;
            r--;
        }
    }
}
_______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
 
    cin >> s;
    hs.init(s);
    int n = s.size();
    calcF();
    for(int i = 0; i < n; i++)
    {
        diff[1]++;
        diff[f[i] + 1]--;
    }
    for(int i = 1; i <= n; i++) res[i] = res[i - 1] + diff[i];
    vector<int> border;
    for(int len = 1; len <= n; len++)
    {
        if(hs.ok(len)) border.pb(len);
    }
    cout << border.size() << endl;
    for(auto len : border) cout << len << ' ' << res[len] << endl;
 
    return 0;
}