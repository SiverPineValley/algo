// 평범한 배낭(kanpsack) - 2
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
	vector<int> d(k+1);
	for(int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = k; j >= 1; j--)
		{
			if(j - w[i] >= 0)
				d[j] = max(d[j], d[j-w[i]] + v[i]);
			if(d[j] > best)
				best = d[j];
		}
	}

	cout << best << "\n";
	return 0;
}