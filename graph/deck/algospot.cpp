// 1261
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <deque>
#include <utility>
using namespace std;
int nx[4] = {1,0,-1,0};
int ny[4] = {0,1,0,-1};
int main(void)
{
	int n, m; // n이 세로, m이 가로
	int map[101][101];
	int w[101][101];
	deque<pair<int,int>> d;
	cin >> m >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%1d",&map[i][j]);
			w[i][j] = -1;
		}
	}
	d.push_front(make_pair(1,1));
	w[1][1] = 0;

	while(!d.empty())
	{
		int cx = d.front().first;
		int cy = d.front().second;
		d.pop_front();
		for(int i = 0; i < 4; i++)
		{
			int dx = cx+nx[i];
			int dy = cy+ny[i];
			if(0 < dx && dx <= m && 0 < dy && dy <= n)
			{
				if( (map[dy][dx] == 0) && (w[dy][dx] == -1) )
				{
					w[dy][dx] = w[cy][cx];
					d.push_front(make_pair(dx, dy));
				}
				else if( (map[dy][dx] == 1) && (w[dy][dx] == -1) )
				{
					w[dy][dx] = w[cy][cx] + 1;
					d.push_back(make_pair(dx, dy));
				}
			}
		}
	}
	cout << w[n][m] << "\n";
	return 0;
}