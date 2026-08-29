/*
Author: Kduckp
Version: 1
Created at: 2025-12-27 10:54
*/
#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define int ll 
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
#define traillingzero(x) __builtin_ctzll(x)
#define cntbit1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
#define TDN signed main()
int getbit(int x, int k){return (x >> k) & 1;}
int offbit(int x, int k){return x & (~(1 << k));}
const ll INF = 1e18;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAXN = 200000;
void solve()
{
    int n; 
    ll res = 0;
    cin >> n;
 
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    // vector<int> clone(a.begin() + 1, a.end());
    // sort(all(clone));
    // clone.erase(unique(all(clone)), clone.end());
    // for(int i = 1; i <= n; i++) a[i] = lower_bound(all(clone), a[i]) - clone.begin() + 1;
    vector<int> f(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + i;
    }
 
    int sumRange = 0, sumKhe = 0;   
    for(int l = 1; l <= n; l++)
    {
        int sumRight = f[n] - f[l];
        sumRange += sumRight - l * (n - l);
    }
    
    for(int khe = 1; khe <= n - 1; khe++)
    {
        ll minRight = a[khe + 1];
        
        int ptrLeft = 1;
        vector<int> maxL(khe + 1, -INF);
        maxL[khe] = a[khe];
        for (int i = khe - 1; i >= 1; i--)
        {
            maxL[i] = max(maxL[i + 1], a[i]);
        }
        ll maxLeft = maxL[1];
        //cout<<"khe: "<<khe<<endl;
        //for(int i = khe; i >= 1; i--) cout<<maxL[i]<<" ";
        //cout<<endl;
        for(int ptrRight = khe + 1; ptrRight <= n; ptrRight++)
        {
            minRight = min(minRight, a[ptrRight]);
            while(maxLeft > minRight && ptrLeft <= khe) 
            {
                ++ptrLeft;
                maxLeft = maxL[ptrLeft];
            }
            //cout<<ptrLeft<<" "<<ptrRight<<" "<<maxLeft<<" "<<minRight<<endl;
            sumKhe += khe - ptrLeft + 1;
        }
        
    }
    //cout<<sumRange<<" "<<sumKhe<<endl;
    cout<<sumRange - sumKhe<<endl;
 
    
    
}
// hahaha
TDN
{
        fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    int tc; cin>>tc;
    while(tc--)
    {
        solve();
    }
}//ha