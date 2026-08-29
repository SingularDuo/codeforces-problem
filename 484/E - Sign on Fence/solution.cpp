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
 
Trâu: For L từ l -> r, maximize(min(L -> L + w))
idea tối ưu 1: st[id][w]
Struct Node 
{
    int id, minRange;
}
merge()
{
    ezgg
}
=> MLE
cnp đáp án
lm s check?
các vị trí >= gán = 1, ngược lại = 0
xem có đoạn nào liên tiếp dài = w có tổng >= w không
 
 
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
struct PersistentSegmentTree 
{
    struct Node 
    {
        int maxOne = 0;
        int pref = 0, suff = 0;
        int len = 0;
        int left = 0, right = 0;
    };
    vector<Node> tree;
    vi root;
    int n;
    PersistentSegmentTree(int n) : n(n)
    {
        tree.pb(Node());    
        root.pb(0);
    }
    Node merge(const Node &a, const Node &b)
    {
        if(a.len == 0) return b;
        if(b.len == 0) return a;
        Node res;
        res.len = a.len + b.len;
        res.pref = (a.pref == a.len) ? a.len + b.pref : a.pref;
        res.suff = (b.suff == b.len) ? b.len + a.suff : b.suff;
        res.maxOne = max({a.maxOne, b.maxOne, a.suff + b.pref});
        return res;
    }
    int update(int prevNode, int l, int r, int pos, int val)
    {
        int cur = tree.size();
        tree.pb(tree[prevNode]);
        if(l == r)
        {
            tree[cur].len = 1;
            tree[cur].maxOne = tree[cur].pref = tree[cur].suff = val;
            return cur;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) tree[cur].left = update(tree[prevNode].left, l, mid, pos, val);
        else tree[cur].right = update(tree[prevNode].right, mid + 1, r, pos, val);
        Node merged = merge(tree[tree[cur].left], tree[tree[cur].right]);
        tree[cur].maxOne = merged.maxOne;
        tree[cur].pref = merged.pref;
        tree[cur].suff = merged.suff;
        tree[cur].len = merged.len;
        return cur;
    }
    void addVersion(int pos, int val)
    {
        root.pb(update(root.back(), 1, n, pos, val));
    }
    Node queryNode(int node, int l, int r, int ql, int qr) 
    {
        if (!node || l > qr || r < ql) return Node();
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        Node resL = queryNode(tree[node].left, l, mid, ql, qr);
        Node resR = queryNode(tree[node].right, mid + 1, r, ql, qr);
        return merge(resL, resR);
    }
    int build(int l, int r) {
        int curNode = tree.size();
        Node cur = Node();
        tree.pb(cur);
        if (l == r) {
            tree[curNode].len = 1;
            return curNode;
        }
        int mid = (l + r) >> 1;
        int lc = build(l, mid);
        int rc = build(mid + 1, r);
        tree[curNode].left = lc;
        tree[curNode].right = rc;
        Node merged = merge(tree[lc], tree[rc]);
        tree[curNode].len = merged.len;
        return curNode;
    }
};
int n;
int h[MAXN + 5];
int m;
vector<pair<int,int>> coord;
// int getID(int x){return lower_bound(nall(coord), x) - coord.begin() + 1;}
 
 
_______TOISECOGIAIVOI_______
{
    #ifdef LOCAL
        base_memory_mb = get_memory_usage(); 
    #endif
    fast;
    IO();
    auto start = chrono::high_resolution_clock::now();
    cin>>n;
    FOR(i, 1, n) 
    {
        cin>>h[i];
        coord.pb(make_pair(h[i], i));
    }
    sort(nall(coord), greater<pii>());
    // coord.erase(unique(nall(coord)), coord.end());
    // FOR(i, 1, n) h[i] = getID(h[i]);
    PersistentSegmentTree pst(n);
    pst.root[0] = pst.build(1, n);
    FOR(k, 0, (int)coord.size() - 1) {
        int pos = coord[k].se;
        pst.root.pb(pst.update(pst.root.back(), 1, n, pos, 1));
    }
    cin>>m;
    while(m--)
    {
        int l, r, w; cin>>l>>r>>w;
        // maxH minH
        int low = 1, high = n, ans = -1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            int cur = pst.queryNode(pst.root[mid], 1, n, l, r).maxOne;
            if (cur >= w) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (ans != -1)
            cout << coord[ans - 1].fi << "
";
        else
            cout << "-1
";
    }
    TIMER(start);
    KILL();
}