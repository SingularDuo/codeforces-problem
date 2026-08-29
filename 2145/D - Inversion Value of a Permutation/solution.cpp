#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i,a,b) for(int i=(a); i<=(b); ++i)
#define R(i,a,b) for(int i=(a); i>=(b); --i)
#define pb push_back
 
const int MXN = 31;
const int MXS = 466; 
 
static bool D[MXN][MXS];
static int P[MXN][MXS];
static int TRI[MXN];
 
void precompute_tri(){
    F(i,1,30) TRI[i] = i*(i+1)/2;
}
 
bool read_case(int &n, ll &k){
    if(!(cin >> n >> k)) return false;
    return true;
}
 
long long compute_S(int n, long long k){
    long long tot = 1LL * n * (n+1) / 2;
    long long S = tot - k;
    if(S < 0) return -1;
    return S;
}
 
void init_dp(int n, int S){
    F(i,0,n) F(j,0,S) D[i][j] = false;
    D[0][0] = true;
}
 
bool run_dp(int n, int S){
    F(i,1,n){
        F(j,1,S){
            F(m,1,i){
                int t = TRI[m];
                if(j >= t && D[i-m][j-t]){
                    D[i][j] = true;
                    P[i][j] = m;
                    break;
                }
            }
        }
    }
    return D[n][S];
}
 
vector<int> reconstruct_blocks(int n, int S){
    vector<int> blocks;
    int cn = n, cs = S;
    while(cn > 0){
        int m = P[cn][cs];
        blocks.pb(m);
        cn -= m;
        cs -= TRI[m];
    }
    return blocks;
}
 
vector<int> build_permutation(const vector<int> &blocks, int n){
    vector<int> p; p.reserve(n);
    int cur = n;
    for(int m : blocks){
        int s = cur - m + 1;
        F(i, s, cur) p.pb(i);
        cur = s - 1;
    }
    return p;
}
 
void print_perm(const vector<int> &p){
    int n = (int)p.size();
    F(i,0,n-1){
        cout << p[i];
        if(i < n-1) cout << ' ';
    }
    cout << '
';
}
 
void solve_case(){
    int n; ll k;
    if(!read_case(n, k)) return;
    long long Sll = compute_S(n, k);
    if(Sll < 0){
        cout << 0 << '
';
        return;
    }
    int S = (int)Sll;
    init_dp(n, S);
    bool ok = run_dp(n, S);
    if(!ok){
        cout << 0 << '
';
        return;
    }
    vector<int> blocks = reconstruct_blocks(n, S);
    vector<int> perm = build_permutation(blocks, n);
    print_perm(perm);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute_tri();
    int tc;
    if(!(cin >> tc)) return 0;
    while(tc--) solve_case();
    return 0;
}