/*
========================================================
   Author  : duxp
   Purpose : Competitive Programming
   Note    : Think first. Code once.
   Rule    : Once AC, never touch
   Created at: 2026-01-26 19:35
========================================================
*/
#include <bits/stdc++.h>
 
#ifdef __APPLE__
#include <mach/mach.h>
#else
#include <unistd.h>
#endif
 
using namespace std;
 
#define ll long long
#define pb push_back
#define all(x) x.begin() + 1, x.end()
#define nall(x) x.begin(), x.end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mem(a, x) memset(a, x, sizeof(a))
 
#ifndef ONLINE_JUDGE
bool __LOCAL__ = true;
#else
bool __LOCAL__ = false;
#endif
 
#define dbg(x)     \
    if (__LOCAL__) \
    cerr << #x << " = " << (x) << '
'
#define dbg2(x, y)             \
    if (__LOCAL__)             \
    cerr << #x << " = " << (x) \
         << ", " << #y << " = " << (y) << '
'
#define dbg3(x, y, z)                  \
    if (__LOCAL__)                     \
    cerr << #x << " = " << (x)         \
         << ", " << #y << " = " << (y) \
         << ", " << #z << " = " << (z) << '
'
#define el         \
    if (__LOCAL__) \
    cerr << '
'
 
template <typename T>
void dbgvec(const vector<T> &v, const string &name = "")
{
    if (!__LOCAL__)
        return;
    if (!name.empty())
        cerr << name << " = ";
    cerr << "[ ";
    for (auto &x : v)
        cerr << x << " ";
    cerr << "]
";
}
 
template <typename K, typename V>
void dbgmp(const map<K, V> &mp, const string &name = "")
{
    if (!__LOCAL__)
        return;
    if (!name.empty())
        cerr << name << " = ";
    cerr << "{
";
    for (auto &p : mp)
        cerr << "  " << p.first << " : " << p.second << '
';
    cerr << "}
";
}
 
template <typename T>
void dbgset(const set<T> &s, const string &name = "")
{
    if (!__LOCAL__)
        return;
    if (!name.empty())
        cerr << name << " = ";
    cerr << "{ ";
    for (auto &x : s)
        cerr << x << " ";
    cerr << "}
";
}
 
#ifndef ONLINE_JUDGE
auto __START_TIME = chrono::high_resolution_clock::now();
#endif
 
static inline long long get_memory_mb()
{
#ifdef __APPLE__
    task_basic_info_data_t info;
    mach_msg_type_number_t count = TASK_BASIC_INFO_COUNT;
    if (task_info(mach_task_self(), TASK_BASIC_INFO,
                  (task_info_t)&info, &count) != KERN_SUCCESS)
        return -1;
    return info.resident_size / (1024 * 1024);
#else
#endif
}
 
static inline void dbg_memory()
{
    if (!__LOCAL__)
        return;
    long long mem = get_memory_mb();
    cerr << "RAM: " << mem << " MB";
    if (mem <= 256)
        cerr << "  (OK @256MB)";
    else if (mem <= 512)
        cerr << "  (OK @512MB)";
    else if (mem <= 1024)
        cerr << "  (OK @1024MB)";
    else
        cerr << "  (RISKY >1024MB)";
    cerr << '
';
}
 
#define trailingzero(x) __builtin_ctzll(x)
#define cntbit1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
 
#define _______TOISETHIVOI_______ signed main()
#define KILL() exit(0)
#define NAME "duxp"
 
struct duxp_hash
{
    unsigned long long C;
    unsigned int RANDOM;
 
    duxp_hash()
    {
        C = (unsigned long long)(2e18 * acos(0)) + 71;
        RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    }
 
    size_t operator()(unsigned long long x) const
    {
        return __builtin_bswap64((x ^ RANDOM) * C);
    }
};
 
template <typename T>
inline int getbit(T x, int k) { return (x >> k) & 1; }
template <typename T>
inline T onbit(T x, int k) { return x | (T(1) << k); }
template <typename T>
inline T offbit(T x, int k) { return x & ~(T(1) << k); }
 
template <typename T>
inline bool minimize(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
inline bool maximize(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
 
const ll OO = 1e18;
const int oo = 1e9;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAXN = 200000;
int n;
int a[MAXN];
_______TOISETHIVOI_______
{
    fast;
 
#ifndef ONLINE_JUDGE
    freopen(NAME ".inp", "r", stdin);
    freopen(NAME ".out", "w", stdout);
#endif
 
    // === SOLUTION GOES HERE ===
    cin >> n;
    int mx = -oo;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if (mx <= 0)
    {
        for (int k = 1; k <= max(1, mx); k++) cout << 0 << " ";
        cout << '
';
        KILL();
    }
 
    vector<ll> ans(mx + 3, 0);
    if (a[1] > 0)
    {
        for (int k = 1; k <= mx;)
        {
            ll val = (a[1] + k - 1) / k; 
            int r = a[1] / val;
 
            if (r < k) r = k;       
            if (r > mx) r = mx;
 
            ans[k] += val;
            ans[r + 1] -= val;
 
            k = r + 1;
        }
    }
 
    for (int i = 1; i < n; i++)
    {
        ll A = a[i + 1] - 1;
        ll B = a[i] - 1;
        if (A < 0 || B < 0)
            continue;
 
        for (int k = 1; k <= A;)
        {
            ll x = A / k;
            ll y = B / k;
 
            ll rA = (x > 0 ? A / x : mx);
            ll rB = (y > 0 ? B / y : mx);
            ll r = min({rA, rB, (ll)mx});
 
            if (r < k) r = k;  
 
            if (x > y)
            {
                ans[k] += (x - y);
                ans[r + 1] -= (x - y);
            }
 
            k = r + 1;
        }
    }
 
    ll cur = 0;
    for (int k = 1; k <= mx; k++)
    {
        cur += ans[k];
        cout << cur << " ";
    }
    // === END SOLUTION HERE ===
 
#ifndef ONLINE_JUDGE
    auto __END_TIME = chrono::high_resolution_clock::now();
    cerr << "Time: "
         << chrono::duration<double>(__END_TIME - __START_TIME).count()
         << "s
";
    dbg_memory();
#endif
 
    KILL();
}
// I LOVE MYSELF
/*
Chắc là với mỗi k, bắt đầu điện từ ô nào thì số lần giật cg như nhau (test tay <("))
K bé nhất là 1
có thể thấy đáp án lúc này là a[1] + max(a[2] - a[1], 0) + max(a[3] - a[2], 0) + ... + max(a[n] - a[n - 1], 0)
Vậy xét thử các k khác:
Lúc này nhận ra mỗi a[i] sẽ cần ceil(a[i] / k)
=> không khác gì k = 1
vậy chỉ cần gán a[i] = ceil(a[i] / k) rồi công thức như cũ
công thức viết lại là:
    ceil(a[i] / k) + max(ceil(a[2] / k) - ceil(a[1] / k), 0) + ... như cũ
Optimize
Chia đoạn
Xét a[i], a[i + 1] chỉ đóng góp khi:
(a[i+1] - 1) / k > (a[i] - 1) / k
=> (a[i + 1] - 1) / k - (a[i] - 1) / k > 0
Nhận xét:
- Với mỗi k, đáp án có dạng:
    ceil(a[1] / k)
    + sum max(ceil(a[i] / k) - ceil(a[i-1] / k), 0)
 
- Điều kiện để (a[i], a[i+1]) đóng góp:
    ceil(a[i+1] / k) > ceil(a[i] / k)
 
- Quy đổi:
    ceil(x / k) = (x - 1) / k + 1
=> xét:
    (a[i+1] - 1) / k > (a[i] - 1) / k
Chia đoạn theo k:
- Với A = a[i+1] - 1, B = a[i] - 1
- Fix k = l:
    x = A / l
    y = B / l
- Giá trị x, y không đổi trên đoạn:
    k ∈ [l, min(A/x, B/y)]
 
Nếu x > y:
- đóng góp (x - y) cho toàn bộ đoạn k đó
 
Dùng mảng hiệu ans[] để cộng nhanh
Cuối cùng prefix sum để ra đáp án cho từng k
 
 
*/