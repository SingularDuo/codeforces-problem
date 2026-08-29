#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define int long long
#define EYMK signed main()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define fi first
#define se second
#define each(x) for (auto &i : x)
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
 
const int MOD = 998244353;
const int LARGEPRIME = 998244353;
const int INF_INT = 2147483647;
const ll INF_LL = 2 * 1e18;
const int dx[] = {-1, 1, 0, 0};
#define start_time auto start = clock();
#define cerr_time cerr << endl \
                       << "Time: " << (clock() - start) * 1000.0 / CLOCKS_PER_SEC << " ms
";
const int dy[] = {0, 0, -1, 1};
const int dx8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy8[] = {0, 0, -1, 1, -1, 1, -1, 1};
long long dp[105][2];
void solve()
 
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
 
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
 
        dp[1][0] = 1;
        dp[1][1] = 1;
 
        for (int i = 2; i <= n; i++)
        {
            for (int ngon = 0; ngon < 2; ngon++)
            {
                int x1, y1;
                if (ngon == 0)
                {
                    x1 = a[i - 1];
                    y1 = b[i - 1];
                }
                else
                {
                    x1 = b[i - 1];
                    y1 = a[i - 1];
                }
 
                for (int check = 0; check < 2; check++)
                {
                    int x2, y2;
                    if (check == 0)
                    {
                        x2 = a[i];
                        y2 = b[i];
                    }
                    else
                    {
                        x2 = b[i];
                        y2 = a[i];
                    }
 
                    if (x1 <= x2 && y1 <= y2)
                    {
                        dp[i][check] = (dp[i][check] + dp[i - 1][ngon]) % MOD;
                    }
                }
            }
        }
 
        long long ans = (dp[n][0] + dp[n][1]) % MOD;
        cout << ans << endl;
    }
}
 
EYMK
{
    fast;
 
    if (fopen("task.inp", "r"))
    {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
    solve();
    return 0;
}