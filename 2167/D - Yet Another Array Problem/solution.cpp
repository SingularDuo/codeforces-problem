#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TDN signed main()
 
vector<int> gen(int M){
    vector<char> is(M+1,1);
    is[0]=is[1]=0;
    for(int p=2;p*p<=M;++p) if(is[p])
        for(int q=p*p;q<=M;q+=p) is[q]=0;
    vector<int> P;
    for(int i=2;i<=M;++i) if(is[i]) P.pb(i);
    return P;
}
 
void solve(){
    int n; cin>>n;
    vector<int> a(n);
    bool has_odd = false;
    for(int i=0;i<n;++i){ cin>>a[i]; if(a[i]&1) has_odd = true; }
    if(has_odd){
        cout<<2<<"
";
        return;
    }
    static vector<int> P = gen(200000); 
    const int INF = (int)4e18;
    int ans = INF;
    for(int i=0;i<n;++i){
        for(int p: P){
            if(a[i] % p != 0){
                ans = min(ans, (int)p);
                break;
            }
        }
    }
    if(ans==INF) cout << -1 << "
";
    else cout << ans << "
";
}
 
TDN{
    fast;
    int tc; cin>>tc;
    while(tc--) solve();
    return 0;
}