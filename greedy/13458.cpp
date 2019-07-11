// 시험 감독
#include <iostream>
using namespace std;
int main(void)
{
	int n, b, c;
	long long cnt = 0;
	int a[1000001];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cin >> b >> c;

	for(int i = 0; i < n; i++)
	{
		a[i] -= b;
		cnt++;
		if(a[i] > 0)
		{
			if(a[i] % c == 0) cnt += ( a[i] / c );
			else cnt += ( a[i] / c ) + 1;
		}
	}
	cout << cnt << "\n";
	return 0;
}