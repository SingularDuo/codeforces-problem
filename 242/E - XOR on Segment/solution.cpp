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
int n, m;
int a[MAXN + 5];
int cnt[4 * MAXN + 5][BIT + 5], lazy[4 * MAXN + 5];
void build(int id, int l, int r)
{
    if (l == r)
    {
        for (int b = 0; b <= BIT; b++) cnt[id][b] = getbit(a[l], b);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    for (int b = 0; b <= BIT; b++) cnt[id][b] = cnt[id * 2][b] + cnt[id * 2 + 1][b];
}
void push(int id, int l, int r)
{
    if (!lazy[id]) return;
    int mid = (l + r) / 2;
    for (int b = 0; b <= BIT; b++)
    {
        if (getbit(lazy[id], b))
        {
            cnt[id * 2][b] = (mid - l + 1) - cnt[id * 2][b];
            cnt[id * 2 + 1][b] = (r - mid) - cnt[id * 2 + 1][b];
        }
    }
    lazy[id * 2] ^= lazy[id];
    lazy[id * 2 + 1] ^= lazy[id];
    lazy[id] = 0;
}
 
void update(int id, int l, int r, int u, int v, int x)
{
    if (r < u || v < l) return;
    if (u <= l && r <= v)
    {
        int len = r - l + 1;
        for (int b = 0; b <= BIT; b++)
        {
            if (getbit(x, b)) cnt[id][b] = len - cnt[id][b];
        }
        lazy[id] ^= x;
        return;
    }
    push(id, l, r);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, x);
    update(id * 2 + 1, mid + 1, r, u, v, x);
    for (int b = 0; b <= BIT; b++) cnt[id][b] = cnt[id * 2][b] + cnt[id * 2 + 1][b];
}
 
int get(int id, int l, int r, int u, int v)
{
    if (r < u || v < l) return 0;
    if (u <= l && r <= v)
    {
        int res = 0;
        for (int b = 0; b <= BIT; b++) res += cnt[id][b] * (1LL << b);
        return res;
    }
    push(id, l, r);
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
 
_______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    cin>>m;
    memset(lazy, 0, sizeof lazy);
    build(1,1,n);
    while(m--)
    {
        int t; cin>>t;
        if(t == 1)
        {
            int l, r; cin>>l>>r;
            cout<<get(1,1,n,l,r)<<endl;
        }
        else 
        {
            int l, r, x; cin>>l>>r>>x;
            update(1,1,n,l,r,x);
        }
    }
    KILL();
}