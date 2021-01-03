#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205, MAXM = 20005;

int b[MAXN], c[MAXN];
int dp[MAXN][MAXM], pre[MAXN][MAXM];

struct obj {
	int val, id;
	obj() {}
	obj(int VAL, int ID): val(VAL), id(ID) {}
};

//SARCO Device
signed main() {
	cout.tie(0), cin.tie(0)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	
	int sum;
	cin >> sum;
	
	// -> Take k of i-th items
	// dp[i][j] = dp[i][d * b[i] + mod]
	//          = min dp[i - 1][d * b[i] + mod - k * b[i]] + k
	//          = min (dp[i - 1][(d - k) * b[i] + mod] - (d - k)) + d
	//        <!> 0 <= k <= c[i] -> d - k >= d - c[i]     
	//            
	
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int mod = 0; mod < b[i]; mod++) {
			deque<obj> dq;
			for (int d = 0; d * b[i] + mod <= sum; d++) {
				
				// Insert dp[i - 1][d * b[i] + mod] - d
				int val = dp[i - 1][d * b[i] + mod] - d;
				while (dq.size() > 0 && dq.back().val > val) dq.pop_back();
				dq.push_back(obj(val, d));				

				// Remove d - k < d - c[i]
				if (dq.front().id < d - c[i]) dq.pop_front();
				
				dp[i][d * b[i] + mod] = dq.front().val + d;			
				pre[i][d * b[i] + mod] = dq.front().id * b[i] + mod;
											
				/* Naive
				for (int k = 0; k <= c[i]; k++) 
					if ((d - k) * b[i] + mod >= 0)
						dp[i][d * b[i] + mod] = min(dp[i][d * b[i] + mod], dp[i - 1][(d - k) * b[i] + mod] + k);
				*/
			}
		}
	}
	
	cout << dp[n][sum] << '\n';
	
	vector<int> ans(n + 1);
	
	int cur = sum, rem = n;
	while (cur > 0) {
		int p = pre[rem][cur];
		ans[rem] = (cur - p) / b[rem];
		cur = p;
		rem--;
	}
	
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}