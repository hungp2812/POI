#include <bits/stdc++.h>

using namespace std;

int n;

const int MAXP = 50 * 50 * 50 * 50 + 1;
int dist[MAXP], P[10], mx[10];

int Hash(vector<int> a) {
    int res = 0;
    for (int i = 0; i < a.size(); i++) 
        res += P[i] * a[i];
    return res;
}

int num(int h, int pos) {
    int cur = 0;
    return (h % P[pos + 1] - h % P[pos]) / P[pos];
}

void modify(int &h, int pos, int val) {
    h = h - P[pos] * num(h, pos) + val * P[pos];
}

void printHash(int h) {
    for (int i = 0; i < n; i++)
        cout << num(h, i) << ' ';
    cout << '\n';
}

signed main() {
    cout.tie(0), cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    P[0] = 1;
    for (int i = 1; i <= n + 1; i++) P[i] = P[i - 1] * 50;
    vector<int> source(n), target(n);
    for (int i = 0; i < n; i++) cin >> source[i];
    for (int i = 0; i < n; i++) mx[i] = source[i];
    for (int i = 0; i < n; i++) cin >> target[i];
    queue<int> bfs;
    bfs.push(Hash(source));
    memset(dist, -1, sizeof(dist));
    dist[Hash(source)] = 0;
    while (!bfs.empty()) {
        int u = bfs.front(); bfs.pop();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j) {
                    // Pour i -> j
                    
                    // Operation 1:
                    if (mx[j] - num(u, j) >= num(u, i)) {
                        int nxt = u;
                        modify(nxt, j, num(u, j) + num(u, i));
                        modify(nxt, i, 0);
                        if (dist[nxt] == -1) {
                            dist[nxt] = dist[u] + 1;
                            bfs.push(nxt);
                        }
                    }
                    
                    // Operation 2:
                    if (mx[j] - num(u, j) <= num(u, i)) {
                        int nxt = u;
                        modify(nxt, i, num(u, i) - mx[j] + num(u, j));
                        modify(nxt, j, mx[j]);
                        if (dist[nxt] == -1) {
                            dist[nxt] = dist[u] + 1;
                            bfs.push(nxt);
                        }
                    }
                }
        
        for (int i = 0; i < n; i++) {
            // Operation 3:
            if (num(u, i) > 0) {
                int nxt = u;
                modify(nxt, i, 0);
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[u] + 1;
                    bfs.push(nxt);
                }
            }
        }
    }
    if (dist[Hash(target)] == -1) cout << "NIE\n";
    else cout << dist[Hash(target)] << '\n';
}