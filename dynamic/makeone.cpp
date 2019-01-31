// 1463
// 백준's 코드
#include <iostream>
using namespace std;
int makeone(int t) // bottom-up
{
	int v[t+1];
	v[1] = 0;
	for(int i = 2; i <= t; i++)
	{
		v[i] = v[i-1] + 1;
		if( ( i%2 == 0 ) && ( v[i] > v[i/2] + 1 ) )
		{
			v[i] = v[i/2] + 1;
		}
		if( ( i%3 == 0 ) && ( v[i] > v[i/3] + 1 ) )
		{
			v[i] = v[i/3] + 1;
		}
	}
	return v[t];
}

int makeone2(int t, int* ary) // top-down
{	
	if(t <= 1) return 0;
	if(ary[t] > 0) return ary[t];
	ary[t] = makeone2(t-1,ary) + 1;
	if(t%2 == 0)
	{
		int temp = makeone2(t/2,ary) + 1;
		if(ary[t] > temp) ary[t] = temp;
	}
	if(t%3 == 0)
	{
		int temp = makeone2(t/3,ary) + 1;
		if(ary[t] > temp) ary[t] = temp;
	}

	return ary[t];
}

int main(void)
{
	int t;
	cin >> t;
	cout << makeone(t) << "\n";
	return 0;
}