#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 3005, INF = (int)2e18;

int n, m, a, b;
vector<int> path[MAXN];
int cut[MAXN], vis[MAXN], tin[MAXN], low[MAXN], dista[MAXN], distb[MAXN];
int tin_num = 0;

void dfs(int u, int pre) {
	vis[u] = 1; tin[u] = low[u] = ++tin_num; int cnt = 0;
	for (int v: path[u]) {
		if (v == pre) continue;
		if (vis[v]) low[u] = min(low[u], tin[v]);
		else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
// 			if (low[v] >= tin[u]) cut[u] = 1;
			cnt++;
		}
	}
	for (int v : path[u]){
	    if (v == pre || low[v] > tin[u]) 
	        continue;
	    cut[u] = cut[v] = 1;
	}
// 	if (pre == 0) cut[u] = cnt > 1;
}

void bfs(int dist[], int src) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[src] = 0;
	queue<int> q; q.push(src);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v: path[u])
			if (dist[v] == INF) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> a >> b;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++){
	    #define all(a) a.begin(), a.end()
		sort(all(path[i]));
		path[i].resize(unique(all(path[i])) - path[i].begin());
	}
	
	tin_num = 0;
	dfs(1, 0);

// 	for (int i = 1; i <= n; i++)
// 		if (path[i].size() == 1) cut[i] = 1;

	bfs(dista, a); bfs(distb, b);
	
	int mx = 0;
	for (int i = 1; i <= n; i++)
		if (dista[i] < distb[i]){
		    mx = max(mx, distb[i]);
		    if (cut[i]) return cout << "NIE\n", 0;
		}
	
	cout << mx;
}