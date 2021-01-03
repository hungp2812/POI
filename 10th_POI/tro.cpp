#include <bits/stdc++.h>

#define MOD 3
#define int long long

using namespace std;

int sC[4][4], fact[4];



vector<int> rep(int n) {
	vector<int> res;
	while (n > 0) res.emplace_back(n % MOD), n /= MOD;
	return res;
}

int power(int x, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1) res = (res * x) % MOD;
		x = (x * x) % MOD;
		n /= 2;
	}
	return res;
}

int inverse(int x) {
	return power(x, MOD - 2);
}

int C(int n, int k) {
	if (n < k) return 0;
	vector<int> repN = rep(n), repK = rep(k);
	int res = 1;
	for (int i = 0; i < (int)repK.size(); i++) (res *= sC[repN[i]][repK[i]]) %= MOD;
	return res;
}

signed main() {
	cout.tie(0), cin.tie(0)->sync_with_stdio(false);
	int t;
	cin >> t;
	
	fact[0] = 1;
	for (int i = 1; i <= MOD; i++) fact[i] = fact[i - 1] * i % MOD;
	
	for (int i = 0; i < MOD; i++)
		for (int j = 0; j < MOD; j++) {
			if (i < j) sC[i][j] = 0;
			else sC[i][j] = fact[i] * inverse(fact[j]) % MOD * inverse(fact[i - j]) % MOD;
		}
		
	while (t--) {
		int n, i;
		cin >> n >> i;
		int res = C(2 * n, i);
		if (i % 2 == 1) res = (3 - res) % 3;
		cout << res << '\n';
	}
}