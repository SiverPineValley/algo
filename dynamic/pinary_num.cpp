// 2193
#include <iostream>
using namespace std;
long long easy(int n)
{
	long long a[n+1][2];
	a[1][0] = 0; a[1][1] = 1;
	for(int i = 2; i <= n; i++)
	{
		a[i][0] = a[i-1][0] + a[i-1][1];
		a[i][1] = a[i-1][0];
	}
	return a[n][0] + a[n][1];
}

int main(void)
{
	int n;
	cin >> n;
	cout << easy(n) << "\n";
	return 0;
}