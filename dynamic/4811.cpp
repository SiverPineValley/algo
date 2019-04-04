// 알약
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int t, i, j;
	cin >> t;
	vector<vector<long long>> a(31,vector<long long> (31));
	for(i = 1; i <= 30; i++)
		a[0][i] = 1;

	for(i = 1; i <= 30; i++)
	{
		for(j = 0; j <= 30 - i; j++)
		{
			if(j == 0) a[i][j] = a[i-1][1];
			else a[i][j] = a[i-1][j+1] + a[i][j-1];
		}		
	}

	while(t)
	{
		cout << a[t][0] << "\n";
		cin >> t;
	}
	return 0;
}