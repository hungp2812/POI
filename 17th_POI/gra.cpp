#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

long long a[MAXN];
int n;

int main(){
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, - ans + a[i]);
    }
    cout << ans;
}