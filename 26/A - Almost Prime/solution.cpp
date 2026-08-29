/*
Author: duxp
Version: 1
Created at: 2026-01-15 10:59
*/
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <chrono>
#include <cmath>
#include <cstdio>
 
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
 
#define trailingzero(x) __builtin_ctzll(x)
#define cntbit1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
 
#define TDN signed main()
#define KILL() exit(0)
#define NAME "task"
 
const ll INF = 1e18;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAXN = 4000;
 
bool isprime[MAXN + 1];
vi prime;
 
void sieve()
{
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
 
    for(int i = 2; i * i <= MAXN; i++)
    {
        if(isprime[i])
        {
            for(int j = i * i; j <= MAXN; j += i)
                isprime[j] = false;
        }
    }
 
    for(int i = 2; i <= MAXN; i++)
        if(isprime[i]) prime.pb(i);
}
 
int cntprime(int x)
{
    set<int> s;
    for(int i = 0; i < (int)prime.size() && prime[i] * prime[i] <= x; i++)
    {
        while(x % prime[i] == 0)
        {
            x /= prime[i];
            s.insert(prime[i]);
        }
    }
    if(x != 1) s.insert(x);
    return s.size() == 2;
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
 
    int n; 
    cin >> n;
 
    int res = 0;
    for(int i = 1; i <= n; i++)
        if(cntprime(i)) res++;
 
    cout << res;
    KILL();
}