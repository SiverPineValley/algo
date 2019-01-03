#include <iostream>
using namespace std;

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
	int n, s;
	long long g = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		int r[s];
		for(int j = 0; j < s; j++) cin >> r[j];
		for(int j = 0; j < s-1; j++)
		{
			for(int k = j+1; k < s; k++) g += gcd(r[j],r[k]);
		}
		cout << g << "\n";
		g = 0;
	}

	return 0;
}