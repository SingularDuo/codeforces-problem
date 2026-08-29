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
 
#define int long long
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
//#define __TOISETHIVOI__ int32_t main(
#define vec2d(type, name, r, c, val) vector<vector<type>> name((r), vector<type>((c), (val)))
#define vec3d(type, name, x, y, z, val) vector<vector<vector<type>>> name((x), vector<vector<type>>((y), vector<type>((z), (val))))
 
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const ll INF = 2e18;
const int N = 2e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;
 
vi a;
int stgcd[N * 4];
map<int, vi> pos;
 
 
void build_gcd(int id, int l, int r, const vi &a) {
    if (l == r) {
        stgcd[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build_gcd(id * 2, l, mid, a);
    build_gcd(id * 2 + 1, mid + 1, r, a);
    stgcd[id] = __gcd(stgcd[id * 2], stgcd[id * 2 + 1]);
}
 
int get_gcd(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return stgcd[id];
    int mid = (l + r) / 2;
    return __gcd(
        get_gcd(id * 2, l, mid, u, v),
        get_gcd(id * 2 + 1, mid + 1, r, u, v)
    );
}
 
int count_equal(int g, int l, int r, const map<int, int> &val2id, const vector<vi> &pos) {
    auto it = val2id.find(g);
    if (it == val2id.end()) return 0;
    int id = it->second;
    const vi &vec = pos[id];
    return upper_bound(all(vec), r) - lower_bound(all(vec), l);
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n; cin >> n;
    a.resize(n + 1);
 
    set<int> unique_vals;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        unique_vals.insert(a[i]);
    }
    map<int, int> val2id;
    int idx = 0;
    for (int x : unique_vals) val2id[x] = idx++;
 
    vector<vi> pos(idx); 
    for (int i = 1; i <= n; i++) {
        int id = val2id[a[i]];
        pos[id].push_back(i);
    }
 
    build_gcd(1, 1, n, a);
 
    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
 
        int g = get_gcd(1, 1, n, l, r);
        int cnt = count_equal(g, l, r, val2id, pos);
 
        cout << (r - l + 1 - cnt) << '
';
    }
    //sss
    return 0;
}