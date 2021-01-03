#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int MAXN = 1e6 + 5;

vector<int> adj[MAXN], ord;
int sz[MAXN], n, par[MAXN];
long long res[MAXN];

void dfs(int u, int p = 0){
    ord.push_back(u);
    par[u] = p;
    sz[u] = 1;
    for (auto v : adj[u]) if (v != p){
        dfs(v, u);
        sz[u] += sz[v];
    }
    for (auto v : adj[u]) if (v != p){
        res[0] += 1ll * sz[v] * (sz[u] - sz[v] - 1);
    }
    // cout << u << ' ' << tmp << endl;
}

// void dfs2(int u, int p){
//     int k = sz[u], l = n - sz[u];
//     if (u != p){
//         sz[p] = l;
//         sz[u] = n;
//         tmp += (k - l) * 2;
//     }
//     // cout << u << ' ' << tmp << endl;
//     if (res > tmp){
//         ans = u;
//         res = tmp;
//     }
//     for (auto v : adj[u]) if (v != p){
//         dfs2(v, u);
//     }
//     if (u != p){
//         sz[u] = k;
//         sz[p] = n;
//         tmp -= (k - l) * 2;
//     }
// }

signed main(){
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (auto u : ord){
        res[u] = res[par[u]] + (sz[u] * 2 - n) * 2;
    }
    cout << (min_element(res + 1, res + n + 1) - res);
}
