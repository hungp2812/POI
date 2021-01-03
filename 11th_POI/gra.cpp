#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define F first
#define S second

const int maxN = 1e6 + 5;

int n, s, p[maxN];
map<int, int> cnt;
// basic staircase NIM crying :'(
void Solve(){
    cin >> s >> n;
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
    p[n] = s + 1;
    cnt.clear();
    int cur = 0;
    for (int i = n; i > 0; i--){
        cur += p[i] - p[i - 1] - 1;
        cnt[cur] ++;
    }
    int ans = 0, grd = 0;
    vector<pii> vec;
//    cout << "UBD:\n";
    for (auto v : cnt){
        if (v.F == 1){
            cout << v.S << endl;
            return;
        }
        if (v.F % 2 == 1){
            grd ^= v.S;
        }
        vec.push_back(v);
//        cout << v.F << ' ' << v.S << endl;
    }
    for (int i = 0; i < vec.size(); i++){
        if (vec[i].F == 2) continue;

        for (int x = 1; x <= vec[i].S; x++){
            int nxt_grd;
            if (vec[i].F % 2 == 0){
                if (i && vec[i-1].F == vec[i].F - 1){
                    nxt_grd = grd ^ vec[i-1].S ^ (vec[i-1].S + x);
                }else{
                    nxt_grd = grd ^ x;
                }
            }else{
                nxt_grd = grd ^ vec[i].S ^ (vec[i].S - x);
            }
            if(!nxt_grd) ans++;
        }
    }
    cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
//    cin >> TC;
    while(TC --) Solve();
    return 0;
}

/*

3
5 2
1 3

5 2
2 3

8 3
1 3 4

*/