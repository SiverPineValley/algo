// 1912
#include <iostream>
using namespace std;

int ms(int * a, int* d, int n)
{
	for(int i = 2; i <= n; i++)
	{
		d[i] = max(d[i-1]+a[i],a[i]);
	}
	int best = d[1];
	for(int i = 2; i <= n; i++)
	{
		if(best < d[i])
		{
			best = d[i];
		}
	}
	return best;
}

int main(void)
{
	int n;
	cin >> n;
	int a[n+1];
	int d[n+1];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	d[1] = a[1];
	cout << ms(a,d,n) << "\n";
	return 0;
}