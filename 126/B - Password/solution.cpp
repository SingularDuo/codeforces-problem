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
constexpr int BASE = 311;
 
const unsigned long long NEXT_PRIME[] = {0, 11ULL, 101ULL, 1009ULL, 10007ULL, 100003ULL, 1000003ULL, 10000019ULL, 100000007ULL, 1000000007ULL, 10000000019ULL};
 
template <class T, class U> inline bool minimize(T &x, const U &y) { return x > y ? (x = y, true) : false; }
template <class T, class U> inline bool maximize(T &x, const U &y) { return x < y ? (x = y, true) : false; }
template <class T, class U> constexpr int add(T x, U y) { return ((x % MOD) + (y % MOD)) % MOD; }
template <class T, class U> constexpr int sub(T x, U y) { return ((x % MOD) - (y % MOD) + MOD) % MOD; }
template <class T, class U> constexpr int mul(T x, U y) { return ((x % MOD) * (y % MOD)) % MOD; }
 
string s; 
int n;
struct StringHash {
    static const int MOD1 = 1000000007;
    static const int MOD2 = 1000000009;
 
    int n, BASE;
    vector<int> h1, h2, pw1, pw2;
 
    StringHash() {}
 
    StringHash(const string &s, int base = 311) {
        init(s, base);
    }
 
    void init(const string &s, int base = 311) {
        BASE = base;
        n = s.size();
 
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        pw1.assign(n + 1, 1);
        pw2.assign(n + 1, 1);
 
        for (int i = 1; i <= n; i++) {
            pw1[i] = 1LL * pw1[i - 1] * BASE % MOD1;
            pw2[i] = 1LL * pw2[i - 1] * BASE % MOD2;
 
            h1[i] = (1LL * h1[i - 1] * BASE + s[i - 1]) % MOD1;
            h2[i] = (1LL * h2[i - 1] * BASE + s[i - 1]) % MOD2;
        }
    }
 
    pair<int, int> getHash(int l, int r) {
        ++l; ++r;
 
        int x1 = (h1[r] - 1LL * h1[l - 1] * pw1[r - l + 1] % MOD1 + MOD1) % MOD1;
        int x2 = (h2[r] - 1LL * h2[l - 1] * pw2[r - l + 1] % MOD2 + MOD2) % MOD2;
 
        return {x1, x2};
    }
};
bool check(int len, StringHash &hash)
{
    pii hash1 = hash.getHash(0, len - 1);
    pii hash2 = hash.getHash(s.size() - len, s.size() - 1);
    if (hash1.fi != hash2.fi || hash1.se != hash2.se) return false;
    for (int i = 1; i <= (int)s.size() - len - 1; i++)
    {
        pii hash3 = hash.getHash(i, i + len - 1);
        if (hash3.fi == hash1.fi && hash3.se == hash1.se)  return true;
    }
    return false;
}
 
_______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) 
    {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    
    cin >> s;
    n = s.size();
    StringHash hash(s, 311);
    vector<int> ngon;
    for (int len = 1; len < n; len++)
    {
        if (hash.getHash(0, len - 1) == hash.getHash(n - len, n - 1)) ngon.pb(len);
    }
    int l = 0, r = (int)ngon.size() - 1;
    int res = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(ngon[mid], hash))
        {
            res = ngon[mid]; 
            l = mid + 1;
        }
        else r = mid - 1;
    }
    
    if (res == -1)  cout << "Just a legend";
    else cout << s.substr(0, res);
    
    KILL();
}