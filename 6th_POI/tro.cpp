/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)        
bool endline = false;
template<class T>
istream& operator >> (istream& inp, vector<T>& v){
    for (auto& it : v) inp >> it;
    return inp;
}
template<class T>
ostream& operator << (ostream& out, vector<T>& v){
    for (auto& it : v) out << it << (endline ? "\n" : " ");
    return out;
}
template<class T, class U>
istream& operator >> (istream& inp, pair<T, U>& v){
    inp >> v.F >> v.S;
    return inp;
}
template<class T, class U>
ostream& operator << (ostream& out, pair<T, U>& v){
    out << v.F << ' ' << v.S;
    return out;
}
#define debug(x)            cout << #x << " : " << endl << x << endl;
#define Ptest(x)            return cout << x << endl, (void) 0;
// geometry calculate
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9 + 7;
const int MAXN = 1e5 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
//#define int long long

int id = 1, n;
string s;
int dp_min[MAXN][3];
int dp_max[MAXN][3];
int adj[MAXN][2];

void build(int p){
    int sz = s[id++] - '0';
    for (int i = 0; i < sz; i++){
        adj[p][i] = id;
        build(id);
    }
}

int dfs_min(int r, int c){
    if (r == 0) return 0;
    if (dp_min[r][c] != -1)
        return dp_min[r][c];
    int res = c == 2;
    if (c == 0) res += min(dfs_min(adj[r][0], 1) + dfs_min(adj[r][1], 2), 
                            dfs_min(adj[r][0], 2) + dfs_min(adj[r][1], 1));
    if (c == 1) res += min(dfs_min(adj[r][0], 0) + dfs_min(adj[r][1], 2), 
                            dfs_min(adj[r][0], 2) + dfs_min(adj[r][1], 0));
    if (c == 2) res += min(dfs_min(adj[r][0], 1) + dfs_min(adj[r][1], 0), 
                            dfs_min(adj[r][0], 0) + dfs_min(adj[r][1], 1));
    return dp_min[r][c] = res;
}

int dfs_max(int r, int c){
    if (r == 0) return 0;
    if (dp_max[r][c] != -1)
        return dp_max[r][c];
    int res = c == 2;
    if (c == 0) res += max(dfs_max(adj[r][0], 1) + dfs_max(adj[r][1], 2), 
                            dfs_max(adj[r][0], 2) + dfs_max(adj[r][1], 1));
    if (c == 1) res += max(dfs_max(adj[r][0], 0) + dfs_max(adj[r][1], 2), 
                            dfs_max(adj[r][0], 2) + dfs_max(adj[r][1], 0));
    if (c == 2) res += max(dfs_max(adj[r][0], 1) + dfs_max(adj[r][1], 0), 
                            dfs_max(adj[r][0], 0) + dfs_max(adj[r][1], 1));
    return dp_max[r][c] = res;
}

void Solve(){
    cin >> s;
    n = s.length();
    s = ' ' + s;
    build(1);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            dp_min[i][j] = dp_max[i][j] = -1;
    
    int mn = min({dfs_min(1, 0), dfs_min(1, 1), dfs_min(1, 2)});
    int mx = max({dfs_max(1, 0), dfs_max(1, 1), dfs_max(1, 2)});
    cout << mx << ' ' << mn;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    //cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*
./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\

+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.
*/