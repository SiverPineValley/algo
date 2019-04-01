// 1학년
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int n, r;
	cin >> n;
	vector<int> a(n);
	for(int i = 1; i < n; i++)
		cin >> a[i];
	cin >> r;
	vector<vector<long long>> d(n,vector<long long> (21));
	d[1][a[1]] = 1;

	for(int i = 1; i < n; i++) // 2 ~ n - 1
		for(int j = 0; j <= 20; j++)
		{
			if(d[i][j] > 0 && i + 1 <= n - 1)
			{
				int n1 = j + a[i+1];
				int n2 = j - a[i+1];
				if( 0 <= n1 && n1 <= 20 )
				{
					d[i+1][n1] += d[i][j];
				}
				if( 0 <= n2 && n2 <= 20 )
				{
					d[i+1][n2] += d[i][j];
				}
			}
		}

	cout << d[n-1][r] << "\n";
	return 0;
}	