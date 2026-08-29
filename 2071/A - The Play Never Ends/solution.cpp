#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
#define endl "
"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
#define TOISETHIVOI signed main()
 
TOISETHIVOI
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        if(n % 3 == 1 || n == 1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}