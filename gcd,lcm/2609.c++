#include<iostream>
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
	int a, b, g;
	cin >> a >> b;

	g = gcd(a,b);

	cout << g << "\n";
	cout << a*b/g << "\n";

	return 0;
}