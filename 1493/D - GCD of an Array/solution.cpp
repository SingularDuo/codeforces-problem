/*
Author: duxp
Version: 1
Created at: 2026-01-15 20:34
*/
#include <bits/stdc++.h>
 
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
 
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
 
#define trailingzero(x) __builtin_ctzll(x)
#define cntbit1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
 
#define TDN signed main()
#define KILL() exit(0)
#define NAME "task"
 
struct custom {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
template <typename T>
inline int getbit(T x, int k) { return (x >> k) & 1; }
 
template <typename T>
inline T onbit(T x, int k) { return x | (T(1) << k); }
 
template <typename T>
inline T offbit(T x, int k) { return x & ~(T(1) << k); }
 
template <typename T>
inline bool minimize(T &a, const T &b) {
    if (a > b) { a = b; return true; }
    return false;
}
 
template <typename T>
inline bool maximize(T &a, const T &b) {
    if (a < b) { a = b; return true; }
    return false;
}
 
const ll INF = 1e18;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAXN = 200000 + 5;
 
int spf[MAXN];
 
ll modpow(ll a, ll e)
{
    ll r = 1;
    while(e)
    {
        if(e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}
 
void sieve()
{
    for(int i = 1; i < MAXN; i++) spf[i] = i;
    for(int i = 2; i * i < MAXN; i++)
        if(spf[i] == i)
            for(int j = i * i; j < MAXN; j += i)
                if(spf[j] == j) spf[j] = i;
}
 
int n, q;
ll a[MAXN];
 
unordered_map<int, unordered_map<ll,int,custom>, custom> mp;
unordered_map<ll, map<int,int>, custom> cnt;
unordered_map<ll, int, custom> min_exp;
 
ll cur_gcd = 1;
 
unordered_map<ll,int,custom> factor(ll x)
{
    unordered_map<ll,int,custom> res;
    while(x > 1)
    {
        ll p = spf[x];
        int c = 0;
        while(x % p == 0)
        {
            x /= p;
            c++;
        }
        res[p] += c;
    }
    return res;
}
 
TDN
{
    fast;
    string fname = string(NAME);
    if (fopen((fname + ".inp").c_str(), "r")) {
        freopen((fname + ".inp").c_str(), "r", stdin);
        freopen((fname + ".out").c_str(), "w", stdout);
    }
 
    sieve();
 
    cin >> n >> q;
 
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        auto f = factor(a[i]);
        for(auto &it : f)
            mp[i][it.fi] += it.se;
    }
 
    for(int i = 1; i <= n; i++)
        for(auto &it : mp[i])
            cnt[it.fi][it.se]++;
 
    for(auto &it : cnt)
    {
        int have = 0;
        for(auto &e : it.se) have += e.se;
        if(have < n)
            it.se[0] += (n - have);
    }
 
    for(auto &it : cnt)
    {
        ll p = it.fi;
        int mn = it.se.begin()->fi;
        min_exp[p] = mn;
        if(mn > 0)
            cur_gcd = cur_gcd * modpow(p, mn) % MOD;
    }
 
    while(q--)
    {
        int idx;
        ll x;
        cin >> idx >> x;
 
        auto add = factor(x);
 
        for(auto &it : add)
        {
            ll p = it.fi;
            int d = it.se;
 
            int olde = mp[idx][p];
            int newe = olde + d;
            mp[idx][p] = newe;
 
            if(cnt[p].empty())
            {
                cnt[p][0] = n;
                min_exp[p] = 0;
            }
 
            cnt[p][olde]--;
            if(cnt[p][olde] == 0) cnt[p].erase(olde);
            cnt[p][newe]++;
 
            int old_min = min_exp[p];
            int new_min = cnt[p].begin()->fi;
            min_exp[p] = new_min;
 
            if(new_min > old_min)
                cur_gcd = cur_gcd * modpow(p, new_min - old_min) % MOD;
        }
 
        cout << cur_gcd << '
';
    }
 
    KILL();
}