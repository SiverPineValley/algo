// 14002
#include <iostream>
using namespace std;

void printLSD(int * a, int* v, int p)
{
	if(p == -1)
		return;
	printLSD(a,v,v[p]);
	cout << a[p] << " ";
}

void lsd(int * a, int* d, int* v, int n)
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < i; j++)
		{
			int temp = d[j] + 1;
			if((a[j] < a[i])&&(d[i] < temp))
			{
				d[i] = temp;
				v[i] = j;
			}
		}
	}
	int best = 1;
	for(int i = 1; i <= n; i++)
	{
		if(d[best] < d[i])
		{
			best = i;
		}
	}
	cout << d[best] << "\n";
	printLSD(a,v,best);
}

int main(void)
{
	int n;
	cin >> n;
	int a[n+1];
	int d[n+1];
	int v[n+1];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		d[i] = 1;
		v[i] = -1;
	}
	lsd(a,d,v,n);
	return 0;
}