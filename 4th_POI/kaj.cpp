#include <bits/stdc++.h>
 
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
#define INF 2147483647
#define EPS 1e-9
 
//#define FILEOPEN
 
using namespace std;
 
multiset<int> a;
 
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	#ifdef FILEOPEN
		freopen("input.in", "r", stdin);
		freopen("input.out", "w", stdout);
	#endif
	int n, x;
	cin >> x >> n;
	For(i,1,n) {
		int p;
		cin >> p;
		a.insert(-p);
	}	
	int g = 0;
	while (!a.empty()) {
		int f = *(a.begin()); f = -f;
		a.erase(a.begin());
		g++;
		f = f - x;
		auto p = a.lower_bound(f);
		if (p != a.end()) {
			a.erase(p);
		}
	}
	cout << g;
}
