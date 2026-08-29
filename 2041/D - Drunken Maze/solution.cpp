/*
Author: duxp
"IT WORKED ON MY MACHINE!"
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define int ll
#define ld long double 
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define nall(x) (x).begin(), (x).end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define vpii vector<pii>
#define endl '
'
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, x) memset((a), (x), sizeof((a)))
 
#define _______TOISECOGIAIVOI_______ signed main()
#define KILL() exit(0)
#define NAME "duxp"
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
template <typename T> inline int getbit(T x, int k) { return (x >> k) & 1; }
template <typename T> inline T onbit(T x, int k) { return x | (T(1) << k); }
template <typename T> inline T offbit(T x, int k) { return x & ~(T(1) << k); }
 
const ll OO = 1e18;
const int oo = 1e9;
const int MOD = 1e9 + 7;
const int MAXN = 200005;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
struct state
{
    int x, y, lastDirection, consMove;
};
int n, m;
vector<string> maze;
// d[flattenIndex][lastDirection][consMove]
int d[MAXN][4][4];
inline int getIdx(int r, int c) 
{
    return (r - 1) * m + (c - 1);
}
 
_______TOISECOGIAIVOI_______
{
    fast;
    if (fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    cin>>n>>m;
    maze.resize(n + 1);
    int sx, sy, tx, ty;
    for (int i = 1; i <= n; i++) 
    {
        string row; cin >> row;
        maze[i] = " " + row;
        for (int j = 1; j <= m; j++) 
        {
            if (maze[i][j] == 'S') { sx = i; sy = j; }
            if (maze[i][j] == 'T') { tx = i; ty = j; }
            int idx = getIdx(i,j);
            for(int k = 0; k < 4; k++)
            {
                for(int step = 1; step <= 3; step++) d[idx][k][step] = OO;
            }
        }
    }
    queue<state> q;
    for (int k = 0; k < 4; k++) 
    {
        int nx = sx + dx[k], ny = sy + dy[k];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && maze[nx][ny] != '#') 
        {
            d[getIdx(nx, ny)][k][1] = 1;
            q.push({nx, ny, k, 1});
        }
    }
 
    int res = OO;
 
    while (!q.empty()) 
    {
        state cur = q.front();
        q.pop();
        int curDist = d[getIdx(cur.x, cur.y)][cur.lastDirection][cur.consMove];
        if (cur.x == tx && cur.y == ty) 
        {
            res = min(res, curDist);
            continue; 
        }
        for (int k = 0; k < 4; k++) 
        {
            int nx = cur.x + dx[k], ny = cur.y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m || maze[nx][ny] == '#') continue;
            int nextCons;
            if(k == cur.lastDirection) nextCons = cur.consMove + 1;
            else nextCons = 1;
            if (nextCons <= 3) 
            {
                if (d[getIdx(nx, ny)][k][nextCons] == OO) 
                {
                    d[getIdx(nx, ny)][k][nextCons] = curDist + 1;
                    q.push({nx, ny, k, nextCons});
                }
            }
        }
    }
 
    if (res == OO) cout << -1 << endl;
    else cout << res << endl;
 
    return 0;
}