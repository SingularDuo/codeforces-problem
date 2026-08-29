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
const unsigned long long NEXT_PRIME[] = {0, 11ULL, 101ULL, 1009ULL, 10007ULL, 100003ULL, 1000003ULL, 10000019ULL, 100000007ULL, 100000007ULL, 10000000019ULL};
 
template <class T, class U> inline bool minimize(T &x, const U &y) { return x > y ? (x = y, true) : false; }
template <class T, class U> inline bool maximize(T &x, const U &y) { return x < y ? (x = y, true) : false; }
struct BinaryTrie {
    int ch[MAXN * 31][2];
    int sz[MAXN * 31]; 
    int tot;
 
    void init() { 
        tot = 1; 
        memset(ch[0], 0, sizeof(ch[0]));
        sz[0] = 0; 
    }
 
    void insert(int x) {
        int cur = 0;
        sz[cur]++;
        for (int i = BIT; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (!ch[cur][b]) {
                memset(ch[tot], 0, sizeof(ch[tot]));
                sz[tot] = 0;
                ch[cur][b] = tot++;
            }
            cur = ch[cur][b];
            sz[cur]++;
        }
    }
    void remove(int x) 
    {
        int cur = 0;
        sz[cur]--;
        for (int i = BIT; i >= 0; i--) 
        {
            int b = (x >> i) & 1;
            cur = ch[cur][b];
            sz[cur]--;
        }
    }
    int minXor(int x) 
    {
        int cur = 0, ans = 0;
        for (int i = BIT; i >= 0; i--) 
        {
            int b = (x >> i) & 1;
            int want = b; 
            if (ch[cur][want] && sz[ch[cur][want]] > 0) cur = ch[cur][want];
            else 
            {
                ans |= (1 << i);
                cur = ch[cur][1 - want]; 
            }
        }
        return ans;
    }
} btrie;
int n;
vi a;
vector<int> par, szz;
void init_dsu(int n) 
{
    par.resize(n + 1);
    szz.assign(n + 1, 1);
    iota(par.begin(), par.end(), 0);
}
 
int fs(int u) {
    if (u == par[u]) return u;
    return par[u] = fs(par[u]);
}
 
bool join(int u, int v) {
    u = fs(u);
    v = fs(v);
    if (u == v) return false;
    if (szz[u] < szz[v]) swap(u, v);
    par[v] = u;
    szz[u] += szz[v];
    return true;
}
_______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    cin >> n;
    init_dsu(n);
    btrie.init();
    a.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    for(int i = 1; i <= a.size() - 1; i++) btrie.insert(a[i]);
    n = a.size(); 
    int comp = n - 1; 
    ll mst = 0;
    while(comp > 1)
    {
        vector<vi> comps(n);
        for(int i = 1; i < n; i++) comps[fs(i)].pb(i);
        vi bestW(n, LLINF);
        vi target(n, -1);
        for(int root = 1; root < n; root++) 
        {
            if(comps[root].empty()) continue;
            for(int idx : comps[root]) btrie.remove(a[idx]);
            for(int idx : comps[root]) 
            {
                int mn = btrie.minXor(a[idx]);
                if(mn < bestW[root]) {
                    bestW[root] = mn;
                    int target_val = a[idx] ^ mn;
                    int target_idx = lower_bound(all(a), target_val) - a.begin();
                    target[root] = target_idx;
                }
            }
            for(int idx : comps[root]) btrie.insert(a[idx]);
        }
 
        for(int i = 1; i < n; i++) 
        {
            if(!comps[i].empty() && target[i] != -1) 
            {
                int u = i, v = target[i];
                if(join(u, v)) 
                {
                    mst += bestW[i];
                    comp--;
                }
            }
        }
    }
 
    cout << mst ;
    KILL();
}