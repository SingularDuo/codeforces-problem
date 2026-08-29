// Problem: A. Doremy's Paint 3
// Contest: Codeforces - Codeforces Round 906 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1890/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
/*
Author: duxp
"IT WORKED ON MY MACHINE!"
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define int ll
#define ld long double 
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define nall(x) (x).begin(), (x).end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define vpii vector<pii>
#define endl '
'
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, x) memset((a), (x), sizeof((a)))
 
#define _______TOISECOGIAIVOI_______ signed main()
#define KILL() exit(0)
#define NAME "duxp"
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
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
 
template <typename T> inline int getbit(T x, int k) { return (x >> k) & 1; }
template <typename T> inline T onbit(T x, int k) { return x | (T(1) << k); }
template <typename T> inline T offbit(T x, int k) { return x & ~(T(1) << k); }
 
const ll OO = 1e18;
const int oo = 1e9;
const int MOD = 1e9 + 7;
const int MAXN = 200000;
const int LOG = 20;
 
 
_______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    
    int tc; cin>>tc;
    while(tc--)
    {
    	int n; cin>>n;
    	map<int, int> freq;
    	for(int i = 1; i <= n; i++)
    	{
    		int x; cin>>x;
    		freq[x]++;
    	}
    	if(freq.size() >= 3) cout<<"No"<<endl;
    	else
    	{
    		if (abs(freq.begin()->second - freq.rbegin()->second) <= 1) cout<<"Yes"<<endl;
		    else cout<<"No"<<endl;
    	}
    }
 
    return 0;
}