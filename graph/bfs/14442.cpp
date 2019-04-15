// 벽 부수고 이동하기 2
#include <iostream>
#include <queue>
#include <cstdio>
#include <tuple>
#include <cstring>
using namespace std;
int map[1000][1000];
int check[1000][1000][11];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(void)
{
	int n, m, k;
	scanf("%d %d %d",&n,&m, &k);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			scanf("%1d",&map[i][j]);

	queue<tuple<int,int,int>> q;
	check[0][0][0] = 1;
	q.push(make_tuple(0,0,0));

	while (!q.empty())
	{
		int cx, cy, cb;
		tie(cx,cy,cb) = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx+dx[i];
			int ny = cy+dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == 0 && check[nx][ny][cb] == 0)
			{
				check[nx][ny][cb] = check[cx][cy][cb] + 1;
				q.push(make_tuple(nx,ny,cb));
			}
			if (cb + 1 <= k && map[nx][ny] == 1 && check[nx][ny][cb+1] == 0)
			{
				check[nx][ny][cb+1] = check[cx][cy][cb] + 1;
				q.push(make_tuple(nx,ny,cb+1));
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= k; i++)
	{
		if (check[n-1][m-1][i] == 0) continue;
		if (ans == -1)
			ans = check[n-1][m-1][i];
		else if (ans > check[n-1][m-1][i])
			ans = check[n-1][m-1][i];
	}
	cout << ans << '\n';
	return 0;
}
