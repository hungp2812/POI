#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n, m, ans[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int c){
    if (ans[u])
        return ;
    ans[u] = c;
    for (auto v : adj[u]) {
        dfs(v, 3 - c);
    }
}

int main(){
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        if (adj[i].empty())
            return cout << "NIE\n", 0;
        if (!ans[i])
            dfs(i, 1);
    }
    cout << "TAK\n";
    for (int i = 1; i <= n; i++){
        cout << (ans[i] == 1 ? "K\n" : "S\n");
    }
}