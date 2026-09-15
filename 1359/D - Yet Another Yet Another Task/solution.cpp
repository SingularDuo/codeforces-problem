/*
Author : minhhhhsadk
=====================================================================================
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pb push_back
#define fi first
#define se second
#define fast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define tminh signed main()
#define NAME "tminh"
const ll INF = 1000000000000000000LL;
const int oo = 1000000000;
const int MOD = 1000000007;
const int MOD2 = 998244353;
typedef pair<int,int> ii;
const int maxn=200005;
int n;
int a[maxn];
//===================================================================================
void Sol()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int res=0;
    for(int mx=0;mx<=30;mx++){
        int best=0;
        int cur=0;
        for(int i=1;i<=n;i++){
            int val=a[i];
            if(val>mx) val=-oo;
            cur+=val;
            best=min(best,cur);
            res=max(res,(cur-best)-mx);
        }
    }
    cout<<res;
}
tminh
{
    fast;
 
    if (FILE *f = fopen(NAME ".inp", "r"))
    {
        fclose(f);
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    Sol();
    return 0;
}