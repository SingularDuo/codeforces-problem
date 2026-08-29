/*
Author: Kduckp
Version: 1
Created at: 2025-12-27 17:36
*/
#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define int long long
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
const int MAXN = 100000;
int n , m;
int a[MAXN + 5];
pair<int, int> st[MAXN * 4];
pii merge(pii a, pii b)
{
    pii res;
    res.fi = a.fi + b.fi;
    res.se = max(a.se, b.se);
    return res;
}
void build(int id, int l, int r)
{
    if(l == r)
    {
        st[id] = {a[l], a[l]};
        return;
    }
    int mid = (l + r)  / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}
void update1(int id , int l, int r, int u, int v, int x)
{
    if(l > v || r < u) return;
    if(st[id].se < x) return;
    if(l == r)
    {
        a[l] %= x;
        st[id].fi = st[id].se = a[l];
        return;
    }
    int mid = (l + r) / 2;
    update1(id * 2, l, mid , u, v, x);
    update1(id * 2 + 1, mid + 1, r, u, v, x);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
 
}
void update2(int id, int l, int r, int pos, int val)
{
    if(l > pos || r < pos) return;
    if(l == r)
    {
        a[l] = val;
        st[id].fi = st[id].se = a[l];
        return;
    }
    int mid = (l + r) / 2;
    update2(id * 2, l, mid , pos, val);
    update2(id * 2 + 1, mid + 1, r,pos, val);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
 
}
int get(int id, int l, int r, int u, int v)
{
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return st[id].fi;
    int mid = (l + r) / 2;
    
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
TDN
{
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>a[i];
    build(1,1,n);
    while(m--)
    {
        int t; cin>>t;
        if(t == 1)
        {
            int l, r; cin>>l>>r;
            cout<<get(1,1,n,l,r)<<endl;
 
        }
        else if(t == 2)
        {
            int l, r, x; cin>>l>>r>>x;
            update1(1,1,n,l,r,x);
        }
        else
        {
            int k, x; cin>>k>>x;
            update2(1,1,n,k,x);
            
        }
    }
}