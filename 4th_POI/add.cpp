#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
int a[MAXN];

bool check(int p) {
	bitset<10001> s;
	s[0] = 1;
	set<int> f;
	
	for (int i = 1; i <= p; i++) {
		f.insert(a[i]);
		for (int j = a[i]; j <= a[p]; j += a[i]) 
			if (s[j] == 0) s |= (s << a[i]);
	}
	
	for (int i = 1; i <= a[p]; i++)
		if (s[i] == 1 && !f.count(i)) return false;
	
	return true;
}

signed main() {
	cout.tie(0), cin.tie(0)->sync_with_stdio(0); 
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	int l = 1, r = n;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	
	int p = 0;
	if (check(l)) p = l;
	if (check(r)) p = max(p, r);
	
	cout << a[p] << '\n';
	
	bitset<10001> s; s[0] = 1;
	for (int i = 1; i <= p; i++) {
		if (s[a[i]] == 0) cout << a[i] << '\n';
		for (int j = a[i]; j <= a[p]; j += a[i]) 
			if (s[j] == 0) s |= (s << a[i]);
	}
}