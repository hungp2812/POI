#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> a(n + 1);
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
//		double nx = (x - y) / sqrt(2); //nx = cos(45) x - sin(45) y
//		double ny = (x + y) / sqrt(2); //ny = sin(45) x + cos(45) y
		
//		Actually let's multiply nx and ny by sqrt(2)
		int nx = x - y;
		int ny = x + y;
		a[i] = {nx, ny};
	}
//	for (int i = 1; i <= n; i++) cout << a[i].first << ' ' << a[i].second << '\n';
	set<int> res;
	sort(a.begin() + 1, a.end());
	for (int i = 1; i <= n; i++) {
		auto f = res.upper_bound(a[i].second);
		if (f != res.begin()) res.erase(prev(f));
		res.insert(a[i].second);
	}	
	cout << res.size();
}