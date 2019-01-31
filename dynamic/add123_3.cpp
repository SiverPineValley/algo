// 15988
#include <iostream>
using namespace std;

long long add123(int n, long long* a)
{
	if(n == 2) return 2;
	else if(n <= 1) return 1;
	a[n] = (add123(n-1,a) + add123(n-2,a) + add123(n-3,a)) % 1000000009LL;
	return a[n];
}

long long add123_2(int n)
{
	if(n == 2) return 2;
	else if(n <= 1) return 1;
	long long d[n+1];
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	for(int i = 3; i <= n; i++)
	{
		d[i] = (d[i-1] + d[i-2] + d[i-3]) % 1000000009LL;
	}
	return d[n];
}

int main(void)
{
	int t;
	long long n;
	long long a[1000001];
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << add123_2(n) << "\n";
		cout << add123(n,a) << "\n";
	}

	return 0;
}