#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define int long long
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
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
 
const int MOD = 1e9 + 7;
const int LARGEPRIME = 998244353;
const int INF_INT = 2147483647;
const ll INF_LL = 2 * 1e18;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int dx8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy8[] = {0, 0, -1, 1, -1, 1, -1, 1};
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int cnt(int K) {
    int ans = 0;
    int len = to_string(K).length();
 
    for (int i = 1; i < len; ++i) {
        int count = 9 * pow(10, i - 1);
        ans += count * i;
    }
 
    int rem = K - pow(10, len - 1) + 1;
    ans += rem * len;
 
    return ans;
}
void solve()
{
   long long k;
        cin >> k;
        long long cur = 9, len = 1;
        while (k - cur * len > 0) {
            k -= cur * len;
            cur *= 10;
            len++;
        }
        string s = to_string(cur / 9 + (k - 1) / len);
        long long ans = 0;
        for (int i = 0; i < (k - 1) % len + 1; i++)
            ans += s[i] - '0';
        long long pr_s = 0;
        for (int i = 0; i < s.length(); i++) {
            int curd = s[i] - '0';
            if (curd)
                ans += curd * (len - 1) * cur / 2 + curd * (2 * pr_s + curd - 1) / 2 * cur / 9;
            cur /= 10, len--;
            pr_s += curd;
        }
        cout << ans << '
';
}
 
EYMK
{
    fast;
 
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    int tc; cin>>tc;
    while(tc--) solve();
    return 0;
}