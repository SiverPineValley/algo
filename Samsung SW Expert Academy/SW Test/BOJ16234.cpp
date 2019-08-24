// 인구이동
#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>

using namespace std;

#define MAX 4

int n, l, rr;
int map[51][51];
bool flag = true;
bool visited[51][51];

int dr[MAX] = {-1,0,1,0};
int dc[MAX] = {0,1,0,-1};
queue<pair<int, int>> q, nq;

bool check(int r, int c)
{
	for (int k = 0; k < MAX; k++)
	{
		int nr = r + dr[k];
		int nc = c + dc[k];
		if (nr<0 || nr >= n || nc<0 || nc >= n) continue;
		if (abs(map[r][c] - map[nr][nc]) >= l && abs(map[r][c] - map[nr][nc]) <= rr)
			return true;
	}
	return false;
}
bool check2(int r, int c, int nr, int nc)
{
	if (abs(map[r][c] - map[nr][nc]) >= l && abs(map[r][c] - map[nr][nc]) <= rr)
		return true;
	else return false;
}
void bfs(int r, int c)
{
	q.push({ r,c });
	visited[r][c] = true;
	int sum = 0, cnt = 0, people;
	nq.push({ r,c });
	while (!q.empty())
	{
		r = q.front().first;
		c = q.front().second;
		q.pop();
		sum += map[r][c];
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (0 <= nr && nr < n && 0 <= nc && nc < n)
			{
				if (!visited[nr][nc] && check2(r,c,nr, nc))
				{
					visited[nr][nc] = true;
					q.push({ nr,nc });
					nq.push({ nr,nc });
				}
			}
		}
	}
	people = sum / cnt;

	while (!nq.empty()) {
		r = nq.front().first;
		c = nq.front().second;
		nq.pop();
		map[r][c] = people;
	}
}

int main(void)
{
	scanf("%d %d %d", &n, &l, &rr);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	int ans = 0;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (!visited[i][j] && check(i, j))
				{
					bfs(i,j);
					flag = true;
				}
		memset(visited, false, sizeof(visited));
		if (flag) ans++;
	}
	printf("%d\n", ans);
	return 0;
}