// 11054
#include <iostream>
using namespace std;

int lbs(int * a, int * a2, int* d, int* d2, int n)
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < i; j++)
		{
			int temp = d[j] + 1;
			if((a[j] < a[i])&&(d[i] < temp))
			{
				d[i] = temp;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < i; j++)
		{
			int temp = d2[j] + 1;
			if((a2[j] < a2[i])&&(d2[i] < temp))
			{
				d2[i] = temp;
			}
		}
	}
	int best = 0;
	for(int i = 1; i <= n; i++)
	{
		if(best < (d[i] + d2[n+1-i]))
		{
			best = d[i] + d2[n+1-i];
		}
	}
	return best;
}

int main(void)
{
	int n;
	cin >> n;
	int a[n+1];
	int a2[n+1];
	int d[n+1];
	int d2[n+1];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a2[n+1-i] = a[i];
		d[i] = 1;
		d2[i] = 0;
	}
	cout << lbs(a,a2,d,d2,n) << "\n";
	return 0;
}