// 1699
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int n;
	int MAX = 100000;
	vector<int> d(MAX+1);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		d[i] = i;
		for(int j = 1; j*j <= i; j++)
		{
			if(d[i] > d[i-j*j]+1)
			{
				d[i] = d[i - j*j] + 1;
			}
		}
	}
	cout << d[n] << "\n";
	return 0;
}