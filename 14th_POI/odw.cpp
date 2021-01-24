#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int x[55], cnt, n, m;
vector<int> c[55];
int ctn[MAXN];

signed main(){
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    map<int, vector<int>> mp;
    mp[1] = {};
    for (int i = 1; i <= n; i++){
        cin >> ctn[i];
    }
    for (int j = 1, t; j <= m; j++){
        cin >> t;
        mp[t].push_back(1);
    }
    for (auto [p, v] : mp){
        x[cnt] = p;
        c[cnt ++] = v;
    }
    x[cnt] = 1e9;
    for (int i = cnt - 1; i >= 1; i--)
        x[i] /= x[i - 1];
    int ans = 0;
    for (int i = 0; i < cnt; i++){
        // cout << x[i] << ' ';
        #define rall(a) a.rbegin(), a.rend()
        sort(rall(c[i]));
        int k = 0;
        for (int j = 1; j <= n; j++){
            int r = ctn[j] % x[i + 1];
            ctn[j] /= x[i + 1];
            while(k < c[i].size() && r){
                r --; ans += c[i][k ++];
            }
        }
        while(k < c[i].size()){
            int t = 0, j = k;
            for (; j < min(k + x[i + 1], (int) c[i].size()); j++)
                t += c[i][j];
            c[i + 1].push_back(t);
            k = j;
        }
    }
    cout << ans;
}