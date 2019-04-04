//퇴사2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	long long n;
	cin >> n;
	vector<long long> t(n+1);		// 걸린 시간
	vector<long long> p(n+1);		// 보수
	vector<long long> d(n+2);		// 당일까지 최대 수익
	for(int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];
	d[1] = 0;
	for(int i = 1; i < n+1; i++)
	{
		d[i] = max(d[i-1],d[i]);
		if(i+t[i] <= n+1)			// 범위 안에 있을 때
		{
			d[i+t[i]] = max(d[i+t[i]], d[i] + p[i]);
		}
	}
	long long best = -1ll;
	for(int i = 1; i <= n+1; i++){
		if(d[i] > best) best = d[i];
	}
	cout << best << "\n";
	return 0;
}