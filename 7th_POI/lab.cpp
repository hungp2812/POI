#include <bits/stdc++.h>
using namespace std;

const int MAXN = 6060;

char cr[MAXN];
int nxt[MAXN][3], n, P[MAXN];

int find(int u){
    return P[u] = (P[u] == u ? u : find(P[u]));
}

bool join(int u, int v){
    u = find(u),v = find(v);
    P[v] = u; return u != v;
}

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	cin >> n;
	int cnt = n;
	for (int i = 1; i < n; i++){
	    cin >> cr[i];
	    for (int j = 0; j < 3; j++)
	        cin >> nxt[i][j];
	    P[i] = i;
	}
	for (int i = n - 1; i >= 1; i--){
	    for (int k = 0; k < 3; k++)
	        nxt[i][k] = find(nxt[i][k]);
	    for (int j = i + 1; j < n; j++){
	        if (cr[j] == cr[i]){
    	        bool f = 0;
	            for (int k = 0; k < 3; k++)
	                if (nxt[i][k] != find(nxt[j][k])){
	                    f = 1; break;
	                }
    	        if (f) continue;
    	        cnt -= join(i, j); 
    	        break;
	        }
	    }
	}
	cout << cnt;
}