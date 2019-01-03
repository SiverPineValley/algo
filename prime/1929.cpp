#include<iostream>
using namespace std;

void eratosthenes(int a, int b)
{
	int prime[b];
	int pn = 0;
	bool check[b+1];
	for( int i = 2; i <= b; i++ )
	{
		if(!check[i])
		{
			prime[pn++] = i;
			for( int j = i*i; j <= b; j+=i)
				check[j] = true;
		}
	}
	for( int i = 0; i < pn; i++ )
		if( prime[i] >= a ) cout << prime[i] << "\n";
	return;
}

int main(void)
{
	int a, b;
	cin >> a >> b;
	eratosthenes(a,b);
	return 0;
}