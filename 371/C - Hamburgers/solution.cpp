#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long`
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
const int INF_LL = 2 * 1e18;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int dx8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy8[] = {0, 0, -1, 1, -1, 1, -1, 1};
string s;
int totalbr = 0, totalsau = 0, totalche = 0;
int kitchen[4], shop[4], m;
bool ok(int burger)
{
    int bread = kitchen[1], sau = kitchen[2], che = kitchen[3];
    int needbr = totalbr * burger, needsau = totalsau * burger, needche = totalche * burger;
    int total_money =  max(needbr - bread, 1LL * 0) * shop[1] + max(needsau - sau, 1LL * 0) * shop[2] + max(needche - che, 1LL * 0) * shop[3];
    return total_money <= m;
 
}
void solve()
{
    cin>>s;
    for(int i = 1; i <= 3; i++) cin>>kitchen[i];
    for(int i = 1; i <= 3; i++)cin>>shop[i];
    cin>>m;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'B')totalbr++;
        else if(s[i] == 'S')totalsau++;
        else totalche++;
    }
    int l = 0, r = 10000000000000, ans = 0;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(ok(mid))
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout<<ans;
}
 
EYMK
{
    fast;
 
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
    solve();
    return 0;
}