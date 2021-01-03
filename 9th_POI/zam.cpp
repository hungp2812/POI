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
#define debug(x) cout << #x << " : " << endl << x << endl;
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
const int MAXN = 6e4 + 5 , MAXM = 3e5 + 5;
const int inf = (1<<30)-1; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
//#define int long long

int n, m, s, t, b, par[101][1001], a[101];
bool vis[101][1001];
vector<int> adj[101];

void Solve() {
    cin >> n >> m >> s >> t >> b;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1, x, y; i <= m; i++){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    queue<pii> q;
    vis[s][a[s]] = 1;
    q.push({s, a[s]});
    while(!q.empty()){
        auto [u, c] = q.front(); q.pop();
        for (auto v : adj[u]){
            if (c + a[v] <= b && !vis[v][c + a[v]]){
                vis[v][c + a[v]] = 1;
                par[v][c + a[v]] = u;
                q.push({v, c + a[v]});
            }
        }
    }
    vector<int> ans;
    for (int i = t; b; b -= a[i], i = par[i][b + a[i]])
        ans.pb(i);
    reverse(all(ans));
    for (auto v : ans)
        cout << v << ' ';
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
//    cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

\/-=====>>><<<-------- DEBUG -------->>><<<=====-\/
/\.............................................../\
+====================== INP ======================+

5 6
1 0 3 3
2 1 2
1 1 4 4
2 1 3
2 1 4
2 3 5


+====================== OUT ======================+


+======================*****======================+
\/...............................................\/
/\-=====>>><<<--------= END =-------->>><<<=====-/\

*/