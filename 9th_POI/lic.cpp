#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
vector<int> primes;

void sieve(int MAX) {
	vector<int> prime(MAX + 1, 0);
	for (int i = 2; i <= MAX; i++) prime[i] = 1;
	for (int i = 2; i <= sqrt(MAX); i++)
		if (prime[i])
			for (int j = i * i; j <= MAX; j += i) prime[j] = 0;
	for (int i = 2; i <= MAX; i++) 
		if (prime[i]) primes.push_back(i);
}

signed main() {
	cout.tie(0), cin.tie(0)->sync_with_stdio(false);
	int n, m, b;
	cin >> n >> m >> b;
	m++;
	sieve(b);
	while(m > 0) {
		int temp = min(100000, m);
		vector<int> num(temp);
		for (int i = n; i < n + temp; i++) num[i - n] = i;
		
		// Continue sieve
		for (int i: primes) {
			int first = n / i * i;
			if (n % i != 0) first += i;
			for (int j = first; j < n + temp; j += i) 
				while (num[j - n] % i == 0) num[j - n] /= i;
		}
		for (int i = 0; i < temp; i++)
		    if (num[i] == 1) cnt++; 
		m -= temp;
		n += 100000;	
	}
	cout << cnt << '\n';
}