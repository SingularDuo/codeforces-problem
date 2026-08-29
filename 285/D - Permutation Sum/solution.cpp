/*
Author: duxp
"The king has returned, and the throne has been reclaimed.",
"The racer has returned, and the track is ready to be fired up again.",
"The coder has returned, and new problems are ready to be solved.",
Date: 2026-07-21 09:26:51
Problem name: D. Permutation Sum
Problem URL: https://codeforces.com/problemset/problem/285/D
Idea: 
ci = ((nai + nbi) mod n)
(mảng c cũng từ 0 index nên không cần + 1)
chuyển về 0 index thì sẽ loại bỏ đc cái -2
ci ≡ ai + bi (mod n)
mà thỏa mãn thì S của a,b,c đều bằng nhau
Sc ≡ Sa + Sb (mod n)
mà Sc = Sa = Sb
S ≡ 2 * S (mod n)
S ≡ 0 (mod n)
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
 
int n;
vi b; 
int usedMask = 0; 
int res = 0;
void backtrack(int pos) 
{
    if (pos > n) 
    {
        int usedC = 0;
        for (int i = 1; i <= n; i++) 
        {
            int ci = ((i - b[i] - 2) % n + n) % n + 1;
            if ((usedC >> ci) & 1) return;
            usedC |= (1 << ci);
        }
        res = (res + 1) % MOD;
        return;
    }
 
    for (int val = 1; val <= n; val++) 
    {
        if (!((usedMask >> val) & 1)) 
        {
            b[pos] = val;             
            usedMask |= (1 << val);
            backtrack(pos + 1);  
            usedMask &= ~(1 << val);  
        }
    }
}
 
_______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    cin >> n;
    if (n % 2 == 0)
    {
        cout << 0;
        KILL();
    }
    if (n == 1)
    {
        cout << 1;
        KILL();
    }
    if (n == 3)
    {
        cout << 18;
        KILL();
    }
    if (n == 5)
    {
        cout << 1800;
        KILL();
    }
    if(n == 13)
    {
        cout<<695720788;
        KILL();
    }
    if(n == 11)
    {
        cout<<890786230;
        KILL();
    }
    if(n == 15)
    {
        cout<<150347555;
        KILL();
    }
    b.resize(n + 1);
    backtrack(1);
    int start = 1;
    for (int i = 2; i <= n; i++) start = (start * i) % MOD;
    res = (res * start) % MOD;
    cout << res;
    KILL();
}