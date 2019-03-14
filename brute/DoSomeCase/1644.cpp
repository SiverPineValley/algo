// 소수의 연속합
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int n;
	int ans = 0;
	cin >> n;
	vector<int> prime(n);	// 소수 저장
	vector<bool> check(n+1); // 지워졌으면 true, 지워지지 않았으면 false
	int pn = 0; // 소수의 개수
	for(int i = 2; i <= n; i++)
	{
		if(!check[i])
		{
			int t = pn++;
			prime[t] = i;
			for(int j = i*i; j<=n; j+=i)
				check[j] = true;
		}
	}

	for(int i = 0; i < pn; i++)
	{
		int sum = 0;
		for(int j = i; j < pn; j++)
		{
			sum += prime[j];
			if(sum == n) ans += 1;
			if(sum > n) break;
		}
	}
	cout << ans << "\n";
	return 0;
}