/*
Author : minhhhhsadk
=====================================================================================
*/
 
#include <bits/stdc++.h>
using namespace std;
 
//=========================== TYPEDEF ===============================================
#define int long long
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define nall(x) (x).begin() + 1, (x).end()
 
 
#define fi first
#define se second
#define tminh signed main()
#define NAME "tminh"
 
//=========================== CONSTANT ==============================================
const ll INF  = 1000000000000000000LL;
const int oo = 1000000000;
const int MOD = 1000000007;
const int MOD2 = 998244353;
typedef pair<int,int> ii;
const int maxn=300005;
int n,m,q,k;
vector <ii> adj[maxn];
int d[maxn];
int par[maxn],sz[maxn];
int to[maxn];
struct Edge
{
    int u,v,w;
}e[maxn];
vector <Edge> new_e;
vector <ii> new_adj[maxn];
int up[maxn][20];
int mx[maxn][20];
int h[maxn]={0};
//===================================================================================
void dijkstra()
{
    fill(d,d+maxn,INF);
    priority_queue <ii,vector <ii>,greater<ii>> qe;
    for(int i=1;i<=k;i++){
        to[i]=i;
        par[i]=i;
        sz[i]=1;
        d[i]=0;
        qe.push({0,i});
    }
    while(!qe.empty()){
        int du=qe.top().fi;
        int u=qe.top().se;
        qe.pop();
        if(d[u]<du) continue;
        for(ii i:adj[u]){
            int v=i.fi;
            int w=i.se;
            if(d[v]>du+w){
                d[v]=du+w;
                to[v]=to[u];
                qe.push({d[v],v});
            }
        }
    }
}
int find_set(int u)
{
    if(par[u]==u) return u;
    return par[u]=find_set(par[u]);
}
void dfs(int u)
{
    for(ii i:new_adj[u]){
        int v=i.fi;
        int w=i.se;
        if(v==up[u][0]) continue;
        up[v][0]=u;
        mx[v][0]=w;
        h[v]=h[u]+1;
        for(int j=1;j<=18;j++){
            up[v][j]=up[up[v][j-1]][j-1];
            mx[v][j]=max(mx[v][j-1],mx[up[v][j-1]][j-1]);
        }
        dfs(v);
    }
}
int lca(int u,int v)
{
    int res=-INF;
    if(h[u]!=h[v]){
        if(h[u]<h[v]) swap(u,v);
        int diff=h[u]-h[v];
        for(int j=0;(1<<j)<=diff;j++){
            if((diff>>j)&1){
                res=max(res,mx[u][j]);
                u=up[u][j];
            }
        }
    }
    if(u==v) return res;
    for(int j=18;j>=0;j--){
        if(up[u][j]!=up[v][j]){
            res=max(res,mx[v][j]);
            res=max(res,mx[u][j]);
            u=up[u][j];
            v=up[v][j];
        }
    }
    res=max(res,max(mx[v][0],mx[u][0]));
    return res;
}
bool union_set(int u,int v)
{
    u=find_set(u);
    v=find_set(v);
    if(u==v) return false;
    if(sz[u]<sz[v]) swap(u,v);
    sz[u]+=sz[v];
    par[v]=u;
    return true;
}
bool cmp(Edge x,Edge y)
{
    return x.w<y.w;
}
void Sol()
{
    cin>>n>>m>>k>>q;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        e[i].u=u;
        e[i].v=v;
        e[i].w=w;
    }
    dijkstra();
    for(int i=1;i<=m;i++){
        int u=to[e[i].u];
        int v=to[e[i].v];
        if(u!=v){
            new_e.pb({u,v,d[e[i].u]+e[i].w+d[e[i].v]});
        }
    }
    sort(new_e.begin(),new_e.end(),cmp);
    for(auto i:new_e){
        int u=i.u;
        int v=i.v;
        if(union_set(u,v)){
            new_adj[u].pb({v,i.w});
            new_adj[v].pb({u,i.w});
        }
    }
    dfs(1);
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        u=to[u];
        v=to[v];
        cout<<lca(u,v)<<'
';
    }
}
void Init()
{
    freopen("tminh.inp","r",stdin);
    freopen("tminh.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
tminh
{
    // Init();
    Sol();
    return 0;
}