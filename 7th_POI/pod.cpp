#include <bits/stdc++.h>
using namespace std;

int n, vis[505][505], chk[505];
vector<int> adj[505], r;

void dfs(int u, int p){
    vis[p][u] = 1;
    for (auto v : adj[u]){
        if (!vis[p][v]){
            dfs(v, p);
        }
    }
}

signed main(){
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 1, k, x; i <= n; i++){
        cin >> k;
        if (k == 0){
            r.push_back(i);
            chk[i] = 1;
        }
        while(k --){
            cin >> x;
            adj[x].push_back(i);
        }
    }
    for (auto u : r){
        dfs(u, u);
    }
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= n; j++){
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    bool f = 1;
    for (int i = 1; i <= n; i++){
        if (!chk[i]){
            int cnt = 0;
            for (int j = 1; j <= n; j++){
                if(vis[j][i]) cnt ++;
            }
            if (cnt <= 1){
                f = 0;
                cout << i << "\n";
            }
        }
    }
    if (f) cout << "BRAK\n";
}