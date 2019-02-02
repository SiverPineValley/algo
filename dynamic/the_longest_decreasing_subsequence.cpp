// 11722
#include <iostream>
using namespace std;

int lsd(int * a, int* d, int n)
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < i; j++)
		{
			int temp = d[j] + 1;
			if((a[j] > a[i])&&(d[i] < temp))
			{
				d[i] = temp;
			}
		}
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
		d[i] = 1;
	}
	cout << lsd(a,d,n) << "\n";
	return 0;
}