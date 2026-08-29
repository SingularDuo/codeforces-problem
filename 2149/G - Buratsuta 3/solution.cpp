#include <bits/stdc++.h>
using namespace std;
 
const int MAX_NODES = 5000000;
 
struct Node { int c; Node* L; Node* R; };
static Node pool[MAX_NODES];
static int it;
static Node* E;
 
inline void init_pool(){
    it=0;
    E = &pool[it++];
    E->c = 0; E->L = E->R = E;
}
 
inline Node* make(Node* P){ Node* X = &pool[it++]; *X=*P; ++X->c; return X; }
 
Node* upd(Node* P,int l,int r,int pos){
    Node* C = make(P);
    if(l==r) return C;
    int m=(l+r)>>1;
    if(pos<=m) C->L=upd(P->L,l,m,pos);
    else C->R=upd(P->R,m+1,r,pos);
    return C;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T; cin>>T;
    while(T--){
        init_pool();
        int n,q; cin>>n>>q;
        vector<int> a(n), comp;
        for(int &x:a){ cin>>x; comp.push_back(x); }
        sort(comp.begin(),comp.end());
        comp.erase(unique(comp.begin(),comp.end()),comp.end());
        int m=comp.size();
        auto idx=[&](int v){return int(lower_bound(comp.begin(),comp.end(),v)-comp.begin());};
 
        vector<Node*> root(n+1); root[0]=E;
        for(int i=0;i<n;i++) root[i+1]=upd(root[i],0,m-1,idx(a[i]));
 
        vector<int> ans;
        function<void(Node*,Node*,int,int,int)> dive=[&](Node* U,Node* V,int l,int r,int thr){
            if(V->c - U->c <= thr) return;
            if(l==r){ ans.push_back(comp[l]); return; }
            int mid=(l+r)>>1;
            dive(U->L,V->L,l,mid,thr);
            dive(U->R,V->R,mid+1,r,thr);
        };
 
        while(q--){
            int L,R; cin>>L>>R;
            ans.clear();
            int len=R-L+1, thr=len/3;
            dive(root[L-1],root[R],0,m-1,thr);
            if(ans.empty()) cout<<-1<<"
";
            else{
                for(int i=0;i<ans.size();i++) cout<<ans[i]<<(i+1==ans.size()?"":" ");
                cout<<"
";
            }
        }
    }
}