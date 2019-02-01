// 11057
#include <iostream>
using namespace std;
const long long mod = 10007;
int easy(int n)
{
	long long a[n+1][10];
	for(int i = 0; i < 10; i++ )
		a[1][i] = 1;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			a[i][j] = 0;
			for(int k = 0; k <= j; k++)
			{
				a[i][j] += a[i-1][k];
				a[i][j] %= mod;
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < 10; i++)
	{
		ans += a[n][i];
	}
	ans %= mod;
	return ans;
}

int main(void)
{
	int n;
	cin >> n;
	cout << easy(n) << "\n";
	return 0;
}