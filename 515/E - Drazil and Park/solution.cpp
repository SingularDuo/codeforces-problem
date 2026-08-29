/*
Author: duxp
"The king has returned, and the throne has been reclaimed.",
"The racer has returned, and the track is ready to be fired up again.",
"The coder has returned, and new problems are ready to be solved.",
Date: 2026-07-05 22:24:14
Problem name: C. Drazil and Park
Problem URL: https://codeforces.com/problemset/problem/516/C
Idea: 
nhân đôi mảng xử lí hình tròn
hai th index:
a <= b ezgg
a >= b thì phải giữ nguyên index gốc của a, index của b cần xét trên mảng double là orgBid + n
phải tối ưu lại dist(x, y)
gọi f[i] là prefix sum 1 -> i (prefix d)
L R là vùng an toàn
giả sử case bị chặn a <= b 
-> lúc này bị chặn trên mảng gốc
L = y + 1, R = x + n + 1
case bị chặn a > b
L = y + 1, R = a - 1
vậy bây giờ chúng ta chỉ cần xét các cặp (x,y) (x < y) nằm trong đoạn [L,R] thôi
=> thay vào công thức
E = 2(hx + hy) + dist(x, y) = 2hx + 2hy + (f[y] - f[x]) (tại sao không phải f[x - 1]? -> khe)
E = (2hy + f[y]) + (2hx - f[x])
để maximize tổng này thì hai bên lớn nhất có thể
=> 2 cây seg max (xử lí tránh trùng nhau)
=> thay vì xây 2 cây seg độc lập, ta sẽ xây 1 cây seg có nút quản lí mx1, mx2, mxE
Tag used: Math (transform), segment tree
dm OO sat qua - phat am me luon
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
constexpr long long OO = 0x7FFFFFFFFFFFFFFLL;
constexpr int oo = 0x7FFFFFFF, INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 1000000007, MOD2 = 998244353, MAXN = 200000, LOG = 20, BLOCK = 450;
constexpr int ALPHA = 26, BIT = 30;
const unsigned long long NEXT_PRIME[] = {0, 11ULL, 101ULL, 1009ULL, 10007ULL, 100003ULL, 1000003ULL, 10000019ULL, 100000007ULL, 1000000007ULL, 10000000019ULL};
 
template <class T, class U> inline bool minimize(T &x, const U &y) { return x > y ? (x = y, true) : false; }
template <class T, class U> inline bool maximize(T &x, const U &y) { return x < y ? (x = y, true) : false; }
struct Node 
{
    int mx1, mx2, mxE;
}st[8 * MAXN + 5];
int n, m;
int d[2 * MAXN + 5], h[2 * MAXN + 5], f[2 * MAXN + 5];
Node mergeNode(Node left, Node right) 
{
    Node res;
    res.mx1 = max(left.mx1, right.mx1); 
    res.mx2 = max(left.mx2, right.mx2); 
    res.mxE = max({left.mxE, right.mxE, left.mx2 + right.mx1});
    return res;
}
void merge(int id) {st[id] = mergeNode(st[id * 2], st[id * 2 + 1]);}
void build(int id, int l, int r)
{
    if(l == r)
    {
        st[id] = {2 * h[l] + f[l], 2 * h[l] - f[l], -OO};
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid); build(id * 2 + 1, mid + 1, r);
    merge(id);
}
Node get(int id, int l, int r, int u, int v) 
{
    if(l > v || r < u) return {-OO, -OO, -OO};
    if(l >= u && r <= v) return st[id];
    int mid = (l + r) / 2;
    Node left = get(id * 2, l, mid, u, v);
    Node right = get(id * 2 + 1, mid + 1, r, u, v);
    return mergeNode(left, right);
}
 
_______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        cin>>d[i];
        d[n + i] = d[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin>>h[i];
        h[n + i] = h[i];
    }
    f[1] = 0;
    for(int i = 2; i <= 2 * n; i++) f[i] = f[i - 1] + d[i - 1];
    build(1,1,2 * n);
    while(m--) 
    {
        int l, r; cin >> l >> r;
        int L, R;
        if(l <= r) 
        {
            L = r + 1;
            R = l + n - 1;
        } 
        else 
        {
            L = r + 1;
            R = l - 1;
        }
        Node ans = get(1, 1, 2 * n, L, R);
        cout << ans.mxE << endl;
    }
    KILL();
}