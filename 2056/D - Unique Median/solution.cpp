/*
Author: duxp
"The king has returned, and the throne has been reclaimed.",
"The racer has returned, and the track is ready to be fired up again.",
"The coder has returned, and new problems are ready to be solved.",
Date: 2026-07-07 09:20:49
Problem name: D. Unique Median
Problem URL: https://codeforces.com/problemset/problem/2056/D
Idea: 
nếu dài lẻ thì luôn true
nChan = n/2
nLe = n - nChan
totalOdd = (nLe  * (nLe + 1)) / 2 + nChan*(nchan + 1) / 2;
 
xét từng giá trị từ 1 tới 10
gọi B[i] nếu ai > thì = 1, < = -1 không thì = 0
gọi P[i] là prefix sum của mảng B
taoj mang C[i] la so luong so = a[i] tu 1 -> i
xét đoạn độ dài chẵn, từ x tới y sẽ nhận i là median khi
|P[y] - P[x - 1]| <= |C[y] - C[x - 1]| - 1
tương đương với việc thỏa 2 bpt này cùng lúc:
- Py - Cy <= P[x - 1] - C[x - 1] - 1
- Py + Cy >= P[x - 1] + C[x - 1] + 1
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
constexpr int MOD = 1000000007, MOD2 = 998244353, MAXN = 200000, LOG = 20, BLOCK = 450;
constexpr int ALPHA = 26, BIT = 30;
const unsigned long long NEXT_PRIME[] = {0, 11ULL, 101ULL, 1009ULL, 10007ULL, 100003ULL, 1000003ULL, 10000019ULL, 100000007ULL, 1000000007ULL, 10000000019ULL};
 
template <class T, class U> inline bool minimize(T &x, const U &y) { return x > y ? (x = y, true) : false; }
template <class T, class U> inline bool maximize(T &x, const U &y) { return x < y ? (x = y, true) : false; }
 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a) {
        cin >> i;
    }
    long long ans = 0;
    for(int x = 1; x < 10; x++) 
    {
        vi b(n);
        for(int i = 0; i < n; i++) b[i] = (a[i] > x? 1 : -1);
        int sum = n;
        vi f(n);
        for(int i = 0; i < n; i++) 
        {
            f[i] = sum;
            sum += b[i];
        }
        vi cnt(2 * n + 1);
        sum = n;
        int j = 0;
        for(int i = 0; i < n; i++) 
        {
            if(a[i] == x) 
            {
                while(j <= i) 
                {
                    cnt[f[j]]++;
                    j++;
                }
            }
            sum += b[i];
            ans += cnt[sum];
        }
    }
    ans =  n * (n + 1) / 2 - ans;
    cout << ans << endl;
}
_______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    int tc;cin>>tc;
    while(tc--) solve();
 
    KILL();
}