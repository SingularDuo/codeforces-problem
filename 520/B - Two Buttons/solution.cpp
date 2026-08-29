#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vi>
#define vii vector<pii>
#define ull unsigned long long
#define ld long double
#define setp(x) fixed << setprecision(x)
#define setp2(x, y) fixed << setprecision(x) << y
#define endl "
"
#define __TOISETHIVOI__ signed main()
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define yes cout << "YES
"
#define no cout << "NO
"
#define YESNO(x) cout << ((x) ? "YES
" : "NO
")
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define kill cout<<"end"<<endl;
#define traillingzero(x) __builtin_ctzll(x)
#define count_bit_1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
 
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = INT_MAX;
const int N = 2e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;
 
void OJ()
{
    fast;
}
void THEMIS()
{
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);
    fast;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    int ops = 0;
 
    while (m > n) {
        if (m % 2 == 0) {
            m /= 2;
        } else {
            m++;
        }
        ops++;
    }
 
 
    cout << ops + (n - m) << endl;
}
__TOISETHIVOI__
{
    int t = 1;
    // cin >> t;
    for(int i = 0; i < t; i++)
    {
        solve();
    }
}