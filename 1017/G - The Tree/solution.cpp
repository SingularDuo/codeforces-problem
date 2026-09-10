/*
 ___ _ __  __    ____ ___  __  __ ___ _   _  ____ 
|_ _( )  \/  |  / ___/ _ \|  \/  |_ _| \ | |/ ___|
 | ||/| |\/| | | |  | | | | |\/| || ||  \| | |  _ 
 | |  | |  | | | |__| |_| | |  | || || |\  | |_| |
|___| |_|_ |_|  \____\___/|_|__|_|___|_|_\_|\____|
        | | | |/ ___|  \/  |_   _/ ___|_   _|     
        | |_| | |   | |\/| | | | \___ \ | |       
        |  _  | |___| |  | | | |  ___) || |       
        |_| |_|\____|_|  |_| |_| |____/ |_|       
---------------Frieren lover fr-------------------
Author: duxp
Note: 
"Use long long wherever you can."
"Add +5 to every array size."
"Legends got AC, survivor got the subtasks."
"May the Subtasks be ever in your favor."
"Do on your own."
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
 
#ifdef LOCAL 
    #include <sys/resource.h>
#endif
 
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
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = b; i >= a; i--)
#define EACH(i, a) for(auto &i : a)
#define YESNO(x) cout << ((x) ? "YES" : "NO")
#define KILL() exit(0)
#define NAME "duxp"
#define TASK ""
#define _______TOISECOGIAIVOI_______ signed main()
using vi = vector<int>; using pii = pair<int, int>; using vpii = vector<pii>;
template<typename T, typename = void> struct is_it : std::false_type {}; template<typename T> struct is_it<T, typename std::conditional<true, void, decltype(std::begin(std::declval<T>()))>::type> : std::true_type {};
void _db(long long x) { std::cerr << x; } void _db(double x) { std::cerr << x; } void _db(char x) { std::cerr << '\'' << x << '\''; } void _db(const std::string &x) { std::cerr << '"' << x << '"'; } void _db(bool x) { std::cerr << (x ? "true" : "false"); } template<typename A, typename B> void _db(const std::pair<A, B> &p) { std::cerr << "("; _db(p.first); std::cerr << ", "; _db(p.second); std::cerr << ")"; } template<typename T, typename std::enable_if<is_it<T>::value && !std::is_same<T, std::string>::value, int>::type = 0> void _db(const T &v) { std::cerr << "["; bool f = 1; for (const auto &x : v) { if (!f) std::cerr << ", "; _db(x); f = 0; } std::cerr << "]"; }
void _pr() { std::cerr << "
"; } template <typename T, typename... V> void _pr(T t, V... v) { _db(t); if (sizeof...(v)) std::cerr << ", "; _pr(v...); } 
#ifdef LOCAL
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
 
#ifdef LOCAL
auto start_time = chrono::high_resolution_clock::now();
double base_memory_mb = 0;
 
double get_memory_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    #ifdef __APPLE__
        return usage.ru_maxrss / (1024.0 * 1024.0);
    #else
        return usage.ru_maxrss / 1024.0;
    #endif
}
 
#ifdef __APPLE__
struct section_64 {
    char sectname[16];
    char segname[16];
    uint64_t addr;
    uint64_t size;
    uint32_t offset;
    uint32_t align;
    uint32_t reloff;
    uint32_t nreloc;
    uint32_t flags;
    uint32_t reserved1;
    uint32_t reserved2;
    uint32_t reserved3;
};
extern "C" const struct section_64* getsectbyname(const char *segname, const char *sectname);
#endif
 
void TIMER(chrono::high_resolution_clock::time_point start_time)
{
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_ms = end_time - start_time;
    
    struct rusage usage; 
    getrusage(RUSAGE_SELF, &usage);
    #ifdef __APPLE__
        double dynamic_mb = usage.ru_maxrss / (1024.0 * 1024.0);
    #else
        double dynamic_mb = usage.ru_maxrss / 1024.0;
    #endif
 
    double static_mb = 0;
    #ifdef __APPLE__
        // Quét cả phân vùng __bss lẫn __common (nơi chứa mảng tĩnh chưa khởi tạo)
        const struct section_64* bss_sect = getsectbyname("__DATA", "__bss");
        const struct section_64* common_sect = getsectbyname("__DATA", "__common");
        
        unsigned long total_bytes = 0;
        if (bss_sect) total_bytes += bss_sect->size;
        if (common_sect) total_bytes += common_sect->size;
        
        static_mb = (double)total_bytes / (1024.0 * 1024.0);
    #endif
 
    double total_mb = max(dynamic_mb - 1.30, static_mb);
 
    cerr << "
===============================
";
    cerr << "Time elapsed: " << fixed << setprecision(3) << elapsed_ms.count() << " ms (" 
         << elapsed_ms.count() / 1000.0 << " s)
";
    cerr << "Memory used : " << fixed << setprecision(2) << max(0.0, total_mb) << " MB
";
    cerr << "===============================
";
}
#else
void TIMER(chrono::high_resolution_clock::time_point) {}
#endif
 
void IO() 
{
    #ifdef LOCAL
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    #else
        string task_name = string(TASK);
        if (!task_name.empty()) 
        {
            if (FILE *f = fopen((task_name + ".inp").c_str(), "r")) 
            {
                fclose(f);
                freopen((task_name + ".inp").c_str(), "r", stdin);
                freopen((task_name + ".out").c_str(), "w", stdout);
            }
        }
    #endif
}
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
int Rand(int L, int R) 
{
    assert(L <= R);
    return uniform_int_distribution<int>(L, R)(rd);
}
struct Node 
{
    int sum;
    int minSuffix;
    Node operator + (const Node &other) const 
    {
        return {sum + other.sum, min(other.minSuffix, other.sum + minSuffix)};
    }
}st[4 * MAXN + 5];
int n, q; 
vi g[MAXN + 5];
int depth[MAXN + 5], par[MAXN + 5], heavy[MAXN + 5], sz[MAXN + 5];
int lazy[4 * MAXN + 5];
int a[MAXN + 5];
int pos[MAXN + 5], head[MAXN + 5];
int curPos = 0;
void dfs1(int u, int p)
{
    depth[u] = depth[p] + 1;
    par[u] = p;
    sz[u] = 1;
    int mxS = 0;
    EACH(v, g[u]) if(v != p)
    {
        dfs1(v, u);
        sz[u] += sz[v];
        if(sz[v] > mxS)
        {
            mxS = sz[v];
            heavy[u] = v;
        }
    }
}
void dfs2(int u, int h)
{
    head[u] = h;
    pos[u] = ++curPos;
    a[curPos] = 1;
    if(heavy[u] != -1) dfs2(heavy[u], h);
    for(int v : g[u])
    {
        if(v == par[u] || v == heavy[u]) continue;
        dfs2(v, v);
    }
}
void build(int id, int l, int r)
{
    if(l == r)
    {
        st[id] = {1,1};
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid); build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
}
void apply_lazy(int id, int l, int r) 
{
    int len = r - l + 1;
    st[id].sum = len;       
    st[id].minSuffix = 1;    
    lazy[id] = 1;   
}
void push(int id, int l, int r) 
{
    if (lazy[id]) 
    {  
        int mid = (l + r) / 2;
        apply_lazy(id * 2, l, mid);
        apply_lazy(id * 2 + 1, mid + 1, r);
        lazy[id] = 0;
    }
}
void updateRange(int ql, int qr, int id = 1, int l = 1, int r = n) 
{
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr) 
    {
        apply_lazy(id, l, r);
        return;
    }
    push(id, l, r);
    int mid = (l + r) / 2;
    updateRange(ql, qr, id * 2, l, mid);
    updateRange(ql, qr, id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
}
void updatePoint(int p, int val, int id = 1, int l = 1, int r = n) 
{
    if (l == r) 
    {
        st[id].sum += val;
        st[id].minSuffix += val;
        return;
    }
    push(id, l, r);
    int mid = (l + r) / 2;
    if (p <= mid) updatePoint(p, val, id * 2, l, mid);
    else updatePoint(p, val, id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
}
Node queryST(int ql, int qr, int id = 1, int l = 1, int r = n) 
{
    if (l > qr || r < ql) return {0, LLINF}; 
    if (l >= ql && r <= qr) return st[id];
    push(id, l, r);
    int mid = (l + r) / 2;
    if (qr <= mid) return queryST(ql, qr, id * 2, l, mid);
    if (ql > mid) return queryST(ql, qr, id * 2 + 1, mid + 1, r);
    return queryST(ql, qr, id * 2, l, mid) + queryST(ql, qr, id * 2 + 1, mid + 1, r);
}
Node queryPath(int u) 
{
    Node res = {0, LLINF};
    while (u != 0) 
    {
        Node cur = queryST(pos[head[u]], pos[u]);
        if (res.minSuffix == LLINF) res = cur;
        else res = cur + res;
        u = par[head[u]]; 
    }
    return res;
}
 
_______TOISECOGIAIVOI_______
{
    #ifdef LOCAL
        base_memory_mb = get_memory_usage(); 
    #endif
    fast;
    IO();
    auto start = chrono::high_resolution_clock::now();
    cin>>n>>q;
    FOR(i, 2, n)
    {
        int x; cin>>x;
        g[x].pb(i); g[i].pb(x);
    }
    memset(heavy, -1, sizeof heavy);
    curPos = 0;
    depth[1] = 0;
    dfs1(1, 0); 
    dfs2(1, 1);
    build(1,1,n);
    memset(lazy, 0, sizeof lazy);
    while (q--) 
    {
        int type, u; cin >> type >> u;
        if (type == 1) updatePoint(pos[u], -1);
        else if (type == 2) 
        {
            updateRange(pos[u], pos[u] + sz[u] - 1);
            int S = queryPath(u).minSuffix;
            if (S <= 0) updatePoint(pos[u], 1 - S);
        } 
        else 
        {
            Node res = queryPath(u);
            if (res.minSuffix <= 0) cout << "black";
            else cout << "white";
            cout<<endl;
        }
    }
    TIMER(start);
    KILL();
}