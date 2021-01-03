#include <bits/stdc++.h>
using namespace std;

int n;
pair<pair<int, int>, int> a[(int) 1e5];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        long double x, y;
        cin >> x >> y;
        a[i].first.first = (int) round(1e6 * x);
        a[i].first.second = (int) round(1e6 * y);
        a[i].second = i;
    }
    sort(a + 1, a + n + 1, [](const pair<pair<int, int>, int>& x, pair<pair<int, int>, int>& y){
        return 1ll * x.first.first * y.first.second > 1ll * y.first.first * x.first.second;
    });
    for (int i = 1; i <= n; i++){
        cout << a[i].second << endl;
    }
}