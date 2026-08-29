/*
========================================================
   Author  : duxp
   Purpose : Competitive Programming
   Note    : Think first. Code once.
   Rule    : Once AC, never touch
   Created at: 2026-01-19
========================================================
*/
#include <bits/stdc++.h>
 
#ifdef __APPLE__
#include <mach/mach.h>
#else
#include <unistd.h>
#endif
 
using namespace std;
 
#define ll long long
#define int long long
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
 
#ifndef ONLINE_JUDGE
    bool __LOCAL__ = true;
#else
    bool __LOCAL__ = false;
#endif
 
#define dbg(x) if (__LOCAL__) cerr << #x << " = " << (x) << '
'
#define dbg2(x, y) if (__LOCAL__) cerr << #x << " = " << (x) \
                                         << ", " << #y << " = " << (y) << '
'
#define dbg3(x, y, z) if (__LOCAL__) cerr << #x << " = " << (x) \
                                            << ", " << #y << " = " << (y) \
                                            << ", " << #z << " = " << (z) << '
'
#define el if (__LOCAL__) cerr << '
'
 
const ll OO = (ll)1e18;
 
#define _______TOISETHIVOI_______ signed main()
#define KILL() exit(0)
#define NAME "duxp"
 
typedef long long lli;
 
 
vector<pair<lli, lli>> a; // (A, B)
lli k;
 
 
lli check(lli val)
{
    lli cnt = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        lli A = a[i].fi;
        lli B = a[i].se;
        if (A < val) continue;
 
        lli f = (A - val + B - 1) / B;
        cnt += f;
        if (cnt > k) return cnt;
    }
    return cnt;
}
 
pair<lli, lli> getSum(lli val)
{
    lli cnt = 0;
    lli sum = 0;
 
    for (int i = 0; i < (int)a.size(); i++)
    {
        lli A = a[i].fi;
        lli B = a[i].se;
        if (A < val) continue;
 
        lli f = (A - val + B - 1) / B;
        cnt += f;
        if (cnt > k) break;
 
        sum += f * (2 * A - (f - 1) * B) / 2;
    }
    return make_pair(cnt, sum);
}
 
 
void solve()
{
    int n;
    cin >> n >> k;
 
    a.clear();
    a.resize(n);
 
    for (int i = 0; i < n; i++) cin >> a[i].fi;
    for (int i = 0; i < n; i++) cin >> a[i].se;
 
    lli l = -1, r = (lli)1e18;
    r += 100;
 
    while (r - l > 1)
    {
        lli mid = (l + r) / 2;
        if (check(mid) > k)
            l = mid;
        else
            r = mid;
    }
 
    pair<lli, lli> res = getSum(r);
    lli ans = res.se + max(0LL, k - res.fi) * r;
 
    cout << ans << endl;
}
 
 
                                _______TOISETHIVOI_______
{
    fast;
 
#ifndef ONLINE_JUDGE
    freopen(NAME ".inp", "r", stdin);
    freopen(NAME ".out", "w", stdout);
#endif
 
    int tc;
    cin >> tc;
    while (tc--)
        solve();
 
#ifndef ONLINE_JUDGE
    cerr << "Done.
";
#endif
 
    KILL();
}
// I LOVE MYSELF