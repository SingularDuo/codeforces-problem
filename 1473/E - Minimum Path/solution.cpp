/*
Author: duxp
"IT WORKED ON MY MACHINE!"
"My code is correct, the judge is just having a bad day."
"My code is perfect, that must be compiler's fault"
*/
#include <bits/stdc++.h>
 
#ifndef ONLINE_JUDGE
    #ifdef __APPLE__
        #include <mach/mach.h>
    #endif
#endif
 
using namespace std;
 
#define ll long long
#define int ll 
#define pb push_back
#define all(x) x.begin() + 1, x.end()
#define nall(x) x.begin(), x.end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define vpii vector<pii>
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, x) memset(a, x, sizeof(a))
 
#define _______TOISECOGIAIVOI_______ signed main()
#define KILL() exit(0)
#define NAME "duxp"
#ifndef ONLINE_JUDGE
    #define debug(x) cerr<<#x<<" : "<<x<<endl;
    #define debug2(x,y) cerr<<#x<<" : "<<x<<endl<<#y<<" : "<<y<<endl;
 
    void force_memory_allocation() {
        #ifdef __APPLE__
            vm_address_t addr = 0;
            vm_size_t size = 0;
            vm_region_basic_info_data_64_t info;
            mach_msg_type_number_t count = VM_REGION_BASIC_INFO_COUNT_64;
            mach_port_t object;
            while (vm_region_64(mach_task_self(), &addr, &size, VM_REGION_BASIC_INFO_64, 
                               (vm_region_info_t)&info, &count, &object) == KERN_SUCCESS) {
                if (info.protection & VM_PROT_WRITE) {
                    volatile char *p = (char *)addr;
                    for (vm_size_t i = 0; i < size; i += 4096) p[i] = p[i];
                }
                addr += size;
            }
        #endif
    }
 
    void log_resource() {
        struct rusage usage;
        if (getrusage(RUSAGE_SELF, &usage) == 0) {
            cerr << fixed << setprecision(3) << "
========== DEBUG ==========
";
            cerr << "Time: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms
";
            double mem_mb = usage.ru_maxrss;
            #ifdef __APPLE__
                mem_mb /= (1024.0 * 1024.0);
                mem_mb -= 158.0; 
                if (mem_mb < 0) mem_mb = 0; 
            #else
                mem_mb /= 1024.0;
            #endif
            cerr << "Memory (User): " << mem_mb << " MB
";
            cerr << "===========================
";
        }
    }
#else
    #define debug(x)
    #define debug2(x,y)
    void force_memory_allocation() {}
    void log_resource() {}
#endif
 
template <typename T>
inline int getbit(T x, int k) { return (x >> k) & 1; }
template <typename T>
inline T onbit(T x, int k) { return x | (T(1) << k); }
template <typename T>
inline T offbit(T x, int k) { return x & ~(T(1) << k); }
 
const ll OO = 1e18;
const int oo = 1e9;
const int MOD = 1000000007;
const int MAXN = 200000;
int n, m; 
vpii g[MAXN + 5];
int d[MAXN + 5][2][2];
struct State 
{
    int u, i, j, dist;
    bool operator>(const State& other) const 
    {
        return dist > other.dist;
    }
};
 
void dijkstra(int s)
{
    priority_queue<State, vector<State>, greater<State>> pq;
    d[s][0][0] = 0;
    pq.push({s, 0, 0, 0});
 
    while(!pq.empty()) 
    {
        State top = pq.top(); pq.pop();
        int u = top.u, i = top.i, j = top.j, dist = top.dist;
        if (dist > d[u][i][j]) continue;
        for (auto &edge : g[u]) {
            int v = edge.fi;
            int w = edge.se;
            if (d[v][i][j] > dist + w) 
            {
                d[v][i][j] = dist + w;
                pq.push({v, i, j, d[v][i][j]});
            }
            if (i == 0 && d[v][1][j] > dist) 
            {
                d[v][1][j] = dist;
                pq.push({v, 1, j, d[v][1][j]});
            }
            if (j == 0 && d[v][i][1] > dist + 2 * w) 
            {
                d[v][i][1] = dist + 2 * w;
                pq.push({v, i, 1, d[v][i][1]});
            }
            if (i == 0 && j == 0 && d[v][1][1] > dist + w)
            {
                d[v][1][1] = dist + w;
                pq.push({v, 1, 1, d[v][1][1]});
            }
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
    force_memory_allocation();
    cin>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
 
    for(int i = 1; i <= n; i++) d[i][0][1] = d[i][1][0] = d[i][1][1] = d[i][0][0] = OO;
    dijkstra(1);
    for (int i = 2; i <= n; i++) cout << d[i][1][1] << " ";
    cout << endl;
    log_resource();
    return 0;
}