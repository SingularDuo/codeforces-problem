/*
Author: duxp
Date: 
Note: 
The king has returned, and the throne has been reclaimed.
The racer has returned, and the track is ready to be fired up again.
The coder has returned, and new problems are ready to be solved.
*/
#pragma GCC optimize("O3,unroll-loops,inline,fast-math")
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,tune=native")
#pragma GCC optimize("no-stack-protector")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-variable"
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
 
#ifndef ONLINE_JUDGE
    #ifdef __APPLE__
        #include <mach/mach.h>
    #endif
#endif
 
using namespace std;
 
#define ll long long
#define ld long double 
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
#define YESNO(x) if(x) cout<<"YES";  else cout<<"NO";
 
#define _______TOISECOGIAIVOI_______ signed main()
#define KILL() exit(0)
#define NAME "duxp"
#ifndef ONLINE_JUDGE
    #ifdef __APPLE__
        #include <mach/mach.h>
        #include <mach-o/getsect.h>
        #include <mach-o/dyld.h>
        extern "C" struct mach_header_64 _mh_execute_header;
    #endif
    void force_memory_allocation() {
        #ifdef __APPLE__
            unsigned long size;
            const char* sections[] = {"__bss", "__common"};
            
            for (const char* sec : sections) {
                uint8_t* ptr = getsectiondata(&_mh_execute_header, "__DATA", sec, &size);
                if (ptr) {
                    for (unsigned long i = 0; i < size; i += 4096) {
                        *(volatile char*)(ptr + i) = *(ptr + i);
                    }
                }
            }
        #endif
    }
    void log_resource() {
        double mem_mb = 0;
        #ifdef __APPLE__
            struct task_basic_info t_info;
            mach_msg_type_number_t t_info_count = TASK_BASIC_INFO_COUNT;
            if (task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&t_info, &t_info_count) == KERN_SUCCESS) {
                mem_mb = t_info.resident_size / (1024.0 * 1024.0);
            }
            mem_mb -= 1.5; 
            if (mem_mb < 0) mem_mb = 0;
        #else
            struct rusage usage;
            if (getrusage(RUSAGE_SELF, &usage) == 0) {
                mem_mb = usage.ru_maxrss / 1024.0;
            }
        #endif
 
        cerr << fixed << setprecision(3) << "
========== DEBUG ==========
";
        cerr << "Time: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms
";
        cerr << "Memory (User): " << mem_mb << " MB
";
        cerr << "===========================
";
    }
#else
    void force_memory_allocation() {}
    void log_resource() {}
#endif
 
constexpr int MAXN = 200000;
constexpr int MAXD = 11; 
struct Node {
    int cnt[10][MAXD]; 
    ll sum;
} st[4 * MAXN + 5];
int lazy[4 * MAXN + 5][10];
int n, q;
ll a[MAXN + 5];
ll p10[MAXD + 2];
void resetLazy(int node) 
{
    for (int i = 0; i <= 9; i++) lazy[node][i] = i;
}
 
void apply_lazy(int node, int map_to[10]) 
{
    int new_cnt[10][MAXD] = {0};
    ll new_sum = 0;
 
    for (int d = 0; d <= 9; d++) {
        int target_d = map_to[d];
        for (int p = 0; p < MAXD; p++) {
            if (st[node].cnt[d][p] > 0) {
                new_cnt[target_d][p] += st[node].cnt[d][p];
                new_sum += (ll)st[node].cnt[d][p] * target_d * p10[p];
            }
        }
    }
 
    for (int d = 0; d <= 9; d++) {
        for (int p = 0; p < MAXD; p++) {
            st[node].cnt[d][p] = new_cnt[d][p];
        }
    }
    st[node].sum = new_sum;
 
    int new_lazy[10];
    for (int d = 0; d <= 9; d++) {
        new_lazy[d] = map_to[lazy[node][d]];
    }
    for (int d = 0; d <= 9; d++) {
        lazy[node][d] = new_lazy[d];
    }
}
 
void push(int node) {
    bool has_lazy = false;
    for (int i = 0; i <= 9; i++) {
        if (lazy[node][i] != i) {
            has_lazy = true;
            break;
        }
    }
    if (!has_lazy) return;
 
    apply_lazy(node * 2, lazy[node]);
    apply_lazy(node * 2 + 1, lazy[node]);
 
    resetLazy(node);
}
 
void MERGE(int node) {
    st[node].sum = st[node * 2].sum + st[node * 2 + 1].sum;
    for (int d = 0; d <= 9; d++) {
        for (int p = 0; p < MAXD; p++) {
            st[node].cnt[d][p] = st[node * 2].cnt[d][p] + st[node * 2 + 1].cnt[d][p];
        }
    }
}
 
void build(int node, int s, int e) {
    resetLazy(node);
    memset(st[node].cnt, 0, sizeof(st[node].cnt));
 
    if (s == e) {
        ll val = a[s];
        st[node].sum = val;
        
        if (val == 0) {
            st[node].cnt[0][0] = 1;
            return;
        }
 
        int pos = 0;
        while (val > 0) {
            int dig = val % 10;
            st[node].cnt[dig][pos]++;
            val /= 10;
            pos++;
        }
        return;
    }
    int mid = (s + e) / 2;
    build(node * 2, s, mid);
    build(node * 2 + 1, mid + 1, e);
    MERGE(node);
}
 
void update(int node, int s, int e, int l, int r, int x, int y) {
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        int map_to[10];
        for (int i = 0; i <= 9; i++) map_to[i] = i;
        map_to[x] = y;
        apply_lazy(node, map_to);
        return;
    }
    push(node);
    int mid = (s + e) / 2;
    update(node * 2, s, mid, l, r, x, y);
    update(node * 2 + 1, mid + 1, e, l, r, x, y);
    MERGE(node);
}
 
ll get(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return st[node].sum;
    push(node);
    int mid = (s + e) / 2;
    return get(node * 2, s, mid, l, r) + get(node * 2 + 1, mid + 1, e, l, r);
}
 
                    _______TOISECOGIAIVOI_______
{
    fast;
    // force_memory_allocation();
    p10[0] = 1;
    for (int i = 1; i <= MAXD; i++) p10[i] = p10[i - 1] * 10;
    cin>>n>>q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, x, y; cin >> l >> r >> x >> y;
            if (x != y) update(1, 1, n, l, r, x, y);
        } else {
            int l, r; cin >> l >> r;
            cout << get(1, 1, n, l, r) << endl;
        }
    }
    // log_resource();
    KILL();
}