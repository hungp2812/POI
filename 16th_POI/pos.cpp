/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#include "poslib.h"
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
const int MAXN = 1e4 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
//#define int long long

int n, a, b;
int dp[40 * MAXN]; 
// the maximum range can be asked with current money
// need only log(n) * cost :V

void Solve(){
    inicjuj(&n, &a, &b);
    for (int i = 0; ; i++){
        dp[i] += (i >= a) ? dp[i - a] : 0;
        dp[i] += (i >= b) ? dp[i - b] : 0;
        dp[i] = max(dp[i], 1);
        if (dp[i] >= n){
            // now i is the best
            int l = 1, r = n;
            while(l < r){
                while(i && dp[i - 1] >= r - l + 1) i--;
                if(pytaj('N', l + dp[i - a])){
					r = l + dp[i - a] - 1, i -= a;
				}
				else{
					l = l + dp[i - a], i -= b;
				}
            }
            odpowiedz(l);
            return ;
        }
    }
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    cin >> TC;
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