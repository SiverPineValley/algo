// 1,2,3 더하기 - Bottom up, 이전에 풀었던 방법은 Top down.
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> a(n + 1);
		if(n <= 1) cout << 1 << "\n";
		else if(n == 2) cout << 2 << "\n";
		else
		{
			a[0] = 1; a[1] = 1; a[2] = 2;
			for(int i = 3; i <= n; i++)
			{
				a[i] = a[i-1] + a[i-2] + a[i-3];
			}
			cout << a[n] << "\n";	
		}
	}	
	return 0;
}