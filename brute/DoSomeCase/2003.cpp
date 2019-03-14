// 수들의 합2
#include <iostream>
using namespace std;
int main(void)
{
	int n, m;
	int ans = 0;
	int a[10000];
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
	{
		int sum = 0;
		for(int j = i; j < n; j++)
		{
			sum += a[j];
			if(sum == m) ans += 1;
			if(sum > m) break;
		}
	}
	cout << ans << "\n";
	return 0;
}