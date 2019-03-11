// 종이조각
#include <iostream>
#include <cstdio>
using namespace std;
int n, m; // 세로, 가로
int paper[4][4];
int best = 0;
int main(void)
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%1d",&paper[i][j]);
	for( int i = 0; i < (1 << (n*m)) ; i++ )
	{
		int sum = 0;
		for( int r = 0; r < n; r++ ) // 가로 계산
		{
			int cur = 0;
			for( int c = 0; c < m; c++ )
			{
				if( (i & (1 << (r*m + c))) == 0 )
					cur = ( cur * 10 ) + paper[r][c];
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		for( int c = 0; c < m; c++ ) // 세로 계산
		{
			int cur = 0;
			for( int r = 0; r < n; r++ )
			{
				if( (i & (1 << (r*m + c))) != 0 )
					cur = ( cur * 10 ) + paper[r][c];
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		if(sum > best)
			best = sum;
	}
	cout << best << "\n";
	return 0;
}