#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 8 + 1;
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr

int xlen, ylen, n;

struct segtree {
    int st[MAXN << 2], lz[MAXN << 2];
    void upd(int l, int r, int h, int node = 1, int tl = 1, int tr = ylen){
        if (tl > r || l > tr) return;
        st[node] = max(st[node], h);
        if (l <= tl && tr <= r){
            lz[node] = max(lz[node], h);
            return ;
        }
        int tm = (tl + tr) >> 1;
        upd(l, r, h, left);
        upd(l, r, h, right);
    }
    int query(int l, int r, int node = 1, int tl = 1, int tr = ylen){
        if (tl > r || l > tr) return 0;
        if (l <= tl && tr <= r) return st[node];
        int tm = (tl + tr) >> 1;
        return max({
            query(l, r, left),
            query(l, r, right),
            lz[node]
        });
    }
} st[MAXN << 2], lz[MAXN << 2];

void upd(int l, int r, int ly, int ry, int h, int node = 1, int tl = 1, int tr = xlen){
    if (l > r || l > tr || tl > r) return;
    st[node].upd(ly, ry, h);
    if (l <= tl & tr <= r){
        lz[node].upd(ly, ry, h);
        return ;
    }
    int tm = tl + tr >> 1;
    upd(l, r, ly, ry, h, left);
    upd(l, r, ly, ry, h, right);
}

int query(int l, int r, int ly, int ry, int node = 1, int tl = 1, int tr = xlen){
    if (l > r || l > tr || tl > r) return 0;
    if (l <= tl && tr <= r) return st[node].query(ly, ry);
    int tm = tl + tr >> 1;
    return max({
        query(l, r, ly, ry, left),
        query(l, r, ly, ry, right),
        lz[node].query(ly, ry)
    });
}

signed main(){
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> xlen >> ylen >> n;
    xlen ++, ylen ++;
    int ans = 0;
    while(n--){
        int lx, rx, ly, ry, h;
        cin >> rx >> ry >> h >> lx >> ly;
        rx += lx, ry += ly;
        ans = h + query(lx + 1, rx, ly + 1, ry);
        upd(lx + 1, rx, ly + 1, ry, ans);
        // for (int i = 1; i <= xlen; i++){
        //     for (int j = 1; j <= ylen; j++){
        //         cout << query(i, i, j, j) << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    cout << ans;
}