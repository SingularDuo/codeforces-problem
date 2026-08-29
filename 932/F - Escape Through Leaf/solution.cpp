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
constexpr int ALPHA = 26, BIT = 30, MINX = -100000, MAXX = 100000;
const unsigned long long NEXT_PRIME[] = {0, 11ULL, 101ULL, 1009ULL, 10007ULL, 100003ULL, 1000003ULL, 10000019ULL, 100000007ULL, 1000000007ULL, 10000000019ULL};
 
template <class T, class U> inline bool minimize(T &x, const U &y) { return x > y ? (x = y, true) : false; }
template <class T, class U> inline bool maximize(T &x, const U &y) { return x < y ? (x = y, true) : false; }
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
int Rand(int L, int R) 
{
    assert(L <= R);
    return uniform_int_distribution<int>(L, R)(rd);
}
struct Line 
{
    int m, b;
    Line(int _m = 0, int _b = 4e18) : m(_m), b(_b) {}
    
    int get(int x) const {
        return m * x + b;
    }
};
struct Node 
{
    Line line;
    int left, right;
    Node (int _left = 0, int _right = 0) : left(_left), right(_right) {} 
};
vector<Node> lichaoTree(1);
int addLine(int treeID, Line nw, int l = MINX, int r = MAXX)
{
    if(!treeID)
    {
        treeID = lichaoTree.size();
        lichaoTree.pb(Node());
    }
    int mid = l + (r - l ) / 2;
    bool lef = nw.get(l) < lichaoTree[treeID].line.get(l);
    bool midBetter = nw.get(mid) < lichaoTree[treeID].line.get(mid);
    if (midBetter) swap(nw, lichaoTree[treeID].line);
    if (l == r) return treeID;
    if (lef != midBetter) lichaoTree[treeID].left = addLine(lichaoTree[treeID].left, nw, l, mid);
    else lichaoTree[treeID].right = addLine(lichaoTree[treeID].right, nw, mid + 1, r);
    return treeID;
}
int query(int treeID, int x, int l = MINX, int r = MAXX)
{
    if(!treeID) return OO;
    int res = lichaoTree[treeID].line.get(x);
    if(l == r) return res;
    int mid = l + (r - l) / 2;
    if(x <= mid) return min(res, query(lichaoTree[treeID].left, x, l, mid));
    else return min(res, query(lichaoTree[treeID].right, x, mid + 1, r));
}
int merge(int u, int v, int l = MINX, int r = MAXX) 
{
    if (!u || !v) return u ? u : v;
    if (l == r) 
    {
        if (lichaoTree[v].line.get(l) < lichaoTree[u].line.get(l)) lichaoTree[u].line = lichaoTree[v].line;
        return u;
    }
 
    int mid = l + (r - l) / 2;
    lichaoTree[u].left = merge(lichaoTree[u].left, lichaoTree[v].left, l, mid);
    lichaoTree[u].right = merge(lichaoTree[u].right, lichaoTree[v].right, mid + 1, r);
    
    return addLine(u, lichaoTree[v].line, l, r);
}
int n;
int a[MAXN + 5], b[MAXN + 5], deg[MAXN + 5];
vi g[MAXN + 5];
int dp[MAXN + 5];
 
int dfs(int u = 1, int p = -1) 
{
    bool isLeaf = (deg[u] == 1 && u != 1);
    if (isLeaf) 
    {
        dp[u] = 0;
        int ru = 0;
        return addLine(ru, Line(b[u], dp[u]));
    }
    int ru = 0;
    EACH(v, g[u]) 
    {
        if (v == p) continue;
        int rv = dfs(v, u);
        ru = merge(ru, rv);
    }
    dp[u] = query(ru, a[u]);
    return addLine(ru, Line(b[u], dp[u]));
}
 
_______TOISECOGIAIVOI_______
{
    fast;
    #ifdef LOCAL
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    #else
       // freopen("task.inp", "r", stdin);
       // freopen("task.out", "w", stdout);
    #endif
    cin>>n;
    
    FOR(i, 1, n) cin>>a[i];
    FOR(i, 1, n) cin>>b[i];
    FOR(i, 1, n - 1)
    {
        int u, v; cin>>u>>v;
        g[u].pb(v); g[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    dfs();
    FOR(i, 1, n) cout<< ((dp[i] == INF) ? 0 : dp[i]) << " ";
    KILL();
}