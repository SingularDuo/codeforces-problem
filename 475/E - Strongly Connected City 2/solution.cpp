/*
 ___ _ __  __    ____ ___  __  __ ___ _   _  ____ 
|_ _( )  \/  |  / ___/ _ \|  \/  |_ _| \ | |/ ___|
 | ||/| |\/| | | |  | | | | |\/| || ||  \| | |  _ 
 | |  | |  | | | |__| |_| | |  | || || |\  | |_| |
|___| |_|_ |_|  \____\___/|_|__|_|___|_|_\_|\____|
        | | | |/ ___|  \/  |_   _/ ___|_   _|     
        | |_| | |   | |\/| | | | \___ \ | |       
        |  _  | |___| |  | | | |  ___) || |       
        |_| |_|\____|_|  |_| |_| |____/ |_|       
---------------Frieren lover fr-------------------
Author: duxp
Note: 
dp[u][v][0/1]
là số lượng cặp nhiều nhất trong cây con gốc u khi đang nối với v và cạnh u v có trạng thái
0: u -> v
1: u <- v2
với tplt mạnh có kích thước X, thì số cặp nó tạo dc (tính riêng scc đó) là X * (X -1) / 2
nén thành các tplt mạnh? chưa biết hướng ? cycle ?
Xét các cạnh cầu
giả sử u - v là cạnh cầu, thì hỏi xem trong u có tối đa bao nhiêu đỉnh tới dc u sau khi định hướng
tương tự với v là mảng best
xây trong u và v luôn là từ u (ko qua cạnh u, v) thì có thể tới dc tối đa bao nhiêu cạnh sau định hướng
gọi là bestTo
max(best[u] * bestTo[v], best[v] * bestTo[u])
có thể gom thành các siêu đỉnh rồi xử lí trên cây mới
lúc này dp trên cây mới
dp reroot? vì ở dưới và ở trên sẽ mâu thuẫn lẫn nhau
 
hint editorial:
Tồn tại một đỉnh gốc đặc biệt s trong cây cầu sao cho: 
với mỗi cây con trực tiếp của s, toàn bộ các cạnh bên trong cây con đó 
(không chỉ cạnh nối với s) phải cùng hướng — hoặc tất cả hội tụ về phía s 
("in-tree"), hoặc tất cả tỏa ra xa s ("out-tree"). 
Lý do: nếu trong 1 cây con có "xung đột" hướng, 
đảo ngược nó không bao giờ làm giảm đáp án. Và đóng góp nội bộ của 1 cây con là 
như nhau dù nó hội tụ hay tỏa ra (chỉ đổi chiều cặp, không đổi số lượng cặp).
Vì sao đóng góp nội bộ (internal) không đổi dù cây con "hội tụ vào" hay "tỏa ra"?
 
Đây là phần dễ chứng minh chặt chẽ. 
Giả sử cây con T có 1 cách định hướng bất kỳ, sinh ra tập cặp reachable S. 
Nếu ta đảo chiều toàn bộ cạnh trong T, thì với mọi (x,y) ∈ S, 
bây giờ (y,x) sẽ reachable thay vì (x,y). Đây là một song ánh (bijection) giữa tập 
cặp cũ và tập cặp mới — chỉ đổi chiều của từng cặp, không đổi số lượng cặp. 
Vậy |S| (cái ta cần tối đa hoá) không đổi khi đảo hướng toàn bộ. 
→ chọn "in-tree" hay "out-tree" cho cả cây con không ảnh hưởng đóng góp nội bộ, 
chỉ ảnh hưởng cách nó tương tác với phần còn lại của cây (qua điểm nối).
2) Vì sao nên "dồn" việc chia nhánh (split) vào đúng 1 điểm gốc s, 
thay vì chia rải rác ở nhiều đỉnh?
Đây là phần trực giác, dựa trên bất đẳng thức lồi quen thuộc:
a·b ≤ ((a+b)/2)²
tức là: tách một "khối" tổng (a+b) ra làm 2 phần rồi nhân, 
giá trị lớn nhất đạt được khi tách ngay tại khối lớn đó (a≈b). 
Nếu bạn "phân tán" khả năng tách đôi ra nhiều điểm nhỏ rải rác trong cây, 
mỗi điểm chỉ tách được 1 phần khối lượng nhỏ, tổng các tích cục bộ đó luôn 
≤ tích khi dồn hết khối lượng đó tách tại 1 điểm duy nhất. 
Đây chính là lý do trực quan vì sao "1 hub, chia đôi tất cả cây con của nó" tốt hơn
 "nhiều hub nhỏ mỗi đỉnh tách 1 ít".
 
 
 
"Use long long wherever you can."
"Add +5 to every array size."
"Legends got AC, survivor got the subtasks."
"May the Subtasks be ever in your favor."
"Do on your own."
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
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = b; i >= a; i--)
#define EACH(i, a) for(auto &i : a)
#define YESNO(x) cout << ((x) ? "YES" : "NO")
#define KILL() exit(0)
#define NAME "duxp"
#define _______TOISECOGIAIVOI_______ signed main()
using vi = vector<int>; using pii = pair<int, int>; using vpii = vector<pii>;
template<typename T, typename = void> struct is_it : std::false_type {}; template<typename T> struct is_it<T, typename std::conditional<true, void, decltype(std::begin(std::declval<T>()))>::type> : std::true_type {};
void _db(long long x) { std::cerr << x; } void _db(double x) { std::cerr << x; } void _db(char x) { std::cerr << '\'' << x << '\''; } void _db(const std::string &x) { std::cerr << '"' << x << '"'; } void _db(bool x) { std::cerr << (x ? "true" : "false"); } template<typename A, typename B> void _db(const std::pair<A, B> &p) { std::cerr << "("; _db(p.first); std::cerr << ", "; _db(p.second); std::cerr << ")"; } template<typename T, typename std::enable_if<is_it<T>::value && !std::is_same<T, std::string>::value, int>::type = 0> void _db(const T &v) { std::cerr << "["; bool f = 1; for (const auto &x : v) { if (!f) std::cerr << ", "; _db(x); f = 0; } std::cerr << "]"; }
void _pr() { std::cerr << "
"; } template <typename T, typename... V> void _pr(T t, V... v) { _db(t); if (sizeof...(v)) std::cerr << ", "; _pr(v...); } 
#ifdef LOCAL
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
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
int Rand(int L, int R) 
{
    assert(L <= R);
    return uniform_int_distribution<int>(L, R)(rd);
}
int n, m;
vpii g[MAXN + 5];
vi tree[MAXN + 5];
int low[MAXN + 5], num[MAXN + 5], timer = 0;
int best[MAXN + 5], bestTo[MAXN + 5];
int compCnt = 0;
int comp[MAXN + 5], compSz[MAXN + 5];
int down[MAXN + 5], up[MAXN + 5];
int sz[MAXN + 5];       
int ancestorSum;     
bool isBridge[MAXN + 5];
bool reach[MAXN + 5];
 
void dfsBridge(int u, int p_edge = -1)
{
    num[u] = low[u] = ++timer;
 
    for (auto &edge : g[u])
    {
        int v = edge.fi, eid = edge.se;
        if (eid == p_edge) continue;
        if (num[v]) minimize(low[u], num[v]);
        else
        {
            dfsBridge(v, eid);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) isBridge[eid] = true;
        }
    }
}
 
void dfsComp(int u, int p_id)
{
    comp[u] = compCnt;
    compSz[compCnt]++;
    for (auto &edge : g[u])
    {
        int v = edge.fi, eid = edge.se;
        if (isBridge[eid] || comp[v] || v == p_id) continue;
        dfsComp(v, eid);
    }
}
 
void dfsBest(int u, int p)
{
    best[u] = compSz[u];
    for (int v : tree[u])
    {
        if (v == p) continue;
        dfsBest(v, u);
        best[u] += best[v];
    }
}
 
void dfsBestTo(int u, int p)
{
    if (p == 0)
        bestTo[u] = compSz[u];
    else
        bestTo[u] = bestTo[p] + compSz[u];
 
    for (int v : tree[u])
    {
        if (v == p)
            continue;
 
        dfsBestTo(v, u);
    }
}
 
 
void dfsSz(int u, int p)
{
    sz[u] = compSz[u];
    for (int v : tree[u])
    {
        if (v == p) continue;
        dfsSz(v, u);
        sz[u] += sz[v];
    }
    ancestorSum += (ll)compSz[u] * (sz[u] - compSz[u]);
}
 
_______TOISECOGIAIVOI_______
{
    fast;
 
    #ifdef LOCAL
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    #else
        // freopen(NAME ".inp", "r", stdin);
        // freopen(NAME ".out", "w", stdout);
    #endif
 
    cin >> n >> m;
 
    vpii eds;
 
    eds.pb({0, 0});
 
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
 
        g[u].pb({v, i});
        g[v].pb({u, i});
 
        eds.pb({u, v});
    }
 
    FOR(i, 1, n)
    {
        if (!num[i])
            dfsBridge(i);
    }
 
    FOR(i, 1, n)
    {
        if (!comp[i])
        {
            compCnt++;
            dfsComp(i, 0);
        }
    }
 
    FOR(i, 1, m)
    {
        if (isBridge[i])
        {
            int u = comp[eds[i].fi];
            int v = comp[eds[i].se];
            tree[u].pb(v);
            tree[v].pb(u);
        }
    }  
    // FOR(i, 1, n) EACH(j, tree[i]) cout<<i<<" "<<j<<endl;
    int base = n;
    FOR(i, 1, compCnt) base += compSz[i] * (compSz[i] - 1);
    int res = 0;
    FOR(s, 1, compCnt)
    {
        ancestorSum = 0;
        dfsSz(s, 0);
        int rest = n - compSz[s];
        FOR(i, 0, rest) reach[i] = false;
        reach[0] = true; 
 
        EACH(c, tree[s])
        {
            int w = sz[c]; 
            FORD(x, w, rest) if (reach[x - w]) reach[x] = true;
        }
        FOR(i, 0, rest)if (reach[i]) maximize(res, base + ancestorSum + i * (rest - i));
    }
    cout<<res;
    KILL();
}