/*
Author: duxp
Date: 
Note: 
The king has returned, and the throne has been reclaimed.
The racer has returned, and the track is ready to be fired up again.
The coder has returned, and new problems are ready to be solved.
*/
#include <bits/stdc++.h>
 
#ifndef ONLINE_JUDGE
    #ifdef __APPLE__
        #include <mach/mach.h>
    #endif
#endif
 
using namespace std;
 
#define ll long long
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
 
template <class T, class U> inline bool minimize(T &x, const U &y) { return x > y ? (x = y, true) : false; }
template <class T, class U> inline bool maximize(T &x, const U &y) { return x < y ? (x = y, true) : false; }
template <class T, class U> constexpr int add(T x, U y) { return ((x % MOD) + (y % MOD)) % MOD; }
template <class T, class U> constexpr int sub(T x, U y) { return ((x % MOD) - (y % MOD) + MOD) % MOD; }
template <class T, class U> constexpr int mul(T x, U y) { return ((x % MOD) * (y % MOD)) % MOD; }
 
int n;
int a[MAXN + 5];
vpii DIV[MAXN + 5];
int par[MAXN + 5], szz[MAXN + 5];
ll res[MAXN + 5];       
int mp[MAXN + 5];
ll preDIVs[MAXN + 5]; 
 
int vis_node[MAXN + 5], vis_root[MAXN + 5];
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
 
vi getDIV(int x)
{
    vi ans;
    for(int i = 1; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            ans.pb(i);
            if(i * i != x) ans.pb(x / i);
        }
    }
    return ans;
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
    force_memory_allocation();
    
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vi DIVs = getDIV(a[i]);
        for(int x : DIVs) mp[x]++; 
    }
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v; cin >> u >> v;
        int d = gcd(a[u], a[v]);
        DIV[d].pb({u, v});
    }
    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
        szz[i] = 1;
    }
    for(int d = 1; d <= 2e5; d++)
    {
        vi used;
        for(int i = d; i <= 2e5; i += d)
        {
            for(auto &j : DIV[i])
            {
                join(j.fi, j.se);
                if (vis_node[j.fi] != d) 
                {
                    vis_node[j.fi] = d;
                    used.pb(j.fi);
                }
                if (vis_node[j.se] != d) 
                {
                    vis_node[j.se] = d;
                    used.pb(j.se);
                }
            }
        }
        
        if (used.empty()) {
            preDIVs[d] += mp[d];
            continue;
        }
        for(int u : used)
        {
            int root = fs(u);
            if (vis_root[root] != d) 
            {
                vis_root[root] = d; 
                ll sz = szz[root];
                preDIVs[d] += (sz * (sz + 1)) / 2; 
            }
        }
        
        preDIVs[d] += mp[d];
        for(int u : used)
        {
            if(a[u] % d == 0) preDIVs[d]--;
            par[u] = u;
            szz[u] = 1;
        }
    }
    fill(res + 1, res + MAXN + 4, 0);
    for(int i = MAXN; i >= 1; i--)
    {
        res[i] = preDIVs[i];
        for(int j = i + i; j <= MAXN; j += i) res[i] -= res[j];
    }
    for(int i = 1; i <= 2e5; i++)
    {
        if(res[i] == 0) continue;
        else cout << i << " " << res[i] << endl;
    }
    
    log_resource();
    KILL();
}