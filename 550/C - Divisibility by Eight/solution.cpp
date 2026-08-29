#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define all(x) x.begin() + 1, x.end()
#define nall(x) x.begin(), x.end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, x) memset(a, x, sizeof(a))
 
#define trailingzero(x) __builtin_ctzll(x)
#define cntbit1(x) __builtin_popcountll(x)
#define leadingzero(x) __builtin_clzll(x)
 
#define _______TOISETHIVOI_______ signed main()
#define KILL() exit(0)
#define NAME "duxp"
 
const ll OO = 1e18;
const int oo = 1e9;
 
                                _______TOISETHIVOI_______
{
    fast;
    if (FILE *f = fopen(NAME ".inp", "r")) {
        fclose(f);
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
 
    string s; 
    cin >> s;
    int n = s.size();
 
    // dp[i][r]: xét i ký tự đầu, có subsequence mod 8 = r
    vector<vi> dp(n + 1, vi(8, 0));
    vector<vector<int>> pre_r(n + 1, vector<int>(8, -1));
    vector<vector<int>> take(n + 1, vector<int>(8, 0)); 
 
    for (int i = 1; i <= n; i++) {
        int d = s[i - 1] - '0';
        for (int r = 0; r < 8; r++) {
            if (dp[i - 1][r] && !dp[i][r]) {
                dp[i][r] = 1;
                pre_r[i][r] = r;
                take[i][r] = 0;
            }
        }
        if (!dp[i][d % 8]) {
            dp[i][d % 8] = 1;
            pre_r[i][d % 8] = -1; 
            take[i][d % 8] = 1;
        }
        for (int r = 0; r < 8; r++) {
            if (dp[i - 1][r]) {
                int nr = (r * 10 + d) % 8;
                if (!dp[i][nr]) {
                    dp[i][nr] = 1;
                    pre_r[i][nr] = r;
                    take[i][nr] = 1;
                }
            }
        }
    }
 
    int pos = -1;
    for (int i = 1; i <= n; i++) {
        if (dp[i][0]) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "NO";
        KILL();
    }
    string ans = "";
    int r = 0, i = pos;
    while (i > 0) {
        if (take[i][r]) {
            ans.pb(s[i - 1]);
            int pr = pre_r[i][r];
            if (pr == -1) break;
            r = pr;
        }
        i--;
    }
 
    reverse(ans.begin(), ans.end());
    cout << "YES
" << ans;
    KILL();
}