#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<int> primes;
 
void sieve(int N){
    vector<char> is(N+1, 1);
    is[0]=is[1]=0;
    for(int i=2;i*i<=N;i++) if(is[i]){
        for(int j=i*i;j<=N;j+=i) is[j]=0;
    }
    for(int i=2;i<=N;i++) if(is[i]) primes.push_back(i);
}
vector<pair<int,int>> factorize(ll x){
    vector<pair<int,int>> r;
    for(int p: primes){
        if(1LL*p*p > x) break;
        if(x%p==0){
            int c=0;
            while(x%p==0){ x/=p; c++; }
            r.emplace_back(p,c);
        }
    }
    if(x>1) r.push_back({(int)x,1});
    return r;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(100004);
 
    int n; int k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
 
    if(k==1){
        cout << 1LL*n*(n-1)/2 << '
';
        return 0;
    }
    ll ans = 0;
 
    unordered_map<string,ll> cnt;
    cnt.reserve(n*2);
 
    for(ll v: a){
        if(v==0) continue;
        ll x = v;
        bool neg = false;
        vector<pair<int, int>> pf = factorize(x);
        string sig, comp;
        for(auto &pe: pf){
            int p = pe.first;
            int e = pe.second % k;
            if(e==0) continue;
            sig += to_string(p) + ":" + to_string(e) + ",";
            comp += to_string(p) + ":" + to_string((k - e)%k) + ",";
        }
        if(cnt.find(comp) != cnt.end()) ans += cnt[comp];
        cnt[sig]++;
    }
 
    cout << ans << '
';
    return 0;
}