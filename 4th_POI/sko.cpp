#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
priority_queue <long long> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int pos;
		cin >> pos;
		pos += 20000;
		cin >> a[pos];
		pq.push(40000ll * a[pos] + pos);
	}	
	while(pq.empty() == false)
	{
		int cnt = pq.top() / 40000, pos = pq.top() % 40000;
		pq.pop();
		if(cnt <= 1)
		{
			break;
		}
		if(a[pos] != cnt)
		{
			continue;
		}
		if(cnt >= 18)
		{
		    int temp = cnt / 18;
			a[pos - 6] += temp;
			a[pos + 6] += temp;
			a[pos] = a[pos] % 18;
			pq.push(40000ll * a[pos - 6] + pos - 6);
			pq.push(40000ll * a[pos + 6] + pos + 6);
			pq.push(40000ll * a[pos] + pos);
		}
		else if(cnt >= 7)
		{
		    int temp = cnt / 7;
			a[pos - 4] += temp;
			a[pos + 4] += temp;
			a[pos] = a[pos] % 7;
			pq.push(40000ll * a[pos - 4] + pos - 4);
			pq.push(40000ll * a[pos + 4] + pos + 4);
			pq.push(40000ll * a[pos] + pos);
		}
		else if(cnt >= 3)
		{
			int temp = cnt / 3;
			a[pos - 2] += temp;
			a[pos + 2] += temp;
			a[pos] = a[pos] % 3;
			pq.push(40000ll * a[pos - 2] + pos - 2);
			pq.push(40000ll * a[pos + 2] + pos + 2);
			pq.push(40000ll * a[pos] + pos);
		}
		else if(cnt == 2)
		{
			a[pos - 2] += 1;
			a[pos + 1] += 1;
			a[pos] = 0;
			pq.push(40000ll * a[pos - 2] + pos - 2);
			pq.push(40000ll * a[pos + 1] + pos + 1);
		}
	}
	for(int i = 40000; i >= 0; i--)
	{
		if(a[i] and a[i + 1])
		{
			a[i + 2] = 1;
			a[i] = 0;
			a[i + 1] = 0;
			i += 3;
		}
	}
	for(int i = 0; i <= 40000; i++)
	{
		if(a[i])
		{
			cout << i - 20000 << ' ';
		}
	}
}