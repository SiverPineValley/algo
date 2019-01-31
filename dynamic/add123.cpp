// 9095
#include <iostream>
using namespace std;

int add123(int n, int* a)
{
	if(n == 2) return 2;
	else if(n <= 1) return 1;
	a[n] = add123(n-1,a) + add123(n-2,a) + add123(n-3,a);
	return a[n];
}

int main(void)
{
	int t, n;
	int a[12];
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << add123(n,a) << "\n";
	}

	return 0;
}