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
const int MAXN = 2e5 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
#define int long long

struct edge {
    int s, t, c, dis;
};

int n, m, dis[404][404][27]; // 0 = '?', 1 = 'a', 2 = 'b' ...
bool vis[404][404][27];
int lst[404][404][27];
pii par[404][404];
char val[404][404];

vector<int> adj[404][27], radj[404][27];

void print(int s, int t){
    if (vis[s][t][0] == 0){
        Ptest(-1);
    }
    cout << dis[s][t][0] << ' ';
    string p;
    while(dis[s][t][0] > 1){
        p += (char) (par[s][t].S - 1 + 'a');
        s = par[s][t].F;
        t = lst[s][t][p.back() + 1 - 'a'];
    }
    cout << p;
    reverse(all(p));
    if (s != t) cout << val[s][t];
    cout << p << endl;
}

queue<edge> q;

void Solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        q.push({i, i, 0, 0});
        vis[i][i][0] = 1;
    }
    for (int i = 1, u, v; i <= m; i++){
        char x; cin >> u >> v >> x;
        int xx = x - 'a' + 1;
        adj[u][xx].pb(v);
        radj[v][xx].pb(u);
        val[u][v] = x;
        if (!vis[u][v][0]){
            q.push({u, v, 0, 1});
            vis[u][v][0] = 1;
            dis[u][v][0] = 1;
        }
    }
    while(!q.empty()){
        auto xx = q.front(); q.pop();
        if (!xx.c){
            for (int c = 1; c <= 26; c++){
                for (auto nxt : adj[xx.t][c]){
                    if (!vis[xx.s][nxt][c]){
                        vis[xx.s][nxt][c] = 1;
                        lst[xx.s][nxt][c] = xx.t;
                        q.push({xx.s, nxt, c, dis[xx.s][nxt][c] = xx.dis + 1});
                    }
                }
            }
            continue;
        }
        for (auto nxt : radj[xx.s][xx.c]){
            if (!vis[nxt][xx.t][0]){
                vis[nxt][xx.t][0] = 1;
                par[nxt][xx.t] = {xx.s, xx.c};
                q.push({nxt, xx.t, 0, dis[nxt][xx.t][0] = xx.dis + 1});
            }
        }
    }
    int q, l, r;
    cin >> q >> l;
    for (int i = 1; i < q; i++){
        cin >> r;
        print(l, r);
        l = r;
    }
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


+====================== OUT ======================+


+======================*****======================+
\/...............................................\/
/\-=====>>><<<--------= END =-------->>><<<=====-/\

*/