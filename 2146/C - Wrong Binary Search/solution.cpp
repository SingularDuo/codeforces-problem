#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
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
 
const int MOD = 1e9 + 7;
const int LARGEPRIME = 998244353;
const int INF_INT = 2147483647;
const ll INF_LL = 2 * 1e18;
 
template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
 
template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}
 
 
bool ze(const string &s)
{
    int n = s.size();
    int i = 0;
    while (i < n)
    {
        if (s[i] == '1')
        {
            i++;
            continue;
        }
        int start = i;
        while (i < n && s[i] == '0')
            i++;
        int length = i - start;
        if (length == 1)
            return true;
    }
    return false;
}
 
vector<int> build(const string &s)
{
    int n = s.size();
    vector<int> p(n + 1);
    int i = 0;
 
    while (i < n)
    {
        if (s[i] == '1')
        {
            p[i + 1] = i + 1;
            i++;
        }
        else
        {
            int l = i;
            while (i < n && s[i] == '0') i++;
            
            int r = i - 1;
 
            for (int j = l; j < r; j++)
            {
                p[j + 1] = j + 2;
            }
            p[r + 1] = l + 1;
        }
    }
 
    return p;
}
 
 
void outp(const vector<int> &p)
{
    for (int i = 1; i < p.size(); i++)
    {
        cout << p[i] << " ";
    }
    cout << "
";
}
 
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    if (ze(s))
    {
        cout << "NO
";
        return;
    }
 
    vector<int> p = build(s);
 
    cout << "YES
";
    outp(p);
}
 
 
EYMK
{
    fast;
 
    if (fopen("task.inp", "r"))
    {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
 
    return 0;
}