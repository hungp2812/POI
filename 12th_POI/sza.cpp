#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 500005;
int z[MAXN], sizee[MAXN];
vector<int> eq[MAXN];

int nxt[MAXN], lst[MAXN];

signed main() {
	cin.tie(0)->sync_with_stdio(false); cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	z[0] = n;
	for (int i = 0; i < n; i++){
	    sizee[z[i]]++;
	}
	for(int i = 0; i <= n; i++) eq[i].resize(sizee[i]);
//	return 0;
	for (int i = n - 1; i >= 0; i--){
	    sizee[z[i]]--;
	    //cout << i << " " << z[i] << " " << sizee[z[i]] << " " << eq[z[i]].size() << "\n";
	    eq[z[i]][sizee[z[i]]] = i;
	}
	for (int i = 0; i <= n - 1; i++){
	    nxt[i] = i + 1;
	    lst[i] = i - 1;
	}
	lst[0] = 0;
	//nxt[n - 1] = n - 1;
	int mx = 1;
	for (int P = 0; P < n; P++) {
		// cout << P << ' ' << mx << endl;
		if (mx <= P) {
			cout << P << '\n';
			return 0;
		}
		for (int i: eq[P]) {
		    //cout << i << " " << nxt[i] - lst[i] << "\n";
			mx = max(mx, nxt[i] - lst[i]);
			nxt[lst[i]] = nxt[i];
			lst[nxt[i]] = lst[i];
		}
	}
	cout << n << '\n';
}