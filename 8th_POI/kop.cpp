#include <bits/stdc++.h>
using namespace std;

const int ext = 5e4, MAXN = 1e5 + 5;
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr

int lenx, leny, q;
int st[MAXN << 2], lz[MAXN << 2];

void app(int node, int v){
    st[node] += v;
    lz[node] += v;
}

void push(int node){
    app(node << 1, lz[node]);
    app(node << 1 | 1, lz[node]);
    lz[node] = 0;
}

void upd(int l, int r, int v, int node = 1, int tl = 1, int tr = 1e5){
    if (l > r || tl > r || l > tr) return ;
    if (l <= tl && tr <= r) {
        app(node, v);
        return ;
    }
    int tm = (tl + tr) >> 1;
    push(node);
    upd(l, r, v, left);
    upd(l, r, v, right);
    st[node] = max(st[node << 1], st[node << 1 | 1]);
}

int xx[15015];
vector<int> yy[15015];

signed main(){
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> lenx >> leny >> q;
    map<int, vector<int>> mp;
    for (int i = 0, x, y; i < q; i++){
        cin >> x >> y;
        mp[x].push_back(y + ext);
    }
    int n = 0;
    for (auto [x, y] : mp){
        xx[n] = x;
        yy[n] = y;
        n ++;
    }
    int j = 0, i = 0, ans = 0;
    for (; i < n; i++){
        while(xx[i] > xx[j] + lenx){
            for (auto v : yy[j]) upd(v - leny, v, -1); j++;
        }
        for (auto v : yy[i]) upd(v - leny, v, +1);
        ans = max(ans, st[1]);
    }
    cout << ans;
}