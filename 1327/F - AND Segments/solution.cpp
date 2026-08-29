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
const int MOD = 998244353;
const int MAXN = 500000;
struct force
{
    int l,r,x;
};
vector<force> qs;
int n, k, m;
int bitCons[32][MAXN + 5], diffbitCons[32][MAXN + 5];
                                _______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    force_memory_allocation();
    cin>>n>>k>>m;
    for(int i = 1; i <= m; i++)
    {
        int l,r,x; cin>>l>>r>>x;
        qs.pb({l,r,x});
        for(int j = 0; j < k; j++)
        {
            int get = getbit(x, j);
            if(get == 1)
            {
                diffbitCons[j][l] += 1;
                diffbitCons[j][r + 1] -= 1;
            }
        }
    }
    for(int i = 0; i < k; i++)
    {
        int delta = 0;
        for(int j = 1; j <= n; j++)
        {
            delta += diffbitCons[i][j];
            bitCons[i][j] = delta;
            if(bitCons[i][j] > 1) bitCons[i][j] = 1;
        }
    }
    ll res = 1;
 
    for (int j = 0; j < k; j++) 
    {
        // dp[i] là số cách xét đến vị trí i, và tại i ĐẶT SỐ 0
        vector<ll> dp(n + 2, 0), L(n + 2, 0), f(n + 2, 0);
        dp[0] = 1;
        for (auto &q : qs) 
        {
            if (getbit(q.x, j) == 0) 
            {
                L[q.r] = max(L[q.r], 1LL * q.l);
            }
        }
        for (int i = 1; i <= n; i++) L[i] = max(L[i], L[i-1]);
        dp[0] = f[0] = 1;
        for (int i = 1; i <= n + 1; i++) 
        {
            if (i <= n && bitCons[j][i] > 0) dp[i] = 0;
            else 
            {
                int left;
                if(i > n) left = L[n];
                else left = L[i - 1];
                ll currS = f[i-1];
                if (left > 0) currS = (currS - f[left-1] + MOD) % MOD;
                dp[i] += currS;
            }
            f[i] = (f[i-1] + dp[i]) % MOD;
        }
        res = (res % MOD * dp[n + 1] % MOD) % MOD;
    }
 
    cout << res;
    log_resource();
    KILL();
}