#include <bits/stdc++.h>

using namespace std;

signed main() {
	cout.tie(0), cin.tie(0)->sync_with_stdio(false);
	int n;
	cin >> n; vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.end());
	int sum = 0;
	for (int i = 1; i <= n / 2; i++) 	
		sum += a[n - i + 1] - a[i];
	
	for (int i = 1; i <= n; i++) sum += a[i];
	cout << sum << '\n';
}