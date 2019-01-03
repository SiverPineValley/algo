#include <iostream>
using namespace std;
bool prime(int n)
{
	if(n < 2) return false;
	for (int i = 2; i*i <= n; i++)
		if(n % i == 0) return false;
	return true;
}

int main(void)
{
	int n;
	int r = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if(prime(num)) r++;
	}
	cout << r << "\n";
	return 0;
}