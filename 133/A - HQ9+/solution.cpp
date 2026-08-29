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
 
void solve()
{
    string s; cin>>s;
    bool h = false, q = false, nine = false, plus = false;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'H') h = true;
        if(s[i] == 'Q') q = true;
        if(s[i] == '9') nine = true;
    }
    if(h || q || nine || plus) cout<<"YES";
    else cout<<"NO";
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