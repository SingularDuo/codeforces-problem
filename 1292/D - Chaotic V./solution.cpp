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
constexpr int MOD = 1000000007, MOD2 = 998244353, MAXN = 1000000, LOG = 20, BLOCK = 450;
constexpr int ALPHA = 26, BIT = 30, MAXK = 5000;
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
/*
mỗi số k! sẽ chia được cho 2 f(x) lần liên tục
với f(x) là số lần số 2 xuất hiện, ví dụ 8! có 7 lần xuất hiện
luôn tạo ra cây vì t thích
gốc là đỉnh 1
num[x][y]
*/
const int prime[675] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 
    83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 
    191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 
    293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
     419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 
     541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 
     653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 
     787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 
     919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 
     1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 
     1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277,
      1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749, 2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001, 3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079, 3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181, 3187, 3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 3259, 3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 3343, 3347, 3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 3433, 3449, 3457, 3461, 3463, 3467, 3469, 3491, 3499, 3511, 3517, 3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571, 3581, 3583, 3593, 3607, 3613, 3617, 3623, 3631, 3637, 3643, 3659, 3671, 3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727, 3733, 3739, 3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821, 3823, 3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889, 3907, 3911, 3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967, 3989, 4001, 4003, 4007, 4013, 4019, 4021, 4027, 4049, 4051, 4057, 4073, 4079, 4091, 4093, 4099, 4111, 4127, 4129, 4133, 4139, 4153, 4157, 4159, 4177, 4201, 4211, 4217, 4219, 4229, 4231, 4241, 4243, 4253, 4259, 4261, 4271, 4273, 4283, 4289, 4297, 4327, 4337, 4339, 4349, 4357, 4363, 4373, 4391, 4397, 4409, 4421, 4423, 4441, 4447, 4451, 4457, 4463, 4481, 4483, 4493, 4507, 4513, 4517, 4519, 4523, 4547, 4549, 4561, 4567, 4583, 4591, 4597, 4603, 4621, 4637, 4639, 4643, 4649, 4651, 4657, 4663, 4673, 4679, 4691, 4703, 4721, 4723, 4729, 4733, 4751, 4759, 4783, 4787, 4789, 4793, 4799, 4801, 4813, 4817, 4831, 4861, 4871, 4877, 4889, 4903, 4909, 4919, 4931, 4933, 4937, 4943, 4951, 4957, 4967, 4969, 4973, 4987, 4993, 4999};
int n;
int a[MAXN + 5];
int num[5000 + 5][670 + 5];
vi g[MAXN + 5];
int sumDist1 = 0;
int legendre(int k, int p) 
{
    int cnt = 0;
    while (k > 0) 
    {
        cnt += k / p;
        k /= p;
    }
    return cnt;
}
 
_______TOISECOGIAIVOI_______
{
    #ifdef LOCAL
        base_memory_mb = get_memory_usage(); 
    #endif
    fast;
    IO();
    auto start = chrono::high_resolution_clock::now();
    cin>>n;
    FOR(i, 1, n) cin>>a[i];
    for (int v = 1; v <= MAXK; v++) for (int j = 1; j <= 669; j++) 
    {
        if (prime[j] <= v)  num[v][j] = legendre(v, prime[j]);
        else break;
    }
    // for(int i = 1; i <= n; i++) 
    // {
    //     debug(i);
    //     for(int j = 1; j <= 5; j++) debug(j, num[a[i]][j]);
    // }
    // sumDistRoot();
    // cout<<sumDist1;
    sumDist1 = 0;
    FOR(i, 1, n) FOR(j, 1, 670) sumDist1 += num[a[i]][j];
    int cnt[MAXN + 5] = {0};
    FOR(i, 1, n) cnt[a[i]]++;   
    vi topP(5005, 0);
    vi cand;
    FOR(k, 1, 5000) if(cnt[k] != 0)
    {
        cand.pb(k);
        FORD(j, 1, 669) if (num[k][j] > 0) 
        {
            topP[k] = j;
            break;
        }
    }
    cerr<<cand.size()<<endl;
    while(true)
    {
        vi groupCnt(673, 0);
        for(int k : cand) if(topP[k] > 0) groupCnt[topP[k]] += cnt[k];
        int bestP = -1;
        FOR(j, 1, 670) if (groupCnt[j] > n / 2) 
        {
            bestP = j;
            break;
        }
        if(bestP == -1) break;
        int inB = groupCnt[bestP];
        sumDist1 += (n - inB) - inB;
        vi nxtCand;
        for(int k : cand) if(topP[k] == bestP)
        {
            nxtCand.pb(k);
            num[k][bestP]--;
            while (topP[k] > 0 && num[k][topP[k]] == 0) topP[k]--;
        }
        cand = nxtCand;
    }
    cout<<sumDist1;
    TIMER(start);
    KILL();
}