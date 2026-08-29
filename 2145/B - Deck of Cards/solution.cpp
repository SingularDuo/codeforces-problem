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
 
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int N = 1e5;
const int MAXA = 1e9;
const int INF = 1e9; // change to 1e18 if using long long 
void solve()
{
    int n, k; 
    cin >> n >> k;
    string s; 
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for(char c: s)
    {
        cnt0 += (c == '0') ? 1 : 0;
        cnt1 += (c == '1') ? 1 : 0;
    }
    vector<char> res(n, '?');
    for(int i = 0; i < cnt0; i++)
    {
        res[i] = '-';
    }
    for (int i = n - 1; i >= max(0, n - cnt1); i--) res[i] = '-';
 
    int rem = k - cnt0 - cnt1; // thao tac con lai
    int unmarked = n - cnt0 - cnt1; // so bai chx dc gan res
    if(unmarked > 0 && unmarked == rem)
    {
        for (int i = cnt0; i < n - cnt1; i++) res[i] = '-';
 
    }
    else if(unmarked > rem)
    {
        int st = max(0, cnt0 + rem);
        int en = min(n - 1, n - cnt1 - rem - 1);
        for (int i = st; i <= en && i < n; i++) res[i] = '+';
 
    }
    for(int i= 0; i < n; i++) cout<<res[i];
    cout<<endl;
    
    
}
 
signed main()
{
    fast;
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
 
    return 0;
}
// TDN LOVER