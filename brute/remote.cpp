#include <iostream>
#include <math.h>
using namespace std;
bool b[10];
int possible(int c)
{
	if(c == 0)
		return b[0] ? 0 : 1;
	int len = 0;
	while(c > 0)
	{
		if(b[c % 10]) return 0;
		len += 1;
		c /= 10;
	}
	return len;
}

int main(void)
{
	int n, m;
	cin >> n;
	cin >> m;
	int best = abs(n-100);
	for(int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		b[t] = true;
	}

	for(int i = 0; i <= 1000000; i++)
	{
		int len = possible(i);
		if(len)
		{
			int temp = abs(n - i) + len;
			if((best == -1) || best > temp) best = temp;
		}
	}
	cout << best << "\n";
	return 0;
}