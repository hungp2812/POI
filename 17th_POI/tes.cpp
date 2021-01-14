#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
vector<int> p[MAXN];
int n, q;

void solve(){
    cin >> n;
    int cur = 0, f = 0;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        auto vt = upper_bound(p[x].begin(), p[x].end(), cur);
        if (vt == p[x].end()) f = 1;
        else cur = *vt;
    }
    cout << (f ? "NIE\n" : "TAK\n"); 
}

int main(){
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 1, a; i <= n; i++){
        cin >> a; p[a].push_back(i);
    }
    cin >> q;
    while(q--){
        solve();
    }
}