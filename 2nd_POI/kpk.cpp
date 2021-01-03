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

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m, brd[101][101];

struct node {
    int x, y, d;
    node(int _x = 0, int _y = 0, int _d = 0) 
        : x(_x), y(_y), d(_d) {
            
    }
    bool valid(){
        return x >= 1 && y >= 1 && x <= n && y <= m && !brd[x][y];
    }
    node nxt(int f){
        return node(x + dx[(d + f) % 4], y + dy[(d + f) % 4], (d + f) % 4);
    }
};
node lst[101][101][4];
int d[101][101][4];

void Solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char c; cin >> c;
            brd[i][j] = c - '0';
        }
    }
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    queue<node> bfs;
    for (int i = 0; i < 4; i++){
        d[sx][sy][i] = 1;
        bfs.emplace(sx, sy, i);
    }
    vector<pii> ans;
    while(!bfs.empty()){
        node u = bfs.front(); bfs.pop();
        // cout << u.x << ' ' << u.y << ' ' << u.d << endl;
        if (u.x == ex && u.y == ey){
            ans.eb(u.x, u.y);
            while(u.x != sx || u.y != sy){
                u = lst[u.x][u.y][u.d];
                ans.eb(u.x, u.y);
            }
            reverse(all(ans));
            cout << ans.size() << endl;
            for (auto [x, y] : ans){
                cout << x << ' ' << y << endl;
            }
            return;
        }
        for (int f = 0; f < 2; f++){
            node v = u.nxt(f);
            if (v.valid() && !d[v.x][v.y][v.d]){
                d[v.x][v.y][v.d] = d[u.x][u.y][u.d] + 1;
                lst[v.x][v.y][v.d] = u;
                bfs.push(v);
            }
        }
    }
    Ptest("NIE");
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