//11727
#include<iostream>
using namespace std;

int tiling(int n)
{
	int t[n+1];
	t[0] = 1;
	t[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		t[i] = t[i-1] + 2*t[i-2];
		t[i] %= 10007;
	}
	return t[n];
}

int tiling2(int n, int* ary)
{
	if(n <= 2) return n;
	ary[n] = ( tiling2(ary[n-1],ary) + 2*tiling2(ary[n-2],ary) ) % 10007;
	return ary[n];
}

int main(void)
{
	int n;
	cin >> n;
	cout << tiling(n) << "\n";	
	return 0;
}