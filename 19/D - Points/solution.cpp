/*
Author: duxp
"The king has returned, and the throne has been reclaimed.",
"The racer has returned, and the track is ready to be fired up again.",
"The coder has returned, and new problems are ready to be solved.",
Date: 2026-07-09 21:40:43
Problem name: D. Points
Problem URL: https://codeforces.com/problemset/problem/19/D
Idea: 
Tag used: 
Summary: 
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
#define YESNO(x) cout << ((x) ? "YES" : "NO")
#define KILL() exit(0)
#define NAME "duxp"
#define _______TOISECOGIAIVOI_______ signed main()
using vi = vector<int>; using pii = pair<int, int>; using vpii = vector<pii>;
template<typename T, typename = void> struct is_it : std::false_type {}; template<typename T> struct is_it<T, typename std::conditional<true, void, decltype(std::begin(std::declval<T>()))>::type> : std::true_type {};
void _db(long long x) { std::cerr << x; } void _db(double x) { std::cerr << x; } void _db(char x) { std::cerr << '\'' << x << '\''; } void _db(const std::string &x) { std::cerr << '"' << x << '"'; } void _db(bool x) { std::cerr << (x ? "true" : "false"); } template<typename A, typename B> void _db(const std::pair<A, B> &p) { std::cerr << "("; _db(p.first); std::cerr << ", "; _db(p.second); std::cerr << ")"; } template<typename T, typename std::enable_if<is_it<T>::value && !std::is_same<T, std::string>::value, int>::type = 0> void _db(const T &v) { std::cerr << "["; bool f = 1; for (const auto &x : v) { if (!f) std::cerr << ", "; _db(x); f = 0; } std::cerr << "]"; }
void _pr() { std::cerr << "
"; } template <typename T, typename... V> void _pr(T t, V... v) { _db(t); if (sizeof...(v)) std::cerr << ", "; _pr(v...); } 
#ifndef ONLINE_JUDGE
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
constexpr int MOD = 1000000007, MOD2 = 998244353, MAXN = 400000, LOG = 20, BLOCK = 450;
constexpr int ALPHA = 26, BIT = 30;
const unsigned long long NEXT_PRIME[] = {0, 11ULL, 101ULL, 1009ULL, 10007ULL, 100003ULL, 1000003ULL, 10000019ULL, 100000007ULL, 1000000007ULL, 10000000019ULL};
 
template <class T, class U> inline bool minimize(T &x, const U &y) { return x > y ? (x = y, true) : false; }
template <class T, class U> inline bool maximize(T &x, const U &y) { return x < y ? (x = y, true) : false; }
struct Query
{
    string type;
    int x, y;
}qs[MAXN + 5];
bool cmp(Query a, Query b)
{
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}
int n;
vi coord;
set<int> column[MAXN + 5];
int st[4 * 2 * MAXN + 5];
pii getID(int x, int y)
{
    x = lower_bound(nall(coord), x) - coord.begin();
    y = lower_bound(nall(coord), y) - coord.begin();
    return {x,y};
}
void update(int id, int l, int r, int pos)
{
    if(l == r)
    {
        if (column[l].empty()) st[id] = -1;
        else st[id] = *column[l].rbegin();
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(id * 2, l, mid, pos);
    else update(id * 2 + 1, mid + 1, r, pos);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v, int val)
{
    if (l > v || r < u || st[id] <= val) return -1;
    if (l == r) return l;
    int mid = (l + r) / 2;
    int res = get(id * 2, l, mid, u, v, val);
    if (res != -1) return res;
    return get(id * 2 + 1, mid + 1, r, u, v, val);
}
_______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> qs[i].type >> qs[i].x >> qs[i].y;
        coord.pb(qs[i].x); coord.pb(qs[i].y);
    }
    sort(nall(coord));
    coord.erase(unique(nall(coord)), coord.end());
    int sz = coord.size();
    
    for(int i = 1; i <= n; i++)
    {
        qs[i].x = lower_bound(nall(coord), qs[i].x) - coord.begin();
        qs[i].y = lower_bound(nall(coord), qs[i].y) - coord.begin();
    }
    memset(st, -1, sizeof(st));
    for(int i = 1; i <= n; i++)
    {
        string type = qs[i].type;
        int x = qs[i].x, y = qs[i].y;
        if(type == "add")
        {
            column[x].insert(y);
            update(1, 0, sz - 1, x);
        }
        else if(type == "remove")
        {
            column[x].erase(y);
            update(1, 0, sz - 1, x);
        }
        else 
        {
            int res = get(1, 0, sz - 1, x + 1, sz - 1, y);
            if (res == -1) cout << -1 << endl;
            else 
            {
                auto it = column[res].upper_bound(y);
                int ans_y = *it;
                cout << coord[res] << " " << coord[ans_y] << endl;
            }
        }
    }
    KILL();
}