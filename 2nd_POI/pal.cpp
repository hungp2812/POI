#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define int long long

#define For(i,a,b) for (int i = a; i <= (b); ++i)
#define For2(i,a,b) for (int i = a; i >= (b); --i)

#define test int _t; cin >> _t; while (_t--)

#define pii pair<int, int>
#define mpii map<int, int>
#define all(a) a.begin(), a.end()
#define pb emplace_back
#define fi first
#define se second
#define mp make_pair
#define sz(a) (int)a.size()

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define INF (int)1e18
#define EPS 1e-9

using namespace std;
using namespace __gnu_pbds;

template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//#define FILEOPEN

const int MAXN = 205;
int dpmin[MAXN], dpmax[MAXN];
int premin[MAXN], premax[MAXN];

bool pal(string s) {
	string p = s;
	reverse(all(p));
	return p == s;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	#ifdef FILEOPEN
		freopen("input.in", "r", stdin);
		freopen("input.out", "w", stdout);
	#endif
	string s;
	cin >> s;
	For(i,0,sz(s)) dpmin[i] = INF, dpmax[i] = -INF;
	dpmin[0] = dpmax[0] = 0;
	for (int i = 2; i <= sz(s); i += 2) {
		for (int j = 0; j < i; j += 2) {
			string p = "";
			For(k,j + 1,i) p += s[k - 1];
			if (pal(p)) {
				if (dpmin[i] > dpmin[j] + 1) {
					dpmin[i] = dpmin[j] + 1;
					premin[i] = j + 1;
				}
				if (dpmax[i] < dpmax[j] + 1) {
					dpmax[i] = dpmax[j] + 1;
					premax[i] = j + 1;
				}
			}
		}
	}
	if (dpmin[sz(s)] > sz(s)) {
		cout << "NIE";
		return 0;
	}
	vector<pii> a;
	int cur = sz(s);
	while (cur != 0) {
		a.pb(mp(premin[cur], cur));
		cur = premin[cur] - 1;
	}
	reverse(all(a));
	for (pii f: a) {
		For(i,f.fi,f.se) cout << s[i - 1];
		cout << " ";
	}
	cout << "\n";
	a.clear();
	cur = sz(s);
	while (cur != 0) {
		a.pb(mp(premax[cur], cur));
		cur = premax[cur] - 1;
	}
	reverse(all(a));
	for (pii f: a) {
		For(i,f.fi,f.se) cout << s[i - 1];
		cout << " ";
	}
	cout << "\n";
}