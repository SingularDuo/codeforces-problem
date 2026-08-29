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
constexpr int MOD = 1000000007, MOD2 = 998244353, MAXN = 300000, LOG = 20, BLOCK = 450;
constexpr int ALPHA = 26, BIT = 30;
const unsigned long long NEXT_PRIME[] = {0, 11ULL, 101ULL, 1009ULL, 10007ULL, 100003ULL, 1000003ULL, 10000019ULL, 100000007ULL, 1000000007ULL, 10000000019ULL};
 
template <class T, class U> inline bool minimize(T &x, const U &y) { return x > y ? (x = y, true) : false; }
template <class T, class U> inline bool maximize(T &x, const U &y) { return x < y ? (x = y, true) : false; }
struct Query
{
    int l, r, k, id;
};
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long L, long long R) {
    assert(L <= R);
    return uniform_int_distribution<long long>(L, R)(rd);
}
int n, q;
int a[MAXN + 5],res[MAXN + 5], cnt[MAXN + 5];
vector<Query> qs;
bool cmp(const Query &A, const Query &B) 
{
    int aa = A.l / BLOCK, bb = B.l / BLOCK;
    if (aa != bb) return aa < bb;
    if (aa & 1) return A.r > B.r; 
    return A.r < B.r;
}
void add(int idx) 
{
    int val = a[idx];
    cnt[val]++;
}
 
void rem(int idx) 
{
    int val = a[idx];
    cnt[val]--;
}
_______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    cin>>n>>q;
    for(int i = 1; i <= n; i++) cin>>a[i];
    qs.resize(q + 1);
    for(int i = 1; i <= q; i++)
    {
        cin>>qs[i].l>>qs[i].r>>qs[i].k;
        qs[i].id = i;
    }
    sort(all(qs), cmp);
    memset(res, -1, sizeof res);
    memset(cnt, 0, sizeof cnt);
    int L = 1, R = 0;
    for(int i = 1; i <= q; i++)
    {
        int l = qs[i].l, r = qs[i].r, k = qs[i].k, id = qs[i].id;
        while (R < r) add(++R);
        while (R > r) rem(R--);
        while (L < l) rem(L++);
        while (L > l) add(--L);
        int len = r - l + 1;
        int amt = len / k;
        int best = OO;
        for(int s = 0; s <= 100; s++)
        {
            int id = Rand(l, r);
            int val = a[id];
            if(cnt[val] > amt) minimize(best, val);
        }
        res[id] = (best == OO ? -1 : best);
    }
    for(int i = 1; i <= q; i++) cout<<res[i]<<endl;
    KILL();
}