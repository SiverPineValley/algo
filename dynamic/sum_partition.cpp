// 2225
#include <iostream>
using namespace std;
long long MOD = 1000000000;
long long d[201][201];
int main(void)
{
	int n, k;
	cin >> n >> k;
	d[0][0] = 1LL;
	for(int i = 1; i <= k; i++)
		for(int j = 0; j <= n; j++)
			for(int t = 0; t <= j; t++)
			{
				d[i][j] += d[i-1][j-t];
				d[i][j] %= MOD;
			}
	cout << d[k][n]<< "\n";
	return 0;
}