/*
Author: duxp
Date: 
Note: 
The king has returned, and the throne has been reclaimed.
The racer has returned, and the track is ready to be fired up again.
The coder has returned, and new problems are ready to be solved.
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
 
#ifndef ONLINE_JUDGE
    #ifdef __APPLE__
        #include <mach/mach.h>
    #endif
#endif
 
using namespace std;
 
#define ll long long
#define int ll
#define ld long double 
#define pb push_back
#define all(x) x.begin() + 1, x.end()
#define nall(x) x.begin(), x.end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define vpii vector<pii>
#define endl '
'
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, x) memset(a, x, sizeof(a))
#define YESNO(x) if(x) cout<<"YES";  else cout<<"NO";
 
#define _______TOISECOGIAIVOI_______ signed main()
#define KILL() exit(0)
#define NAME "duxp"
#ifndef ONLINE_JUDGE
    #ifdef __APPLE__
        #include <mach/mach.h>
        #include <mach-o/getsect.h>
        #include <mach-o/dyld.h>
        extern "C" struct mach_header_64 _mh_execute_header;
    #endif
    void force_memory_allocation() {
        #ifdef __APPLE__
            unsigned long size;
            const char* sections[] = {"__bss", "__common"};
            
            for (const char* sec : sections) {
                uint8_t* ptr = getsectiondata(&_mh_execute_header, "__DATA", sec, &size);
                if (ptr) {
                    for (unsigned long i = 0; i < size; i += 4096) {
                        *(volatile char*)(ptr + i) = *(ptr + i);
                    }
                }
            }
        #endif
    }
    void log_resource() {
        double mem_mb = 0;
        #ifdef __APPLE__
            struct task_basic_info t_info;
            mach_msg_type_number_t t_info_count = TASK_BASIC_INFO_COUNT;
            if (task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&t_info, &t_info_count) == KERN_SUCCESS) {
                mem_mb = t_info.resident_size / (1024.0 * 1024.0);
            }
            mem_mb -= 1.5; 
            if (mem_mb < 0) mem_mb = 0;
        #else
            struct rusage usage;
            if (getrusage(RUSAGE_SELF, &usage) == 0) {
                mem_mb = usage.ru_maxrss / 1024.0;
            }
        #endif
 
        cerr << fixed << setprecision(3) << "
========== DEBUG ==========
";
        cerr << "Time: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms
";
        cerr << "Memory (User): " << mem_mb << " MB
";
        cerr << "===========================
";
    }
#else
    void force_memory_allocation() {}
    void log_resource() {}
#endif
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
struct Debug 
{
    static void print(long long x) { std::cerr << x; }
    static void print(double x) { std::cerr << x; }
    static void print(long double x) { std::cerr << x; }
    static void print(char x) { std::cerr << '\'' << x << '\''; }
    static void print(const std::string &x) { std::cerr << '"' << x << '"'; }
    static void print(const char* x) { std::cerr << '"' << x << '"'; }
    static void print(bool x) { std::cerr << (x ? "true" : "false"); }
 
    template<typename...> using void_t = void;
    template<typename T, typename = void>
    struct is_iterable : std::false_type {};
    template<typename T>
    struct is_iterable<T, void_t<decltype(std::begin(std::declval<T>())), decltype(std::end(std::declval<T>()))>> : std::true_type {};
    template<typename A, typename B>
    static void print(const std::pair<A, B> &p) {
        std::cerr << "("; print(p.first); std::cerr << ", "; print(p.second); std::cerr << ")";
    }
    template<typename T, typename std::enable_if<is_iterable<T>::value && !std::is_same<T, std::string>::value, int>::type = 0>
    static void print(const T &v) {
        std::cerr << "[";
        bool first = true;
        for (const auto &x : v) {
            if (!first) std::cerr << ", ";
            print(x); 
            first = false;
        }
        std::cerr << "]";
    }
};
 
#define debug(x) std::cerr << #x << " = ", Debug::print(x), std::cerr << '
';
 
template <typename T>
constexpr int getbit(T x, int k) { return (x >> k) & 1; }
template <typename T>
constexpr T onbit(T x, int k) { return x | (T(1) << k); }
template <typename T>
constexpr T offbit(T x, int k) { return x & ~(T(1) << k); }
 
constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
 
constexpr ll OO = 0x7FFFFFFFFFFFFFFFLL;
constexpr int oo = 0x7FFFFFFF;
constexpr int INF = 0x3f3f3f3f;
constexpr int LLINF = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 1000000007;
constexpr int MAXN = 200000;
constexpr int MOD2 = 998244353;
constexpr int LOG = 20;
 
const unsigned long long NEXT_PRIME[] = {0, 11ULL, 101ULL, 1009ULL, 10007ULL, 100003ULL, 1000003ULL, 10000019ULL, 100000007ULL, 1000000007ULL, 10000000019ULL};
 
template <class T, class U> inline bool minimize(T &x, const U &y) { return x > y ? (x = y, true) : false; }
template <class T, class U> inline bool maximize(T &x, const U &y) { return x < y ? (x = y, true) : false; }
template <class T, class U> constexpr int add(T x, U y) { return ((x % MOD) + (y % MOD)) % MOD; }
template <class T, class U> constexpr int sub(T x, U y) { return ((x % MOD) - (y % MOD) + MOD) % MOD; }
template <class T, class U> constexpr int mul(T x, U y) { return ((x % MOD) * (y % MOD)) % MOD; }
struct edge
{
    int u, v, w;
}eds[MAXN + 5];
struct adjacent
{
    int to;
    bool good;
    int w;
};
bool cmp(adjacent a, adjacent b){return a.w < b.w;}
vector<adjacent> g[MAXN + 5];
vpii adj[MAXN + 5];
int n,m;
int timer = 0;
bitset<MAXN + 5> inMST;
int par[MAXN + 5], sz[MAXN + 5];
int up[MAXN + 5][LOG + 5], mx[MAXN + 5][LOG + 5], depth[MAXN + 5], parW[MAXN + 5];
int tin[MAXN + 5], tout[MAXN + 5];
bitset<MAXN + 5> badNode;
int fs(int u)
{
    if(u == par[u]) return u;
    return par[u] = fs(par[u]);
}
bool join(int u, int v)
{
    u = fs(u); v = fs(v);
    if(u == v) return false;
    if(sz[u] > sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    return true;
}
bitset<MAXN + 5> vis;
bool ngu = false;
int cntEdge = 0;
void dfsBrute(int u)
{
    vis[u] = true;
    for(auto &v : g[u])
    {
        int to = v.to, w = v.w;
        bool state = v.good;
        if(!vis[to])
        {
            cntEdge++;
            if(!state) ngu = true;
            dfsBrute(to);
        }
    }
}
void dfs(int u)
{
    tin[u] = ++timer;
    for(auto& ver : adj[u])
    {
        int v = ver.fi, w = ver.se;
        if(v == up[u][0]) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        mx[v][0] = w;
        parW[v] = w;
        for(int i = 1; i <= LOG; i++)
        {
            up[v][i] = up[up[v][i - 1]][i - 1];
            mx[v][i] = max(mx[v][i - 1], mx[up[v][i - 1]][i - 1]);
        }
        dfs(v);
    }
    tout[u] = timer;
}
pii lca(int u, int v)
{
    int val = -OO;
    if(depth[u] != depth[v])
    {
        if(depth[u] < depth[v]) swap(u, v);
        for(int i = LOG; i>=0;i--)
        {
            if(depth[up[u][i]] >= depth[v])
            {
                maximize(val, mx[u][i]);
                u = up[u][i];
            }
            if(depth[u] == depth[v]) break;
        }
    }
    if(u == v) return {u, v};
    for(int i = LOG; i>= 0; i--)
    {
        if(up[u][i] != up[v][i])
        {
            maximize(val, mx[u][i]);
            maximize(val, mx[v][i]);
            u = up[u][i];
            v = up[v][i];
        }
    }
    return {up[u][0], val};
}
int directChild(int u, int anc)
{
    if(u == anc) return -1;
    for(int i = LOG; i >= 0; i--)
    {
        if(depth[up[u][i]] > depth[anc]) u = up[u][i];
    }
    return u;
}
 
                            _______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    // force_memory_allocation();
    inMST.reset();
    cin>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        cin>>eds[i].u>>eds[i].v;
        eds[i].w = i;
    }
    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 1; i <= m; i++)
    {
        int u = eds[i].u, v = eds[i].v, w = eds[i].w;
        if(join(u, v))
        {
            inMST[i] = true;
            g[u].pb({v, true, w});
            g[v].pb({u, true, w});
            adj[u].pb({v, w}); adj[v].pb({u, w});
        }
    }
    vector<edge> badEds;
    for(int i = 1; i <= m; i++)
    {
        if(inMST[i]) continue;
        int u = eds[i].u, v = eds[i].v, w = eds[i].w;
        g[u].pb({v, false, w}); 
        g[v].pb({u, false, w});
        badEds.pb({u, v, w});
    }
    
    /*
    nhận xét:
    1. giả sử xét đường đi từ u -> v trong cây mst, luôn đảm bảo được rằng đường đi này
    sẽ bao gồm các cạnh có trọng số bé hơn một cạnh bất kì nằm ngoài mst
    từ đây, ta có nhận xét:
    giả sử xét cạnh u, v nằm ngoài cây mst
    nếu lca(u, v) (trong mst) != u và != v
    thì rõ ràng khi dfsBrute tới đỉnh root này, nó sẽ chọn 1 trong hai đường là đi xuống u 
    hoặc đi xuống v
    giả sử đi xuống u, nó sẽ đi qua các cạnh trên mst rồi sau đó gặp đỉnh u, lúc này , sau khi
    dfsBrute hết các cạnh, nó sẽ ở đỉnh u và thấy là đỉnh u có đường đi u - v thì nó sẽ đi vào
    -> lca này sẽ là 1 đỉnh ngu 
    -> tất cả các đỉnh mà nằm trên đường đi từ lca -> u (hoặc v) sẽ ngu luôn do dính phải cạnh u v
    dm
    lưu ý: nó chỉ hoạt động khi từ trên L xuống, còn nếu bắt đầu ở một đỉnh con trong 1 nhánh thì xử lí
    khác
    dm idea ngu l r
    Cây mst có tính chất:
    Khi lấy một cạnh ngoài cây mst gọi là e(u, v) thì sẽ tạo ra DUY NHẤT 1 chu trình, và cạnh e này sẽ có trọng số lớn nhất trong chu trình đó
    (Nếu trong chu trình có 1 cạnh thuộc mst mà có trọng số lớn hơn e thì ta có thể xóa cạnh đó và thay e vào để có mst mới nhỏ hơn)
    -> nếu cạnh ngoài cây đang xét lớn hơn cạnh lớn trong mst thì đó không phải vấn đề và ngược lại
    nếu lấy cạnh lớn nhất trên đường đi từ u tới v trên mst, thì đó là cạnh lớn nhất nhỏ nhất trong tất cả đường đi khác trong đồ thị
    đù logic sáng gần đúng 
    chỉnh lại:
    để thỏa mãn thì cây DFS tạo ra khi dfs từ đỉnh u phải giống chính xác cây mst
    giả sử xét cạnh (u v) ngoài cây
    ở trong mst, cặp u v có anc = lca
    1. thì nếu dfs từ một đỉnh ở ngoài cây con của anc
    khi xuống phía u hoặc v thì vì tính chất của dfs tham lam trong đề, nó bắt buộc đi sâu xuống, đến khi dừng lại ở u, kiểu gì cũng dùng
    cạnh u v này (dễ thấy)
    còn giả sử nó đi vào một nhánh W khác không chứa cả u, v (vẫn thuộc cây con gốc anc)
    vì nhánh W này ít nhất sẽ thiếu cả u và v nên không đạt đủ n - 1 cạnh -> kiểu gì cũng phải quay lại đi vào nhánh chứa u hoặc chứa v
    Nhưng mà w có thể dùng 1 cạnh khác ngoài cây, nhưng mà làm vậy thì cây dfs khác cây mst -> vẫn ngu
    nên kiểu gì cũng dính 
    2. Nếu R này nằm dưới u (hoặc v) lúc này sẽ dfs tạo ra được là u sẽ là tổ tiên của v trong cây dfs, nhưng vì tính chất cycle của mst, khi duyệt vô u
    nó sẽ chưa ngay lập tức dùng cạnh u v ngoài cây (vì w lớn hơn)
    -> vẫn sẽ lấy được v trước khi dùng đến cạnh ngoài cây, lúc này xét đến cnahj đó thì u v đều đã được thăm thì không thăm lại
    3. trường hợp R nằm trên đường đi từ u lên lca hoặc v lên lca, lúc này thì về bản chất R vẫn sẽ đụng vào u hoặc v trước bằng dfs và dùng đến cạnh 
    u v ngoài cây
    */
    for (int i = 0; i <= n + 1; i++) {
        fill(mx[i], mx[i] + LOG + 1, -OO);
    }
    fill(depth, depth + n + 1, 0);
    depth[1] = 1;
    dfs(1);
    vi diff(n + 2, 0);
    
    for(auto& i : badEds)
    {
        int u = i.u, v = i.v;
        pii l = lca(u, v);
        int anc = l.fi;
        if (anc == v) 
        {
            int p = directChild(u, v);
            diff[tin[p]] += 1;
            diff[tout[p] + 1] -= 1;
            diff[tin[u]] -= 1;
            diff[tout[u] + 1] += 1;
        }
        else if (anc == u) 
        {
            int p = directChild(v, u);
            diff[tin[p]] += 1;
            diff[tout[p] + 1] -= 1;    
            diff[tin[v]] -= 1;
            diff[tout[v] + 1] += 1;
        }
        else 
        {
            diff[1] += 1;
            diff[n + 1] -= 1;
            diff[tin[u]] -= 1;
            diff[tout[u] + 1] += 1;
            diff[tin[v]] -= 1;
            diff[tout[v] + 1] += 1;
        }
    }
    for(int i = 1; i <= n; i++) diff[i] += diff[i - 1];
    string s = "";
    for(int i = 1; i <= n; i++) 
    {
        if(diff[tin[i]] == 0) s += '1';
        else s += '0';
    }
    
    cout << s << endl;
    // log_resource();
    KILL();
}