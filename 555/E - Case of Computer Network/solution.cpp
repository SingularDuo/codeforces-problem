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
#define YESNO(x) cout << ((x) ? "Yes" : "No")
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
int n, m;
int p, numComp = 0;
bool possible = true;
vpii eds;
vpii g[MAXN + 5];
vpii gTree[MAXN + 5];
pii constraint[MAXN + 5];
string res;
int num[MAXN + 5], low[MAXN + 5], timerDfs = 0, delta[MAXN + 5], par[MAXN + 5];
int depth[MAXN + 5], up[MAXN + 5][LOG + 5];
int parEdge[MAXN + 5];
int upCnt[MAXN + 5], downCnt[MAXN + 5];
int comp[MAXN + 5];
bool visgTree[MAXN + 5];
bool isBridge[MAXN + 5];
vi order;
void dfs(int u, int par)
{
    num[u] = low[u] = ++timerDfs;
    int child = 0;
    for(auto &i : g[u])
    {
        int v = i.fi, eid = i.se;
        if(eid == par) continue;
        if(num[v]) low[u] = min(low[u], num[v]);
        else
        {
            child++;
            dfs(v, eid);
            low[u] = min(low[u], low[v]);
            if(low[v] > num[u]) isBridge[eid] = true;
        }
    }
}
void dfsComp(int u)
{
    comp[u] = numComp;
    for(auto &i : g[u])
    {
        int v = i.fi;
        int eid = i.se;
        if(isBridge[eid]) continue;
        if(comp[v]) continue;
        dfsComp(v);
    }
}
void buildgTree()
{
    FOR(i, 1, m)
    {
        if(!isBridge[i]) continue;
        int u = eds[i].fi, v = eds[i].se;
        int cu = comp[u];
        int cv = comp[v];
        gTree[cu].pb({cv, i}); gTree[cv].pb({cu, i});
    }
}
int rootComp[MAXN + 5];
void dfsgTree(int u, int p, int r)
{
    visgTree[u] = true;
    rootComp[u] = r;
    par[u] = p;
    up[u][0] = p;
    FOR(j, 1, LOG) up[u][j] = up[up[u][j - 1]][j - 1];
    for(auto &node : gTree[u])
    {
        int v = node.fi, eid = node.se;
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        par[v] = u;
        parEdge[v] = eid;
        dfsgTree(v, u, r);
    }
}
 
int LCA(int u, int v) 
{
    if(depth[u] < depth[v]) swap(u, v);
    FORD(j, 0, LOG) if(depth[u] - (1 << j) >= depth[v]) u = up[u][j];
    if(u == v) return u;
    FORD(j, 0, LOG) 
    {
        if(up[u][j] != up[v][j]) 
        {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}
void dfsSolve(int u, int p, string &res) 
{
    for(auto &node : gTree[u]) {
        int v = node.fi, eid = node.se;
        if(v == p) continue;
        dfsSolve(v, u, res);
        upCnt[u] += upCnt[v];
        downCnt[u] += downCnt[v];
        if(upCnt[v] > 0) 
        {
            if(comp[eds[eid].fi] == v) res[eid] = 'R';
            else res[eid] = 'L';
        } 
        else if(downCnt[v] > 0) 
        {
            if(comp[eds[eid].fi] == u) res[eid] = 'R';
            else res[eid] = 'L';
        } 
        else res[eid] = 'B';
    }
}
void dfsCheck(int u, int p)
{
    for(auto &node : gTree[u]) 
    {
        int v = node.fi;
        if(v == p) continue;
        dfsCheck(v, u);
        upCnt[u] += upCnt[v];
        downCnt[u] += downCnt[v];
        if(upCnt[v] > 0 && downCnt[v] > 0) possible = false;
    }
}
void solve()
{
    buildgTree();
    FOR(i, 1, numComp) if(!visgTree[i]) 
    {
        depth[i] = 1;
        dfsgTree(i, 0, i);
    }
    FOR(i, 1, p) 
    {
        int x = constraint[i].fi, y = constraint[i].se;
        int cu = comp[x], cv = comp[y];
        if(cu == cv) continue;
        if(rootComp[cu] != rootComp[cv]) 
        {
            possible = false;
            break;
        }
        
        int lca = LCA(cu, cv);
        upCnt[cu]++;
        upCnt[lca]--;
        downCnt[cv]++;
        downCnt[lca]--;
    }
    if(possible) FOR(i, 1, numComp) if(up[i][0] == 0) dfsCheck(i, 0);
    YESNO(possible);
}
_______TOISECOGIAIVOI_______
{
    #ifdef LOCAL
        base_memory_mb = get_memory_usage(); 
    #endif
    fast;
    IO();
    auto start = chrono::high_resolution_clock::now();
    cin>>n>>m>>p;
    eds.pb({0, 0});
    FOR(i, 1, m)
    {
        int u, v; cin>>u>>v;
        g[u].pb({v, i}); g[v].pb({u, i});
        eds.pb({u, v});
    }
    FOR(i, 1, p) cin>>constraint[i].fi>>constraint[i].se;
    res = 'X' + res; 
    FOR(i, 1, n) if(!num[i]) dfs(i, -1);
    FOR(i, 1, n) if(!comp[i])
    {
        ++numComp;
        dfsComp(i);
    }
    solve();
    TIMER(start);
    KILL();
}