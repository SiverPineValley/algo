// 부분합
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int n, s;
	int ans = 100000;
	cin >> n >> s;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
	{
		int sum = 0;
		for(int j = i; j < n; j++)
		{
			sum += a[j];
			if(sum == s)
			{
				int t = (j - i) + 1;
				if(t < ans) ans = t;
			}
			if(sum > s)
			{
				int t = (j - i) + 1;
				if(t < ans) ans = t;
				break;
			}	
		}
	}
	if(ans > n) cout << 0 << "\n";
	else cout << ans << "\n";	
	return 0;
}