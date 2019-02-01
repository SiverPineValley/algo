// 2156
#include <iostream>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int w[n+1];
	int d[n+1][3];
	for(int i = 1; i <= n; i++)
		cin >> w[i];
	d[1][0] = 0; d[1][1] = w[1]; d[1][2] = w[1];
	for(int i = 2; i <= n; i++)
	{
		d[i][0] = max(d[i-1][0],d[i-1][1]);
		d[i][0] = max(d[i][0],d[i-1][2]);
		d[i][1] = d[i-1][0] + w[i];
		d[i][2] = d[i-1][1] + w[i];
	}
	int ans = 0;
	ans = max(d[n][0],d[n][1]);
	ans = max(ans,d[n][2]);
	cout << ans << "\n";
	return 0;
}