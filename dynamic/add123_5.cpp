// 15990
#include <iostream>
using namespace std;

long long add123(int n)
{
	if(n <= 2) return 1;
	long long d[n+1][4];
	d[1][1] = 1;
	d[1][2] = 0;
	d[1][3] = 0;
	d[2][1] = 0;
	d[2][2] = 1;
	d[2][3] = 0;
	d[3][1] = 1;
	d[3][2] = 1;
	d[3][3] = 1;
	for(int i = 4; i <= n; i++)
	{
		d[i][1] = (d[i-1][2] + d[i-1][3]) % 1000000009LL;
		d[i][2] = (d[i-2][1] + d[i-2][3]) % 1000000009LL;
		d[i][3] = (d[i-3][1] + d[i-3][2]) % 1000000009LL;
	}
	return (d[n][1] + d[n][2] + d[n][3]) % 1000000009LL;
}

int main(void)
{
	int t;
	long long n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << add123(n) << "\n";
	}

	return 0;
}