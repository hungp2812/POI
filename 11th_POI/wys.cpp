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
const int MAXN = 2e5 + 5 , MAXM = 3e5 + 5;
const int inf = (1<<30)-1; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
//#define int long long

int n, st[MAXN << 2], lz[MAXN << 2];

void app(int node, int v){
    st[node] += v;
    lz[node] += v;
}

void push(int node){
    app(node << 1, lz[node]);
    app(node << 1 | 1, lz[node]);
    lz[node] = 0;
}

void upd(int l, int r, int v, int node = 1, int tl = 1, int tr = 2e5){
    if (l > tr || l > r || tl > r) return ;
    if (l <= tl && tr <= r) {
        app(node, v);
        return ;
    }
    int tm = (tl + tr) >> 1;
    push(node);
    upd(l, r, v, left);
    upd(l, r, v, right);
    st[node] = max(st[node << 1], st[node << 1 | 1]);
}

struct sq {
    int l, r, t, v;
    sq(int _l, int _r, int _t, int _v) : l(_l), r(_r), t(_t), v(_v) {}
};

vector<sq> query;

void Solve() {
    cin >> n;
    for (int i = 1, q; i <= n; i++){
        cin >> q;
        vector<pii> a(q + 1);
        for (int i = 0, x; i < q; i++){
            cin >> x;
            if (i & 1){
                // y coordinate 
                a[i].S = a[(i + q - 1) % q].S = x;
            }else{
                // x coordinate 
                a[i].F = a[(i + q - 1) % q].F = x;
            }
        }
        for (int i = 0; i < q; i++){
            if (a[i].S == a[(i + 1) % q].S){
                int v = 1, l = a[i].F, r = a[(i + 1) % q].F;
                if (l > r) swap(l, r), v = -v;
                query.eb(l, r, a[i].S, v);
            }
        }
    }
    vector <int> xx;
    for (auto q : query){
        xx.pb(q.l);
        xx.pb(q.r);
    }
    sort(all(xx));
    xx.resize(unique(all(xx)) - xx.begin());
    for (auto &q : query){
        q.l = lower_bound(all(xx), q.l) - xx.begin() + 1;
        q.r = lower_bound(all(xx), q.r) - xx.begin() + 1;
    }
    sort(all(query), [](const sq & a, const sq & b){
        return a.t < b.t;
    });
    int res = 0;
    for (int i = 0; i < query.size(); ){
        int j = i;
        while(j < query.size() && query[i].t == query[j].t)
            j ++;
        for (int k = i; k < j; k++)
            upd(query[k].l, query[k].r - 1, query[k].v);
        res = max(res, st[1]);
        i = j;
    }
    cout << res;
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