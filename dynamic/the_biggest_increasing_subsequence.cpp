// 11055
#include <iostream>
using namespace std;

int bis(int * a, int* d, int n)
{
	for(int i = 1; i <= n; i++)
	{
		int ans = d[i];
		int temp;
		for(int j = 1; j < i; j++)
		{
			temp = a[i] + d[j];
			if((a[j] < a[i])&&(ans < temp))
			{
				ans = temp;
			}
		}
		d[i] = ans;
	}
	int best = 0;
	for(int i = 1; i <= n; i++)
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
		d[i] = a[i];
	}
	cout << bis(a,d,n) << "\n";
	return 0;
}