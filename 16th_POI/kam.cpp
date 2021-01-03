#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &v : a) cin >> v;
    b[0] = a[0];
    for (int i = 1; i < n; i++) b[i] = a[i] - a[i - 1];
    reverse(b.begin(), b.end());
    int g = 0;
    for (int i = 0; i < n; i += 2) g ^= b[i];
    puts(g ? "TAK" : "NIE");
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}