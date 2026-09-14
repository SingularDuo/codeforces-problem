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
const int maxn=300005;
int n,m,k;
vector <ii> adj[maxn];
int d[maxn];
ii train[maxn];
// ans=k-need
bool non_remove[maxn]={0};
int last[maxn];
//===================================================================================
void Sol()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>train[i].fi>>train[i].se;
    }
    priority_queue <ii,vector <ii>,greater<ii>>  qe;
    memset(last,-1,sizeof last);
    fill(d,d+maxn,INF);
    d[1]=0;
    qe.push({0,1});
    for(int i=1;i<=k;i++){
        if(d[train[i].fi]>train[i].se){
            d[train[i].fi]=train[i].se;
            if(last[train[i].fi]!=-1){
                non_remove[last[train[i].fi]]=false;
            }
            last[train[i].fi]=i;
            non_remove[i]=true;
        }
    }
    for(int i=1;i<=k;i++){
        if(non_remove[i]){
            int u=train[i].fi;
            int w=train[i].se;
   //         cout<<i<<'
';
            qe.push({w,u});
        }
    }
 //   cout<<'
';
    while(!qe.empty()){
        int u=qe.top().se;
        int du=qe.top().fi;
        qe.pop();
        if(du>d[u]) continue;
        for(ii i:adj[u]){
            int v=i.fi;
            int w=i.se;
            if(d[v]>du+w){
                d[v]=du+w;
                if(last[v]!=-1){
                    non_remove[last[v]]=false;
                }
                qe.push({d[v],v});
            }
            else if(d[v]==du+w){
                if(last[v]!=-1){
                    non_remove[last[v]]=false;
                }
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=k;i++){
        if(non_remove[i]){
            cnt++;
        }        
    }
    //cout<<'
';
    cout<<k-cnt;
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