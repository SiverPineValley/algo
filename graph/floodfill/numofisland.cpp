// 4963
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int w, h;
int dx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};
int map[50][50];
void bfs(int x, int y)
{
	int cnt = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	map[x][y] = 0;
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		cnt++;
		for(int i = 0; i < 8; i++)
		{
			int nx = cx+dx[i];
			int ny = cy+dy[i];
			if( 0 <= nx && nx < h && 0 <= ny && ny < w )
			{
				if(map[nx][ny])
				{
					q.push(make_pair(nx,ny));
					map[nx][ny] = 0;
				}
			}
		}
	}
}

int main(void)
{
	cin >> w >> h;
	while( (w != 0) && (h != 0) )
	{
		int cnt = 0;
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
				map[i][j] = 0;
		}
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
				cin >> map[i][j];
		}

		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
				if(map[i][j])
				{
					bfs(i,j);
					cnt++;
				}
		}
		cout << cnt << "\n";
		cin >> w >> h;
	}

	return 0;
}