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

int dp[55][606], tr[55][606];
int a[606][606], n, k;

int tot(int l, int r){
    return a[r][r] - a[l - 1][r] - a[r][l - 1] + a[l - 1][l - 1];
}

void Solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
        }
    }
    for (int i = 1; i < n; i++){
        dp[1][i] = tot(1, i);
    }
    for (int i = 2; i <= k; i++){
        for (int j = 1; j < n; j++){
            dp[i][j] = inf;
            for (int l = 1; l < j; l++){
                if (dp[i][j] > dp[i - 1][l] + tot(l + 1, j)){
                    dp[i][j] = dp[i - 1][l] + tot(l + 1, j);
                    tr[i][j] = l;
                }
            }
        }
    }
    int res = inf, p = 1;
    for (int i = 1; i < n; i++){
        if (res > dp[k][i] + tot(i + 1, n)){
            res = dp[k][i] + tot(i + 1, n);
            p = i;
        }
    }
    vector<int> ans;
    for (int i = k; i >= 1; i--){
        ans.pb(p);
        p = tr[i][p];
    }
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


+====================== OUT ======================+


+======================*****======================+
\/...............................................\/
/\-=====>>><<<--------= END =-------->>><<<=====-/\

*/

