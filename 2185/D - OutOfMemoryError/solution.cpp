/*
========================================================
   Author  : duxp
   Purpose : Competitive Programming
   Note    : Think first. Code once.
   Rule    : Once AC, never touch
   Created at: 2026-01-18 22:29
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
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, x) memset(a, x, sizeof(a))
 
#ifndef ONLINE_JUDGE
    bool __LOCAL__ = true;
#else
    bool __LOCAL__ = false;
#endif
 
#define dbg(x) if (__LOCAL__) cerr << #x << " = " << (x) << '
'
#define dbg2(x, y) if (__LOCAL__) cerr << #x << " = " << (x) \
                                         << ", " << #y << " = " << (y) << '
'
#define dbg3(x, y, z) if (__LOCAL__) cerr << #x << " = " << (x) \
                                            << ", " << #y << " = " << (y) \
                                            << ", " << #z << " = " << (z) << '
'
#define el if (__LOCAL__) cerr << '
'
 
template <typename T>
void dbgvec(const vector<T>& v, const string& name = "") {
    if (!__LOCAL__) return;
    if (!name.empty()) cerr << name << " = ";
    cerr << "[ ";
    for (auto &x : v) cerr << x << " ";
    cerr << "]
";
}
 
template <typename K, typename V>
void dbgmp(const map<K, V>& mp, const string& name = "") {
    if (!__LOCAL__) return;
    if (!name.empty()) cerr << name << " = ";
    cerr << "{
";
    for (auto &p : mp)
        cerr << "  " << p.first << " : " << p.second << '
';
    cerr << "}
";
}
 
template <typename T>
void dbgset(const set<T>& s, const string& name = "") {
    if (!__LOCAL__) return;
    if (!name.empty()) cerr << name << " = ";
    cerr << "{ ";
    for (auto &x : s) cerr << x << " ";
    cerr << "}
";
}
 
#ifndef ONLINE_JUDGE
auto __START_TIME = chrono::high_resolution_clock::now();
#endif
 
static inline long long get_memory_mb() {
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
 
static inline void dbg_memory() {
    if (!__LOCAL__) return;
    long long mem = get_memory_mb();
    cerr << "RAM: " << mem << " MB";
    if (mem <= 256) cerr << "  (OK @256MB)";
    else if (mem <= 512) cerr << "  (OK @512MB)";
    else if (mem <= 1024) cerr << "  (OK @1024MB)";
    else cerr << "  (RISKY >1024MB)";
    cerr << '
';
}
 
#define trailingzero(x) __builtin_ctzll(x)
#define cntbit1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
 
#define _______TOISETHIVOI_______ signed main()
#define KILL() exit(0)
#define NAME "duxp"
 
struct duxp_hash {
    unsigned long long C;
    unsigned int RANDOM;
 
    duxp_hash() {
        C = (unsigned long long)(2e18 * acos(0)) + 71;
        RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    }
 
    size_t operator()(unsigned long long x) const {
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
inline bool minimize(T &a, const T &b) {
    if (a > b) { a = b; return true; }
    return false;
}
template <typename T>
inline bool maximize(T &a, const T &b) {
    if (a < b) { a = b; return true; }
    return false;
}
 
const ll OO = 1e18;
const int oo = 1e9;
const int MOD1 = 1000000007;
const int MOD9 = 998244353;
const int MAXN = 200000;
ll a[MAXN], cura[MAXN];
bool used[MAXN];
void solve()
{
    int n, m;
    ll h;
    cin >> n >> m >> h;
    mem(used, false);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cura[i] = a[i];
    }
    int bad_cnt = 0;
    vi chg;
    while (m--)
    {
        int x;
        ll v;
        cin >> x >> v;
        if (!used[x])
        {
            used[x] = true;
            chg.pb(x);
        }
        if (cura[x] <= h && cura[x] + v > h) bad_cnt++;
        cura[x] += v;
        if (bad_cnt > 0)
        {
            for (int p : chg)
            {
                cura[p] = a[p];
                used[p] = false;
            }
            chg.clear();
            bad_cnt = 0;
        }
    }
    for (int i = 1; i <= n; i++) cout << cura[i] << " ";
    cout << endl;
}
 
 
                                _______TOISETHIVOI_______
{
    fast;
 
#ifndef ONLINE_JUDGE
    freopen(NAME ".inp", "r", stdin);
    freopen(NAME ".out", "w", stdout);
#endif
 
    // === SOLUTION GOES HERE ===
    int tc; cin>>tc;
    while(tc--)
    {
        solve();
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