// 1565
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX = 1000000000

int gcd(int a, int b)
{	
	int r;
	while( b != 0 )
	{
		r = a%b;
		a = b;
		b = r;
	}

	return a;
}

int main(void)
{
	int d, m;
	cin >> d >> m;
	vector<int> ad(d);
	vector<int> am(m);
	
	return 0;
}
