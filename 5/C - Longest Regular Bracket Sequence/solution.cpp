/*
Author: duxp
Version: 1
Created at: 2025-12-27 19:27
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define TDN signed main()
 
string s;
 
TDN
{
    fast;
    if (fopen("task.inp", "r"))
    {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
 
    cin >> s;
    int n = s.size();
 
    stack<int> st;
    st.push(-1);
 
    int res = 0, ans = 0;
 
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                int len = i - st.top();
                if (len > res)
                {
                    res = len;
                    ans = 1;
                }
                else if (len == res)
                {
                    ans++;
                }
            }
        }
    }
    if (res == 0)
    {
        cout<<"0 1";
        return 0;
    }//haha
 
    cout << res << " " << ans << endl;
}