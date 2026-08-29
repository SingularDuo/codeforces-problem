#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define KING_PHAT int main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '
'
 
KING_PHAT
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;  
        cin>>n;
        ll res = (n/15)*3 + max(0LL, min(3LL, (n % 15) + 1));
        cout << res << endl;
    }
}