// 8393
#include <iostream>
using namespace std;
int main(void)
{
	int n;
	long long sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
		sum += i;
	cout << sum << "\n";
	return 0;
}