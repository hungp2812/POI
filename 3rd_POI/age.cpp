#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> g[3030], gr[3030], ord;
bool vis[3030];
set<int> comp;

int c[3030], n, p, m;

void dfs(int u){
    vis[u] = 1;
    for (auto v : g[u]){
        if (!vis[v]) dfs(v);
    }
    ord.push_back(u);
}

void rdfs(int u){
    vis[u] = 1;
    comp.insert(u);
    for (auto v : gr[u]){
        if (!vis[v]) rdfs(v);
    }
}

signed main(){
	cin >> n >> p;
	for (int i = 1; i <= n; i++) c[i] = 1e9;
	for (int i = 1, u, w; i <= p; i++){
	    cin >> u >> w;
	    c[u] = min(c[u], w);
	}
	cin >> m;
	for (int i = 1, u, v; i <= m; i++){
	    cin >> u >> v;
	    g[u].push_back(v);
	    gr[v].push_back(u);
	}
	for (int i = 1; i <= n; i++){
	    if (!vis[i]) dfs(i);
	}
	for (int i = 1; i <= n; i++){
	    vis[i] = 0;
	}
	reverse(ord.begin(), ord.end());
	int ans = 0, res = 1e9;
	for (int i : ord){
	    if (!vis[i]){
	        rdfs(i);
	        int cc = 1e9;
	        bool r = 1;
	        for (int u : comp){
	            cc = min(cc, c[u]);
	            for (int v : gr[u]){
	                if (!comp.count(v))
	                    r = 0;
	            }
	        }
	        if (r){
	            if (cc == (int) 1e9){
	                res = min(res, i);
	            }
	            ans += cc;
	        }
	        comp.clear();
	    }
	}
	if (res != 1e9) 
	    cout << "NIE\n" << res;
	else
	    cout << "TAK\n" << ans;
}