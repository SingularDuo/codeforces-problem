/*
        _.-- ,.--.
      .'   .'     /
       @       '..--------._
     /      \._/              '.
    /  .-.-                     \
   (  /    \                     \
   \      '.                  | #
    \       \   -.           /
     :\       |    )._____.'   \
      "       |   /  \  |  \    )
    Kduckp       |   |./'  :__ \.-'
              '--'
*/
/*
 * Author: Kduckp
 * Generated on: 2025-07-14 20:03:17
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vi>
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '
'
 
#define FOR(i, n) for (int i = 1; i <= (n); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define EACH(x, a) for (auto& x : a)
 
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define yes cout << "YES
"
#define no cout << "NO
"
#define YESNO(x) cout << ((x) ? "YES
" : "NO
")
 
#define bitcount(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)
 
#define debug(x)
#define lb lower_bound
#define ub upper_bound
 
#define __TOISETHIVOI__ signed main()
#define vec(a, b, c, d) vector<a> b(c, d)
#define allin(a, x) (find(all(a), x) != (a).end())
#define vec2d(type, name, r, c, val) vector<vector<type>> name((r), vector<type>((c), (val)))
#define vec3d(type, name, x, y, z, val) vector<vector<vector<type>>> name((x), vector<vector<type>>((y), vector<type>((z), (val))))
 
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = 2e18;
const int N = 2e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;
 
void name(const string &inFile, const string &outFile) {
    freopen(inFile.c_str(), "r", stdin);
    freopen(outFile.c_str(), "w", stdout);
}
 
void init() {
    fast;
    // name("input.inp", "output.out");
}
 
__TOISETHIVOI__ {
    init();
    int t; cin>>t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
 
        int cnt = 0;
        for (int i = 0; i + k <= n; ) {
            bool ok = true;
            for (int j = 0; j < k; j++) {
                if (a[i + j] == 1) {
 
                    //cout<<a[i + j]<<" "<<i<<" "<<j<<endl;
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cnt++;
                i += k + 1;
            }
            else {
                i++;
            }
        }
        cout << cnt << '
';
    }
 
 
 
    return 0;
}