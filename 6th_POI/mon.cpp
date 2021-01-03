#include <bits/stdc++.h>
using namespace std;

int k, q;
set <int> s[10];

int main(){
	cin >> k >> q;
	int t = 0;
	for (int i = 1; i <= 8; i++){
		t = t * 10 + k;
		s[i].insert(t);
	}
	for (int i = 2; i <= 8; i++){
		int j = 1, k = i - 1;
		while(j <= k){
			for (auto v : s[j]){
				for (auto u : s[k]){
					s[i].insert(u + v);
					if (u != v)
						s[i].insert(abs(u - v));
					s[i].insert(u * v);
					if (u % v == 0)
						s[i].insert(u / v);
				}
			}
			j ++, k --;
		}
	}
	while(q--){
		int n, r = -1;
		cin >> n;
		
		for (int i = 1; i <= 8; i++){
			if (s[i].count(n)){
				r = i;
				break;
			}
		}
		if (~r) cout << r << "\n";
		else cout << "NIE\n";
	}
}