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
const int MAXN = 1e5 + 6 , MAXM = 5e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

int n, m, cnt, P[MAXN], sz[MAXN];
vector<pii> edge[MAXN];

int find(int u){
    return P[u] = (P[u] == u ? u : find(P[u]));
}

void join(int u, int v){
    u = find(u), v = find(v);
    if (u != v) P[v] = u, sz[u] += sz[v]; 
}

void addEdge(int u, int v){
    edge[u].eb(v, cnt ++);
    edge[v].eb(u, cnt ++);
}

void Solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        addEdge(i, (i + 1) % n);
        
    for (int i = 0, u, v; i < m; i++){
        cin >> u >> v;
        addEdge(u - 1, v - 1);
    }
    
    for (int i = 0; i < cnt; i++)
        P[i] = i, sz[i] = 1;
    
    for (int i = 0; i < n; i++){
        sort(all(edge[i]), [&](const pii &a, const pii &b){
            return ((a.F - i + n) % n) < ((b.F - i + n) % n);
        });
        for (int j = 0; j < edge[i].size(); j++){
            join(edge[i][j].S, edge[i][(j + 1) % edge[i].size()].S ^ 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < cnt; i++){
        if (sz[find(i)] == n) continue;
        ans = max(ans, sz[find(i)]);
    }
    if (!ans) ans = n;
    cout << ans << endl;
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

7 8
1 2
2 3
2 4
3 4
3 5
5 6
6 7
5 7

+====================== OUT ======================+


+======================*****======================+
\/...............................................\/
/\-=====>>><<<--------= END =-------->>><<<=====-/\

*/