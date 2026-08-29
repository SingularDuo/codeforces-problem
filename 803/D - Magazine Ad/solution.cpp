#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
int k, n = 0;
string s;
bool ok(int w)
{
    int ml = 0;
    int cl = 0;
 
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '-')
        {
            ml = max(ml, cl + 1);
            cl = 0;
        }
        else
        {
            cl++;
        }
    }
    ml = max(ml, cl);
 
    if(ml > w) return false;
    int lc = 1;
    int cw = 0;
 
    int lbp = 0;
 
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '-')
        {
            int sl = i - lbp;
            if(cw + sl > w)
            {
                lc++;
                cw = sl;
            }
            else
            {
                cw += sl;
            }
 
            lbp = i;
 
            if(lc > k) return false;
        }
    }
    int sl = n - lbp;
    if(sl > 0)
    {
        if(cw + sl > w)
        {
            lc++;
        }
    }
    return lc <= k;
}
void solve()
{
    cin>>k;
    cin.ignore();
    getline(cin, s);
    n = s.size();
    s = " " + s;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == ' ')
        {
            s[i] = '-';
        }
    }
    int lo = 1, hi = 1000000, ans = 1e8;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(ok(mid))
        {
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout<<ans<<endl;
}
 
signed main()
{
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
        auto start = clock();
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
 
    cerr <<endl << (clock() - start) * 1000.0 / CLOCKS_PER_SEC<<' '<<'m'<<'s'<<endl;
 
    return 0;
}