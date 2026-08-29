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
#define endl '
'
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
int n, q, s;
int base1, base2;
int d[11 * MAXN + 5];
vector<pii> g[11 * MAXN + 5];
void addEdge(int u, int v, int w)
{
    g[u].pb({v, w});
}
void build1(int id, int l, int r)
{
    if(l == r)
    {
        addEdge(base1 + id, l, 0);
        return;
    }
    int mid = (l + r) / 2;
    build1(id * 2, l, mid);
    build1(id * 2 + 1, mid + 1, r);
    addEdge(base1 + id, base1 + id * 2, 0);
    addEdge(base1 + id, base1 + id * 2 + 1, 0);
}
void build2(int id, int l, int r)
{
    if(l == r)
    {
        addEdge(l, base2 + id, 0);
        return;
    }
    int mid = (l + r) / 2;
    build2(id * 2, l, mid);
    build2(id * 2 + 1, mid + 1, r);
    addEdge(base2 + id * 2, base2 + id, 0);
    addEdge(base2 + id * 2 + 1, base2 + id, 0);
}
void add1(int id, int l, int r, int ql, int qr, int v, int w)
{
    if(qr < l || r < ql) return;
 
    if(ql <= l && r <= qr)
    {
        addEdge(v, base1 + id, w);
        return;
    }
 
    int mid = (l + r) >> 1;
    add1(id * 2, l, mid, ql, qr, v, w);
    add1(id * 2 + 1, mid + 1, r, ql, qr, v, w);
}
void add2(int id, int l, int r, int ql, int qr, int v, int w)
{
    if(qr < l || r < ql) return;
 
    if(ql <= l && r <= qr)
    {
        addEdge(base2 + id, v, w);
        return;
    }
 
    int mid = (l + r) >> 1;
    add2(id * 2, l, mid, ql, qr, v, w);
    add2(id * 2 + 1, mid + 1, r, ql, qr, v, w);
}
void dijkstra(int s)
{
    fill(d, d + MAXN * 11 + 4, OO);
    priority_queue<pii> pq;
    d[s] = 0;
    pq.push({0,s});
    while(!pq.empty())
    {
        pii curr = pq.top(); pq.pop();
        int du = curr.fi, u = curr.se;
        du = -du;
        if(du > d[u]) continue;
        for(auto &ver : g[u])
        {
            int v = ver.fi, w = ver.se;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({-d[v], v});
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
    cin>>n>>q>>s;
    base1 = n; base2 = n + 4 * n;
    build1(1,1,n); build2(1,1,n);
    while(q--)
    {
        int t; cin>>t;
        if(t == 1)
        {
            int u,v,w; cin>>u>>v>>w;
            addEdge(u,v,w);
        }
        else if(t == 2)
        {
            int u,l,r,w; cin>>u>>l>>r>>w;
            add1(1,1,n,l,r,u,w);
        }
        else
        {
            int u,l,r,w; cin>>u>>l>>r>>w;
            add2(1,1,n,l,r,u,w);
        }
    }
    dijkstra(s);
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == OO) cout << -1 << " ";
        else cout << d[i] << " ";
    }
    log_resource();
    KILL();
}