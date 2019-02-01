// 9465
#include <iostream>
using namespace std;
int main(void)
{
	int t, n;
	int s[100001][2];
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < 2; i++)
			for(int j = 1; j <= n; j++)
				cin >> s[j][i];
		int a[n+1][3];
		for(int j = 0; j < 3; j++)
			a[0][j] = 0;
		for(int i = 1; i <= n; i++)
		{
			a[i][0] = max(a[i-1][0],a[i-1][1]);
			a[i][0] = max(a[i][0],a[i-1][2]);
			a[i][1] = max(a[i-1][0],a[i-1][2]) + s[i][0];
			a[i][2] = max(a[i-1][0],a[i-1][1]) + s[i][1];
		}
		int ans = 0;
		for(int i = 0; i < 3; i++)
			ans = max(ans,a[n][i]);
		cout << ans << "\n";
	}
	return 0;
}