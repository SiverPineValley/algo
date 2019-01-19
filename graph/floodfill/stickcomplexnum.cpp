// 2667
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<int> solution;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int map[25][25];
int bfs(int x, int y)
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
		for(int i = 0; i < 4; i++)
		{
			int nx = cx+dx[i];
			int ny = cy+dy[i];
			if( 0 <= nx && nx < n && 0 <= ny && ny < n )
			{
				if(map[nx][ny])
				{
					q.push(make_pair(nx,ny));
					map[nx][ny] = 0;
				}
			}
		}
	}
	return cnt;
}

int main(void)
{
	int cnt = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			scanf("%1d",&map[i][j]);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			if(map[i][j])
			{
				solution.push_back(bfs(i,j));
				cnt++;
			}
	}
	sort(solution.begin(), solution.end());
	cout << cnt << "\n";
	for(int i = 0; i < solution.size(); i++)
		cout << solution[i] << "\n";
	return 0;
}