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
 
namespace sol
{
    vector<int> bfs(int u, int n, vector<vector<int>> &g)
    {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[u] = 0;
        q.push(u);
        while (!q.empty())
        {
            int v = q.front(); q.pop();
            for (int to : g[v])
            {
                if (dist[to] == -1)
                {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
        return dist;
    }
    void dp_dfs(int u, vector<vector<int>> &g, vector<int> &dist, vector<int> &dp, vector<bool> &used)
    {
        dp[u] = dist[u];
        used[u] = true;
        for (int v : g[u])
        {
            if (dist[u] < dist[v])
            {
                if (!used[v]) dp_dfs(v, g, dist, dp, used);
                dp[u] = min(dp[u], dp[v]);
            }
            else
            {
                dp[u] = min(dp[u], dist[v]);
            }
        }
    }
    void sol()
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n + 1);
        for (int i = 1; i <= m; i++)
        {
            int u, v; cin >> u >> v;
            g[u].pb(v);
        }
        vector<int> dist = bfs(1, n, g);
        vector<int> ans(n + 1);
        vector<int> dp(n + 1, 0);
        vector<bool> used(n + 1, false);
        dp_dfs(1, g, dist, dp, used);
        for (int i = 1; i <= n; i++) cout << dp[i] << " ";
        cout << endl;
    }
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
    cin >> tc;
    while (tc--)
    {
        sol::sol();
    }
 
    cerr <<endl << (clock() - start) * 1000.0 / CLOCKS_PER_SEC<<' '<<'m'<<'s'<<endl;
 
    return 0;
}