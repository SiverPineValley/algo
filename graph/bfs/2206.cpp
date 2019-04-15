// 벽 부수고 이동하기
#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int map[1001][1001];
int w[1001][1001][2];
int main(void)
{
	int n, m; // n이 세로, m이 가로
	scanf("%d %d",&n,&m);
	queue<tuple<int,int,int>> q;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%1d",&map[i][j]);
		}
	}
	q.push(make_tuple(1,1,0));
	w[1][1][0] = 1;

	while(!q.empty())
	{
		int cx, cy, cb;
		tie(cx,cy,cb) = q.front();
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = cx+dx[i];
			int ny = cy+dy[i];
			if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
			if( (map[ny][nx] == 0) && (w[ny][nx][cb] == 0) )
			{
				w[ny][nx][cb] = w[cy][cx][cb] + 1;
				q.push(make_tuple(nx,ny,cb));
			}
			else if( (map[ny][nx] == 1) && (cb == 0) && (w[ny][nx][cb] == 0) )
			{
				w[ny][nx][1] = w[cy][cx][cb] + 1;
				q.push(make_tuple(nx,ny,1));
			}
		}

	}

	if(w[n][m][0] != 0 && w[n][m][1] != 0)
	{
	cout << min(w[n][m][0], w[n][m][1]);
	}
	else if (w[n][m][0] != 0)
	{
	cout << w[n][m][0];
	}
	else if (w[n][m][1] != 0)
	{
	cout << w[n][m][1];
	}
	else
	{
	cout << -1;
	}
	cout << '\n';
	return 0;
}