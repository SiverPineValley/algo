// 평범한 배낭(kanpsack) - 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, k;														// 물품의 개수, 최대 무게
	int best = 0;
	cin >> n >> k;
	vector<int> w(n+1);
	vector<int> v(n+1);
	vector<vector<int>> d(n+1,vector<int> (k+1));
	for(int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k; j++)
		{
			d[i][j] = d[i-1][j];
			if(j - w[i] >= 0)
				d[i][j] = max(d[i][j], d[i-1][j-w[i]] + v[i]);		// 안넣을 때, 넣었을 때 비교
		}

	for(int i = 1; i <= k; i++)
		best = d[n][i];
	cout << best << "\n";
	return 0;
}