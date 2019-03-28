// 1,2,3 더하기4
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
		a[0] = 1;
		for(int j = 1; j <= 3; j++)
			for(int i = 1; i <= n; i++)
				if((i - j) >= 0)
					a[i] += a[i - j];
		cout << a[n] << "\n";
	}	
	return 0;
}