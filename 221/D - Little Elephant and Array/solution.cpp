/*                                     
							        _.-- ,.--.
							      .'   .'     /
							       @       |'..--------._
							     /      \._/              '.
							    /  .-.-                     \
							   (  /    \                     \
							   \\      '.                  | #
							    \\       \   -.           /
							     :\       |    )._____.'   \
							      "       |   /  \  |  \    )
							              |   |./'  :__ \.-'
							              '--'         
                                       ...-###########+.. ..                                        
                                      .=##############%###..                                        
                                    .=#############%########..                                      
                                 ...#########################:..                                    
                                  .*##-.....#########-....:###.                                     
                                 .-##........#######........=#*.                                    
                                 .*#...%%--:.:#####+..%%:+:..*#.                                    
                                 .##...+%%@...=----:..+%%%...=#.                                    
                                 .*%:......-====------.......*#..                                   
                                  :##:.....=+===----==-.....=#*.                                    
                                 ..*##::.....==++===:.....:*##:.                                    
                                 ..%%#%*:::.....=:.....::=#####. .                                  
                                 .#%%#%%%%*:::::::::::=########*...                                 
                              ...##%#%%#%+.............:########+.                                  
                              ..#%%%#%#*.................-#######:.                                 
                           ....##%%%%#=....................%#####%=..                               
                          ..:%%%%%%%%-......................######%%+. .                            
                         ..##%%%%%%%+........................%####%%%#-.                            
                        .+###%%%%%%#.........................:%%%#%%%###....                        
                      ..%##%%%%%%%%:..........................*%%###%%#%#=.  .                      
                     .-##%%%%%%%%%*............................%%%%%%%%%###...                      
                   ..=#%%%%%%%%%%%:............................#%%%%%%%%%###...                     
                 ...+###%%%%%%%%%%.............................=%%%%%%%%%%%%#.                      
                 ..=##%%%%%%%%%%%#..............................%%%%%%%%%%%%%#....                  
                 .:%##%%%%%-#%%%%*..............................%%%%%.*%%%%%#%*...                  
                 .##%%%%%-..*%%%%*..............................%%%%%...%%%%%%#:.                   
               ..+#%%%%*... +%%%%#.............................:%%%%%.. .:%%%%##.                   
               ..#%%%%....  :%%%%#.............................-%%%%*.    .#%%%%:                   
               ..%%%-..... ..%%%%%:............................*%%%%:   .....%%#+.                  
               ..-...   .. ..+%%%%=:..........................:%%%%#.   .......-.                   
                            ..%%%%%::........................:=%%%%-.                               
                             .:%%%%=:::....................:::%%%%+...                              
                              .:%%%%:::::...............:::::#%%%*..                                
                              ...%%%%-::::::::::::::::::::::#%%%=..                                 
                              ....+%%%%=::::::::::::::::::*%%%%......                               
                         ...........+%%%%%%#=:::::::-+#%%%%%#:............                          
                        .......:-======+#%%%%%%%%%%%%%%%%*=-=====:...........                       
                      .........:-============+-:::-+============-:...........                       
                      ...........:-==-====+=:.......:======--==-.............                       
                           ..............................................                           
                                 ................................          
                        	AUTHOR: KDUCKP -- EMAIL: ducphatkieu@gmail.com  
                        	VERSION: 1.0 - NOT UPDATED ANYTHING
*/
 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<pii>;
using vvi = vector<vi>;
 
#define endl "
"
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define EACH(x, a) for (auto& x : a)
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define YESNO(x) cout << ((x) ? "YES
" : "NO
")
#define bitcount(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)
#define lb lower_bound
#define ub upper_bound
#define __TOISETHIVOI__ int32_t main()
#define vec2d(type, name, r, c, val) vector<vector<type>> name((r), vector<type>((c), (val)))
#define vec3d(type, name, x, y, z, val) vector<vector<vector<type>>> name((x), vector<vector<type>>((y), vector<type>((z), (val))))
 
const int MAX_A = 1e6 + 5;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const ll INF = 2e18;
const int N = 5e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;
const int MAX_VAL = 1e8;
 
struct Query {
    int l, r, idx;
    bool operator<(const Query& other) const {
        int block_size = sqrt(N);
        if (l / block_size != other.l / block_size)
            return l / block_size < other.l / block_size;
        return r < other.r;
    }
};
 
int a[N], cnt[N];
int res[N]; 
int valid_count = 0; 
vector<int> real_val; 
 
void add(int x) {
    if (cnt[x] == real_val[x]) valid_count--;
    cnt[x]++;
    if (cnt[x] == real_val[x]) valid_count++;
}
 
void remove(int x) {
    if (cnt[x] == real_val[x]) valid_count--;
    cnt[x]--;
    if (cnt[x] == real_val[x]) valid_count++;
}
 
 
__TOISETHIVOI__ {
    fast;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
 
    vi b(a, a + n);         
    sort(all(b));
    b.erase(unique(all(b)), b.end());
 
    for (int i = 0; i < n; i++) {
        a[i] = lb(all(b), a[i]) - b.begin();
    }
 
    real_val = b;
 
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].idx = i;
    }
 
    sort(all(queries));
    int cur_l = 0, cur_r = -1;
    for (const auto& q : queries) {
        while (cur_r < q.r) add(a[++cur_r]);
        while (cur_l > q.l) add(a[--cur_l]);
        while (cur_r > q.r) remove(a[cur_r--]);
        while (cur_l < q.l) remove(a[cur_l++]);
        res[q.idx] = valid_count;
    }
 
    for (int i = 0; i < q; i++) cout << res[i] << "
";
    return 0;
}
//JJJ