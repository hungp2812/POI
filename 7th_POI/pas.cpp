#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int a[3], gr[1005];

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
	for(int i=0; i<3; i++) cin >> a[i];
	for(int i=1; i<=1000; i++){
		unordered_set<int> s;
		for(int j=0; j<i; j++){
			for(int k=0; k<3; k++){
				if(a[k] + j <= i){
					s.insert(gr[j] ^ gr[i-j-a[k]]);
				}
			}
		}
		for(int j=0; ; j++){
			if(s.find(j) == s.end()){
				gr[i] = j;
				break;
			}
		}
	}
	int q, x;
	cin >> q;
	while(q--){
		cin >> x;
		if(gr[x]) puts("1");
		else puts("2");
	}
}
