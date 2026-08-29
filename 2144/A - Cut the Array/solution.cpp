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
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
 
const int MOD = 1e9 + 7;
const int LARGEPRIME = 998244353;
const int INF_INT = 2147483647;
const ll INF_LL = 2 * 1e18;
const int dx[] = {-1, 1, 0, 0};
#define start_time auto start = clock();
#define cerr_time cerr <<endl<< "Time: " << (clock() - start) * 1000.0 / CLOCKS_PER_SEC << " ms
";
const int dy[] = {0, 0, -1, 1};
const int dx8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy8[] = {0, 0, -1, 1, -1, 1, -1, 1};
 
void solve()
{
 
}
 
EYMK
{
    int t;
     cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int a[45];
        a[0] = 0;
 
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] = (a[i - 1] + a[i]) % 3;
        }
 
        bool found = false;
        for (int l = 1; l < n && !found; l++)
        {
            for (int r = l + 1; r < n && !found; r++)
            {
                int s1 = a[l];
                int s2 = (a[r] - a[l] + 3) % 3;
                int s3 = (a[n] - a[r] + 3) % 3;
 
                if ((s1 == s2 && s2 == s3) || (s1 != s2 && s2 != s3 && s1 != s3))
                {
                    cout << l << " " << r << "
";
                    found = true;
                }
            }
        }
        if (!found) cout << "0 0
";
    }
}