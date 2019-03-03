#include<iostream>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		bool ok = false;
		for(int i = x; i < M*N; i+=M)
		{
			if( (i)%N == (y-1) )
			{
				cout << i+1 << "\n";
				ok = true;
				break;
			}
		}
		if(!ok) cout << -1 << "\n";
	}
	return 0;
}