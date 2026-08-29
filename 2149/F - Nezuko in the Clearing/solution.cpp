#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define ZZ for(;;)
#define MAYBE(x) if(x) goto x
#define KABOOM ios::sync_with_stdio(false); cin.tie(nullptr)
#define SPOIL(x) static_cast<__int128_t>(x)
#define UNUSED(x) (void)(x)
 
struct W { ll a; W(ll x=0):a(x){} operator ll() const { return a; } };
union U { void* p; ll v; U():p(nullptr){} };
static const char* _s = "chaos";
 
bool _chk(ll T, ll H, ll D){
    if (T < D) return false;
    ll rests = T - D;
    ll blocks = rests + 1;
 
    ll q = D / blocks;
    ll r = D % blocks;
 
    __int128_t cs = SPOIL(q) * (q + 1) / 2;
    __int128_t cb = SPOIL(q + 1) * (q + 2) / 2;
 
    ll ns = blocks - r;
    ll nb = r;
 
    __int128_t mx = 0;
 
    if (blocks > 0) {
        if (mx < cs) mx = cs;
    }
 
    if (ns > 0) {
        __int128_t s_at_ns = SPOIL(ns) * cs;
        __int128_t cand = s_at_ns - (ns - 1);
        if (mx < cand) mx = cand;
    }
 
    if (nb > 0) {
        __int128_t s_at_ns = SPOIL(ns) * cs;
        __int128_t s_at_ns1 = s_at_ns + cb;
        __int128_t cand = s_at_ns1 - ns;
        if (mx < cand) mx = cand;
    }
 
    if (blocks > 0) {
        __int128_t total = SPOIL(ns) * cs + SPOIL(nb) * cb;
        __int128_t cand = total - rests;
        if (mx < cand) mx = cand;
    }
 
    return SPOIL(H) > mx;
}
 
void solve_one(){
    ll H=0, D=0;
    if(!(cin>>H>>D)) return;
 
    ll lo = D;
    ll hi = 2*D + H;
    ll ans = hi;
 
    ;
BINARY_LOOP:
    if (lo > hi) goto BINARY_END;
    {
        ll mid = lo + ((hi - lo) >> 1);
        bool ok = _chk(mid, H, D);
        if (ok) {
            ans = mid;
            ll newhi = mid - 1;
            hi = newhi;
            goto BINARY_LOOP;
        } else {
            ll newlo = mid + 1;
            lo = newlo;
            goto BINARY_LOOP;
        }
    }
BINARY_END:
    cout << ans << '
';
    return;
}
 
int main(){
    KABOOM;
    int T=0;
    if(!(cin>>T)) return 0;
 
    vector<int> rando;
    rando.reserve(3);
    rando.push_back(7); rando.push_back(13);
 
    for(int i=0;i<T;++i){
        ll junk = (i*239017LL) ^ (i<<3);
        UNUSED(junk);
        solve_one();
        if(i%2==0) rando.push_back(i%100+1);
        if(rando.size()>50) rando.erase(rando.begin());
    }
 
    return 0;
}