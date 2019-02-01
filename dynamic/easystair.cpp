// 10844
#include <iostream>
using namespace std;
const long long mod = 1000000000LL;
int easy(int n)
{
	long long a[n+1][10];
	a[1][0] = 0;
	for(int i = 1; i < 10; i++ )
		a[1][i] = 1;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(j == 0) a[i][j] = a[i-1][j+1];
			else if(j == 9) a[i][j] = a[i-1][j-1];
			else a[i][j] = a[i-1][j-1] + a[i-1][j+1];
			a[i][j] %= mod;
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