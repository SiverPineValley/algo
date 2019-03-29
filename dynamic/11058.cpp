// 크리보드
#include <iostream>
#include <vector>
using namespace std;
vector<long long> a(101);
int main(void)
{
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] + 1;
		for(int j = 3; j <= i; j++)
		{
			if((i - j) >= 0)
			{
				long long temp = a[i-j] * (j - 1);
				if(temp > a[i]) a[i] = temp;
			}
			else break;
		}
	}
	cout << a[n] << "\n";
	return 0;
}