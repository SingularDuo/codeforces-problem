/*
========================================================
   Author  : duxp
   Purpose : Competitive Programming
   Note    : Think first. Code once.
   Rule    : Once AC, never touch
   Created at: 2026-01-22 13:32
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
    return -1;
#endif
}
 
static inline void dbg_memory()
{
    if (!__LOCAL__)
        return;
    long long mem = get_memory_mb();
    cerr << "RAM: " << mem << " MB
";
}
 
#define _______TOISETHIVOI_______ signed main()
#define KILL() exit(0)
#define NAME "duxp"
 
const ll OO = 1e18;
const int oo = 1e9;
const int MOD1 = 1000000007;
const int MOD9 = 998244353;
const int MAXN = 500000;
 
static int cnt[MAXN + 5];
static int a[MAXN + 5];
static int seg[4 * MAXN + 5];
 
void update(int id, int l, int r, int pos, int val)
{
    if (l == r)
    {
        seg[id] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        update(id << 1, l, mid, pos, val);
    else
        update(id << 1 | 1, mid + 1, r, pos, val);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
 
int query(int id, int l, int r, int ql, int qr)
{
    if (ql > r || qr < l)
        return 0;
    if (ql <= l && r <= qr)
        return seg[id];
    int mid = (l + r) >> 1;
    return query(id << 1, l, mid, ql, qr) +
           query(id << 1 | 1, mid + 1, r, ql, qr);
}
 
int find_kth(int id, int l, int r, int k)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    if (seg[id << 1] >= k)
        return find_kth(id << 1, l, mid, k);
    return find_kth(id << 1 | 1, mid + 1, r, k - seg[id << 1]);
}
 
_______TOISETHIVOI_______
{
    fast;
 
#ifndef ONLINE_JUDGE
    freopen(NAME ".inp", "r", stdin);
    freopen(NAME ".out", "w", stdout);
#endif
 
    int n, m, q;
    cin >> n >> m >> q;
 
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
 
    int mx = 0;
    for (int i = 1; i <= m; i++)
        mx = max(mx, cnt[i]);
 
    ll sumDiff = 0;
    for (int i = 1; i <= m; i++)
        sumDiff += (mx - cnt[i]);
    ll T = n + sumDiff;
 
    vector<pll> qs(q + 1);
    vector<int> ans(q + 1);
    for (int i = 1; i <= q; i++)
    {
        cin >> qs[i].fi;
        qs[i].se = i;
    }
    sort(qs.begin() + 1, qs.end());
 
    vector<vector<int>> byCnt(mx + 1);
    for (int i = 1; i <= m; i++)
        byCnt[cnt[i]].pb(i);
 
    ll S = n;
    int ptr = 1;
 
    for (int c = 0; c < mx && ptr <= q; c++)
    {
        for (int x : byCnt[c])
            update(1, 1, m, x, 1);
 
        int rowSize = seg[1];
        if (rowSize == 0)
            continue;
 
        while (ptr <= q && qs[ptr].fi <= S + rowSize)
        {
            ll k = qs[ptr].fi - S;
            ans[qs[ptr].se] = find_kth(1, 1, m, (int)k);
            ptr++;
        }
        S += rowSize;
    }
 
    for (int i = ptr; i <= q; i++)
    {
        ll k = qs[i].fi;
        ll pos = (k - T - 1) % m;
        ans[qs[i].se] = pos + 1;
    }
 
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '
';
 
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