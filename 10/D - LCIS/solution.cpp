/*__stO_stO_stO_stO_stO_stO_stO_zit_Orz_Orz_Orz_Orz_Orz_Orz_Orz__*/
                      #include<bits/stdc++.h>
                        using namespace std;
                         #define name "zit"
            using ll=long long;const ll MOD2=998244353; 
            #define all(x,y) x.begin()+1, x.begin()+y+1
            using vl=vector<ll>; using pll=pair<ll,ll>;
            const int maxn=5e5+1, MOD=1e9+7;// __   c:|
            #define pb push_back//  zit#6421 <(o )____|
            const long long INF=2*1e18;ll n;//(  ._> /|
            #define All(x) x.begin(),x.end()// `----' |
 
#define debug(x) cerr << #x << " = " << x << '
'
#define el cerr<<'
'
 
vl a(501), b(501);
vector < unordered_map <ll, ll> > pos (501);
vector <vl> v (501);
vector <vl> dp (501, vl (501, 0));
 
void print_ans (ll i, ll j) {
	vl ans;
	for (; i && j ;) {
		debug (i);
		debug (j); 
		ans.pb (a[i]);
		for (auto & k : v[i]) {
			auto it = pos[j].find (a[k]);
			if (it == pos[j].end()) continue;
			if (dp[k][pos[j][a[k]]] + 1 == dp[i][j]) {
				i = k;
				j = pos[j][a[k]];
				break;
			}
		}
	}
 
	for (;ans.size();) {
		cout << ans.back() << " ";
		ans.pop_back();
	}
}
 
void sibidi () {             cin >> n;
        ll m;
        for (ll i = 1; i <= n; ++i) cin >> a[i];
        cin >> m;
        for (ll i = 1; i <= m; ++i) cin >> b[i];
 
 
        for (ll i = 1; i <= n; ++i) {
		v[i].pb (0);
                for (ll j = 1; j < i; ++j) 
                        if (a[j] < a[i]) v[i].pb (j);
	}
        
        for (ll j = 1; j <= m; ++j) {
                pos[j] = pos[j - 1];
		pos[j][0] = max (pos[j][0], 0LL);
                pos[j][b[j]] = j;
        }
 
        ll ans = 0;
        ll besti = 0, bestj = 0;
        for (ll i = 1; i <= n; ++i) {
                for (ll j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				for (auto & k : v[i]) {
					auto it = pos[j].find (a[k]);
					if (it == pos[j].end()) continue;
					dp[i][j] = max (dp[i][j], dp[k][pos[j][a[k]]] + 1);
					
					if (dp[i][j] > ans) {
						ans = dp[i][j];
						besti = i;
						bestj = j;
					}
				}
			}
			else dp[i][j] = 0;
                }
        }        
 
	// for (auto & i : v[5]) debug(i);
	// debug (a[3]);
	// debug (pos[3][a[3]]);
	// el;
	// debug (besti);
	// debug (bestj);
 
	// for (ll i = 1; i <= n; ++i) {
	// 	for (ll j = 1; j <= m; ++j) {
	// 		debug (i);
	// 		debug (j);
	// 		debug (dp[i][j]);
	// 		el;
	// 	}
	// }
 
 
        cout << ans << '
';
	print_ans (besti, bestj);
 
}                          signed main()
                    {if(fopen(name".inp", "r"))
  {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);ll tt=1;		
                            //cin>>tt;
                   while(tt--)sibidi();return 0;}