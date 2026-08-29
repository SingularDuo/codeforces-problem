#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define EYMK signed main()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define each(x) for(auto & i : x)
#define vvi vector<vi>
#define pb push_back
#define endl '
'
#define yesno(x) cout << ((x) ? "YES
" : "NO
")
 
const int MOD = 1e9 + 7;
const int LARGEPRIME = 998244353;
const int INF_INT = 2147483647;
const ll INF_LL = 2 * 1e18;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int dx8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy8[] = {0, 0, -1, 1, -1, 1, -1, 1};
 
template<typename T, typename T1>T amax(T &a, T1 b){if(b>a)a=b;return a;}
template<typename T, typename T1>T amin(T &a, T1 b){if(b<a)a=b;return a;}
 
int n, m;
const int B = 31; 
const int MAXN = 200005;
int st[4*MAXN];
int a[MAXN];
 
void build(int p, int l, int r){
    if(l == r){
        st[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    st[p] = st[p<<1] & st[p<<1|1];
}
 
int query(int p, int l, int r, int i, int j){
    if(r < i || l > j) return (1<<30) - 1;
    if(i <= l && r <= j) return st[p];
    int mid = (l + r) >> 1;
    return query(p<<1, l, mid, i, j) & query(p<<1|1, mid+1, r, i, j);
}
 
void solve(){
    cin >> n >> m;
    vector<int> L(m), R(m), Q(m);
    vector<vector<int>> diff(B, vector<int>(n+3, 0));
 
    for(int t=0; t<m; t++){
        cin >> L[t] >> R[t] >> Q[t];
        bitset<B> bnum(Q[t]);
        for(int bit=0; bit<B; bit++){
            if(bnum[bit]){
                diff[bit][L[t]]++;
                diff[bit][R[t]+1]--;
            }
        }
    }
 
    for(int i=1; i<=n; i++) a[i] = 0;
    for(int bit=0; bit<B; bit++){
        int cur = 0;
        for(int i=1; i<=n; i++){
            cur += diff[bit][i];
            if(cur > 0) a[i] |= (1<<bit);
        }
    }
 
    build(1, 1, n);
 
    for(int t=0; t<m; t++){
        int val = query(1, 1, n, L[t], R[t]);
        if(val != Q[t]){
            cout << "NO
";
            return;
        }
    }
 
    cout << "YES
";
    for(int i=1; i<=n; i++){
        if(i > 1) cout << ' ';
        cout << a[i];
    }
    cout << '
';
}
 
EYMK {
    fast;
 
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
    solve();
    return 0;
}