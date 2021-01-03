#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105; 
int sum[MAXN][(1 << 6)], board[MAXN][4], mx[MAXN][(1 << 6)];

int P[] = {2, 2};
int Q[] = {1, -1};

bool ar[4][4];

bool match(int pre, int bits) {
	bool b = false;
	b |= (pre & (1 << 0)) && (bits & (1 << 4));
	b |= (pre & (1 << 1)) && (bits & (1 << 3));
	b |= (pre & (1 << 1)) && (bits & (1 << 5));
	b |= (pre & (1 << 2)) && (bits & (1 << 4));
	return !b;
}

int count(int a) {
	int cnt = 0;
	for (int i = 0; i < 6; i++) cnt += (bool)(a & (1 << i));
	return cnt;
}

signed main() {
	cout.tie(0), cin.tie(0)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	// cout << n << "-"; for (int i = 1; i <= n; i++) cout << a[i] << ","; cout << '\n';
	// return 0;
	
	memset(mx, -1, sizeof(mx));
	
	for (int i = 1; i <= n; i++)
		board[i][a[i]] = 1;
	
	for (int i = 0; i < 3; i++) board[0][i + 1] = 1;
	
	for (int bits = 0; bits < (1 << 6); bits++) {
		array<vector<bool>, 2> p; p[0].resize(3); p[1].resize(3);
		for (int i = 0; i < 6; i++) 
			if (i <= 2) p[0][i] = bits & (1 << i);
			else p[1][i - 3] = bits & (1 << i);
		bool b = true;
		for (int i = 0; i < 3; i++)
			if (p[1][i] && board[1][i + 1]) b = false;
		
		for (int i = 0; i < 3; i++)
			if (p[0][i] && board[0][i + 1]) b = false;
		
		//sarco
		if (p[0][0] == 1 && p[1][2] == 1) b = false;
		if (p[0][2] == 1 && p[1][2] == 1) b = false;
		
		sum[0][bits] = b;
		if (b) mx[0][bits] = count(bits);
	}
	
	for (int bits = 0; bits < (1 << 6); bits++) {
		array<vector<bool>, 2> p; p[0].resize(3); p[1].resize(3);
		for (int i = 0; i < 6; i++) 
			if (i <= 2) p[0][i] = bits & (1 << i);
			else p[1][i - 3] = bits & (1 << i);
		bool b = true;
		for (int i = 0; i < 3; i++)
			if (p[0][i] && board[1][i + 1]) b = false;
		for (int i = 0; i < 3; i++)
			if (p[1][i] && board[2][i + 1]) b = false;
		
		//sarco
		if (p[0][0] == 1 && p[1][2] == 1) b = false;
		if (p[0][2] == 1 && p[1][0] == 1) b = false;
		
		sum[1][bits] = b;
		if (b) mx[1][bits] = count(bits);
	}
	
	for (int i = 2; i < n; i++) {
		for (int bits = 0; bits < (1 << 6); bits++) {
			
			bool b = false;
			
			b |= (bits & (1 << 0)) && (bits & (1 << 5));
			b |= (bits & (1 << 2)) && (bits & (1 << 3));
			
			if (b) continue;
			
			b = true;
			for (int j = 0; j < 3; j++)
				if (board[i][j + 1] && (bits & (1 << j))) b = false;
				
			
			for (int j = 0; j < 3; j++)
				if (board[i + 1][j + 1] && (bits & (1 << (j + 3)))) b = false;
				
			if (!b) continue;
			
			int midrow = (bits & ((1 << 3) - 1));
			
			
			int new_bits = count(bits >> 3);
			
			for (int pre = 0; pre < (1 << 3); pre++) {
				int prerow = (midrow << 3) + pre;
				
				if (mx[i - 1][prerow] == -1) continue;
				
				if (match(pre, bits)) {
					if (mx[i][bits] < new_bits + mx[i - 1][prerow]) {
						mx[i][bits] = new_bits + mx[i - 1][prerow];
						sum[i][bits] = 0;
					}
					if (mx[i][bits] == new_bits + mx[i - 1][prerow])
						sum[i][bits] += sum[i - 1][prerow];
				}
			
			}
		}
	}
	int ans = -1, res = 0;
	for (int bits = 0; bits < (1 << 6); bits++) {
		if (ans < mx[n - 1][bits]) { 
			ans = mx[n - 1][bits];
			res = 0;
		}
		if (ans == mx[n - 1][bits]) res += sum[n - 1][bits];
	}
	
	cout << ans << ' ' << res << '\n';
}
