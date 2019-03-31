// 기타리스트
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int n, s, m;				// 곡 개수, 시작볼륨, 최대볼륨
	int best = -1;
	cin >> n >> s >> m;
	vector<int> v(n+1);			// 볼륨 리스트
	vector<vector<int>> a(n+1,vector<int> (m+1));
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	a[0][s] = 1;
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			if(a[i][j] == 1 && i + 1 <= n)
			{
				int p = j + v[i+1];
				int s = j - v[i+1];
				if(p >= 0 && p <= m)
					a[i+1][p] = 1;
				if(s >= 0 && s <= m)
					a[i+1][s] = 1;
			}
		}
	}
	for(int i = 0; i <= m; i++)
		if(a[n][i] == 1)
			best = i;
	cout << best << "\n";
	return 0;
}