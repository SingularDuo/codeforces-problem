/*
Author: duxp
"The king has returned, and the throne has been reclaimed.",
"The racer has returned, and the track is ready to be fired up again.",
"The coder has returned, and new problems are ready to be solved.",
Date: 2026-07-09 18:34:31
Problem name: F. Tree Factory
Problem URL: https://codeforces.com/contest/1225/problem/F?fbclid=IwY2xjawS8ZitleHRuA2FlbQIxMABicmlkETEzWGFhVXlWQ29YT2hndmt4c3J0YwZhcHBfaWQQMjIyMDM5MTc4ODIwMDg5MgABHrhXhcDDvaytRhWOIugHZK6QgBezLgx6C5oHLK9y2Tk7XSIUDNmDehC44SQN_aem_LBL8tH6PiiQAUA6hXD0YQQ
Idea: 
cho cây
thao tác: chọn đỉnh v sao cho v và par[v] không phải gốc, thêm cạnh nối v và ông nội v, xóa cạnh v và par[v]
tre là đồ thị đg thẳng
ban đầu chúng ta có cây tre N đỉnh, hỏi cần bao nhiêu thao tác để biến nó về cây đề bài
xét cây:
1 2
1 3
với 1 là gốc
muốn biến cây này về cây tre thì 
phải xóa cạnh nối 3 1 và thêm cạnh nối 2 3
vậy có thể đảo ngược thao tác của đề bài theo hướng này
nhưng khi xóa cạnh 1 3 thì làm sao biết được số 3 nên đc nối vào con trực tiếp nào của 2?
tutu, trước khi xóa cạnh 1 3 phải xử lí hết con của nó đã
gọi truy vấn đảo ngược là REV (REV(i) là xóa cạnh của i với par[i] và thêm cạnh i với 1 con trực tiếp j (j != i) của par[i])
khi REV xảy ra, node bị tác động sẽ nhảy lên 1 tầng của cây -> vì vậy luôn luôn có thể đưa các node con trong
1 cây con lên cùng tầng với cha nó , rồi gộp hết vào thành con của 1 con trực tiếp nào đó của gốc, tất nhiên sẽ chọn
con nào mà dùng chi phí rẻ nhất tối ưu dc nhiều cạnh nhất (tính trước khi bắt đầu ghép chung các con trực tiếp khác vào)
thử test mẫu NGON
SOL:
Thay vì cố tìm cây tre ban đầu để biến đổi, ta sẽ xây ngược lại cây tre từ cây đang có
gọi REV(u) là chọn đỉnh v sao cho v là anh em của u, cắt cạnh (u, par[u]) và thêm u (nguyên cây con) mthanhf dưới đáy của v
dưới dạng đường thẳng
lưu ý: cây con của v phải được xử lí thành cây tre hoàn toàn trước khi gộp
tại sao chọn size bị ngu
=> khi ta nhấc cả cây con gốc j nôpis xuống dưới i, đỉnh j sẽ thực hiện các bước nhảy để leo xuống, số lượng thao tác 
rev sẽ là  maxdepth của i chjuws klhoong liên quan đến size i, cấc node nằm ngoài trục của i được gom gọnk nên không làm 
tăng chiều cao đường thẳng 
vậy số thao tác chính xác là maxdepth chứ ko phjair size
giả sử nút u có các con trực tiếp v1 v2 v3 vk, khi ta duyệt qua để gộp thành 1 đg thẳng duy nhất dưới u
xét v1, đượkc duỗi phẳng trước => chi phí gộp = 0;
khi xét đứa con 2, duỗi thẳng xong thì thành cây tre có độ dài maxdepth[v2], gộp vào v1 thì sẽ tốn đúng maxdepth[v1]
nchung la xet theo depth thay vi size
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
int par[MAXN + 5];
vi g[MAXN + 5];
int height[MAXN + 5], beo[MAXN + 5];
vi otherChild[MAXN + 5], revOps, bamboo;
void dfs(int u)
{
    int maxH = -1;
    beo[u] = -1;
    for(int v : g[u])
    {
        dfs(v);
        if(height[v] > maxH)
        {
            maxH = height[v];
            beo[u] = v;
        }
    }
    height[u] = maxH + 1;
}
_______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    cin>>n;
    par[0] = -1;
    for(int i = 1; i <= n - 1; i++)
    {
        cin>>par[i];
        g[par[i]].pb(i);
    }
    dfs(0);
    for(int i = 0; i < n; i++)
    {
        for(int v : g[i])
        {
            if(v != beo[i]) otherChild[i].pb(v);
        }
    }
    int u = 0;
    while(beo[u] != -1) u = beo[u];
    while(true)
    {
        int p = par[u];
        if(p == -1) break;
        if(!otherChild[p].empty())
        {
            int w = otherChild[p].back();
            otherChild[p].pop_back();
            revOps.pb(u);
            par[u] = w;
            beo[p] = w;
            if(beo[w] != -1) otherChild[w].pb(beo[w]);
            beo[w] = u;
        }
        else u = p;
    }
    int curr = 0;
    while(curr != -1)
    {
        bamboo.pb(curr);
        curr = beo[curr];
    }
    for(int i = 0; i < n; i++) cout<<bamboo[i]<<" ";
    cout<<endl;
    reverse(nall(revOps));
    cout<<revOps.size()<<endl;
    if(revOps.size() != 0)
    {
        for(int i : revOps) cout<<i<<" ";
    }
    KILL();
}