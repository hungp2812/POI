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

int st[MAXN << 2];
int lz[MAXN << 2], q;
int n, m;

void add(int val, int node, int tl, int tr){
    st[node] += val;
    lz[node] += val;
}

void push(int node, int tl, int tr){
    int tm = (tl + tr) >> 1;
    add(lz[node], left);
    add(lz[node], right);
    lz[node] = 0;
}

int join(int x, int y){
    return max(x, y);
}

// void build(int node = 1, int tl = 1, int tr = n){
//     if (tl == tr){
//         st[node] = 0;
//         lz[node] = 0;
//         return ;
//     }
//     int tm = (tl + tr) >> 1;
//     build(left); build(right);
//     st[node] = join(st[node << 1], st[node << 1 | 1]);
// }

void upd(int l, int r, int val, int node = 1, int tl = 1, int tr = n){
    if (l > r || tl > r || l > tr)
        return ;
    if (l <= tl && tr <= r){
        add(val, node, tl, tr);
        return ;
    }
    push(node, tl, tr);
    int tm = (tl + tr) >> 1;
    upd(l, r, val, left);
    upd(l, r, val, right);
    st[node] = join(st[node << 1], st[node << 1 | 1]);
}

int query(int l, int r, int node = 1, int tl = 1, int tr = n){
    if (tl > r || l > tr || l > r) return -inf;
    if (l <= tl && tr <= r) return st[node];
    push(node, tl, tr);
    int tm = (tl + tr) >> 1;
    return join(query(l, r, left),
                query(l, r, right));
    // if (tl == tr){
    //     return (st[node] > 0 ? tl : 0);
    // }
    // push(node, tl, tr);
    // int tm = (tl + tr) >> 1;
    // if (st[node << 1 | 1] > 0){
    //     return query(right);
    // }else if (st[node << 1] > 0){
    //     return query(left);
    // }else{
    //     return -1;
    // }
}

void Solve() {
    cin >> n >> m >> q;
    n --;
//    build();
    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        if (query(l, r - 1) + x <= m){
            cout << "T\n";
            upd(l, r - 1, x);
        }else{
            cout << "N\n";
        }
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