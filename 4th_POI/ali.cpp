#include <bits/stdc++.h>

using namespace std;

struct wallet {

	int z, s, p;
	wallet() {}
	wallet(int Z, int S, int P): z(Z), s(S), p(P) {}
	wallet operator + (wallet b) {
		return wallet(
			z + b.z,
			s + b.s,
			p + b.p
		);
	}
	bool operator >= (wallet b) {
		return z >= b.z && s >= b.s && p >= b.p;
	}
	bool valid() {
		return z >= 0 && s >= 0 && p >= 0 && z <= 100 && s <= 100 && p <= 100;
	}
	bool operator == (wallet b) const {
		return b.z == z && b.s == s && b.p == p;
	}
};


int vis[105][105][105], dist[105][105][105];

void Solve() {
	memset(vis, 0, sizeof(vis));
	
	int zp, sp, mp, z, s, m;
	cin >> zp >> sp >> mp >> z >> s >> m;
	wallet start(zp, sp, mp), target(z, s, m);
	
	
	int n; cin >> n;
	vector< pair<wallet, wallet> > cnv(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> zp >> sp >> mp >> z >> s >> m;
		cnv[i] = {wallet(-zp, -sp, -mp), wallet(z, s, m)};	
	}
	
	
	queue<wallet> q;
	
	q.push(start);
	vis[start.z][start.s][start.p] = 1;
	dist[start.z][start.s][start.p] = 0;
	int ans = -1;
	
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		if (u >= target) {
			ans = dist[u.z][u.s][u.p];
			break;
		}
		for (int i = 1; i <= n; i++) {
			wallet res = u + cnv[i].first;
			if (res.valid()) {
				res = res + cnv[i].second;
				if (!vis[res.z][res.s][res.p]) {
					vis[res.z][res.s][res.p] = 1;
					dist[res.z][res.s][res.p] = dist[u.z][u.s][u.p] + 1;
					q.push(res);
				}
			} 
		}
	}
	if (ans == -1) cout << "NIE\n";
	else cout << ans << "\n";
}

signed main() {
	int _t; cin >> _t;
	while (_t--) Solve();
}