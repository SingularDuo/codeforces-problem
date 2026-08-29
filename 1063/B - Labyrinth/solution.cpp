/*
Author: duxp
Date: 
Note: 
Nếu muốn đến được ô mới (x,y) từ ô bắt đầu (r,c) thì phải thỏa:
c + stepR - stepL = y
stepR - stepL = y - c = X
stepR = X + stepL
=> minimize stepL cũng minimize stepR
 
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
inline int getbit(T x, int k) { return (x >> k) & 1; }
template <typename T>
inline T onbit(T x, int k) { return x | (T(1) << k); }
template <typename T>
inline T offbit(T x, int k) { return x & ~(T(1) << k); }
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
const ll OO = 0x7FFFFFFFFFFFFFFFLL;
const int oo = 0x7FFFFFFF;
const int INF = 0x3f3f3f3f;
const int LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 100000007;
const int MAXN = 200000;
const int MOD2 = 998244353;
 
 
inline bool minimize(int &x, int y) { return x > y ? (x = y, true) : false; }
inline bool maximize(int &x, int y) { return x < y ? (x = y, true) : false; }
inline int add(int x, int y) { return (x % MOD + y % MOD) % MOD; }
inline int sub(int x, int y) { return (x % MOD - y % MOD + MOD) % MOD; }
inline int mul(int x, int y) { return (x % MOD * y % MOD) % MOD; }
 
int n, m, r, c, x, y;
char a[2005][2005];
int dist[2005][2005];
 
                            _______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    force_memory_allocation();
    cin >> n >> m >> r >> c >> x >> y;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    mem(dist, INF);
    dist[r][c] = 0;
    deque<pii> dq;
    dist[r][c] = 0;
 
    dq.push_front({r, c});
 
    while(!dq.empty())
    {
        pii curr = dq.front();
        dq.pop_front();
 
        int u = curr.fi;
        int v = curr.se;
 
        for(int i = 0; i < 4; i++)
        {
            int nx = u + dx[i];
            int ny = v + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(a[nx][ny] == '*') continue;
            int w = (i == 3); 
            if(dist[nx][ny] > dist[u][v] + w)
            {
                dist[nx][ny] = dist[u][v] + w;
                if(w == 0) dq.push_front({nx, ny});
                else dq.push_back({nx, ny});
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int stepL = dist[i][j];
            int X = j - c;
            int stepR = X + stepL;
            if(stepL <= x && stepR <= y && stepL != -1) res++;
        }
    }
    cout << res;
    log_resource();
    KILL();
}