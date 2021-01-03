#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

void sieve(int m) {
	vector<int> prime(m + 1, 0);
	for (int i = 2; i <= m; i++) prime[i] = 1;
	for (int i = 2; i <= sqrt(m); i++)
		if (prime[i])
			for (int j = i * i; j <= m; j += i) 
				prime[j] = 0;
	for (int i = 1; i <= m; i++)
		if (prime[i]) primes.emplace_back(i);
}

signed main() {
	cout.tie(0), cin.tie(0)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	sieve(3e6);
	
	// Take 50 first primes
	// vector<vector<bool>> dp(168, vector<bool>(1001, 0));
	// vector<vector<int>> pre(168, vector<int>(1001, 0));
	
	set<int, greater<int>> dp[1001];
	
	vector<int> sel(169);
	for (int i = 1; i < 168; i++) sel[i] = primes[i];
	
	for (int i = 1; i < 168; i++)
		dp[sel[i]].insert(sel[i]);
	
	for (int i = 1; i < 168; i++) {
		for (int j = 1; j <= 1000; j++) {
			if (dp[j].size() > 0) continue;
			if (j >= sel[i] && dp[j - sel[i]].size() > 0 && dp[j - sel[i]].find(sel[i]) == dp[j - sel[i]].end()) {
				dp[j] = dp[j - sel[i]];
				dp[j].insert(sel[i]);
			}
		} 
	}
	
	reverse(primes.begin(), primes.end());
	
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a <= 1000) {
			cout << dp[a].size() << '\n';
			vector<int> res;
			for (int i: dp[a]) res.push_back(i);
			reverse(res.begin(), res.end());
			for (int i: res) cout << i << ' '; cout << '\n';
			continue;
		}
		vector<int> res;
		for (int i: primes) {
			if (a > i && (a - i > 1000 || dp[a - i].size() > 0)) {
				a -= i;
				res.emplace_back(i);
			}  
			else if (a == i) {
				a -= i;
				res.emplace_back(i);
				break;
			}
		}
		if (a > 0) {
			cout << a << endl;
			for (int i: dp[a]) res.emplace_back(i);
		}
		reverse(res.begin(), res.end());
		cout << res.size() << '\n';
		for (int i: res) cout << i << ' '; cout << '\n';
	}
}