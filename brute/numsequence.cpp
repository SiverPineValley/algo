#include<iostream>
using namespace std;
int main(void)
{
	long long n;
	long long j = 1;
	long long s = 0;
	cin >> n;
	for(int i = 1; i <= 9; i++)
	{
		if(j*10 <= n) s = s + (j*10 - j)*i;
		else
		{
			s = s + (n - j + 1)*i;
			break;
		}
		j *= 10;
	}
	cout << s << "\n";
	return 0;
}