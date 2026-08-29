/*
========================================================
   Author  : duxp
   Purpose : Competitive Programming
   Note    : Think first. Code once.
   Rule    : Once AC, never touch
   Created at: 2026-01-20 23:29
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
#define int long long
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
const int MAXN = 100000;
int n, m, q;
int a[MAXN + 5], b[MAXN + 5];
ll st[4 * MAXN + 5];
ll lazy[4 * MAXN + 5];
ll sumEven[MAXN + 5], sumOdd[MAXN + 5];
 
void push(int id, int l, int r)
{
    if(lazy[id] == 0) return;
    int mid = (l + r) >> 1;
 
    int lenL = mid - l + 1;
    ll oddL = (lenL + (l & 1)) / 2;
    ll evenL = lenL - oddL;
    st[id << 1] += lazy[id] * (oddL - evenL);
    lazy[id << 1] += lazy[id];
 
    int lenR = r - mid;
    ll oddR = (lenR + ((mid + 1) & 1)) / 2;
    ll evenR = lenR - oddR;
    st[id << 1 | 1] += lazy[id] * (oddR - evenR);
    lazy[id << 1 | 1] += lazy[id];
 
    lazy[id] = 0;
}
 
void build(int id, int l, int r)
{
    if(l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = st[id << 1] + st[id << 1 | 1];
}
 
void update(int id, int l, int r, int u, int v, ll val)
{
    if(v < l || r < u) return;
    if(u <= l && r <= v)
    {
        int len = r - l + 1;
        ll odd = (len + (l & 1)) / 2;
        ll even = len - odd;
        st[id] += val * (odd - even);
        lazy[id] += val;
        return;
    }
    push(id, l, r);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    st[id] = st[id << 1] + st[id << 1 | 1];
}
 
ll get(int id, int l, int r, int u, int v)
{
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    push(id, l, r);
    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}
ll calc(const vector<ll> &sumB, ll sumA)
{
    int l = 0, r = (int)sumB.size() - 1;
    ll res = OO;
 
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        res = min(res, llabs(sumA - sumB[mid]));
        if(sumB[mid] < sumA) l = mid + 1;
        else r = mid - 1;
    }
    return res;
}
 
 
                                    _______TOISETHIVOI_______
{
    fast;
 
#ifndef ONLINE_JUDGE
    freopen(NAME ".inp", "r", stdin);
    freopen(NAME ".out", "w", stdout);
#endif
 
    // === SOLUTION GOES HERE ===
    cin >> n >> m >> q;
 
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i % 2 == 0) a[i] = -a[i];
    }
 
    for(int i = 1; i <= m; i++) cin >> b[i];
 
    for(int i = m; i >= 1; i--)
    {
        sumOdd[i] = sumOdd[i + 1];
        sumEven[i] = sumEven[i + 1];
        if(i & 1) sumOdd[i] += b[i];
        else sumEven[i] += b[i];
    }
 
    vector<ll> sumB;
    for(int j = 0; j <= m - n; j++)
    {
        int start = j + 1;
        int end = start + n - 1;
 
        ll valP, valS;
        if(start & 1)
        {
            valP = sumOdd[start] - sumOdd[end + 1];
            valS = sumEven[start] - sumEven[end + 1];
        }
        else
        {
            valP = sumEven[start] - sumEven[end + 1];
            valS = sumOdd[start] - sumOdd[end + 1];
        }
        sumB.pb(valP - valS);
    }
 
    sort(sumB.begin(), sumB.end());
 
    build(1, 1, n);
 
    ll sumA = get(1, 1, n, 1, n);
    cout << calc(sumB, sumA) << endl;
 
    while(q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        update(1, 1, n, l, r, x);
        sumA = get(1, 1, n, 1, n);
        cout << calc(sumB, sumA) << endl;
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