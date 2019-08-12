// 연구소
#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

#define MAXSIZE 8

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int map[MAXSIZE][MAXSIZE];
int numOfVirusAndWall = 0;		// 초기 Map에서 Virus와 Wall의 개수
int result = 0;
int n, m;

int simulation(queue<pair<int,int>> virus)
{
	int tempMap[MAXSIZE][MAXSIZE];
	memcpy(tempMap, map, sizeof(map));
	int blank = 0;

	while(!virus.empty())
	{
		int cx = virus.front().first;
		int cy = virus.front().second;
		virus.pop();

		for(int index = 0; index < 4; index++)
		{
			int nx = cx + dx[index];
			int ny = cy + dy[index];

			if(0 <= nx && nx < m && 0 <= ny && ny < n)
			{
				if(tempMap[ny][nx] == 0)
				{
					tempMap[ny][nx] = 2;
					virus.push(make_pair(nx,ny));
					blank++;
				}
			}
		}
	}
	return blank;
}

void bfs(queue<pair<int,int>> virus, int stage, int startY)
{
	if(stage == 3)
	{
		int sim = simulation(virus);
		int simResult = n*m - numOfVirusAndWall - sim - 3;
		if(simResult > result)
			result = simResult;
		return;
	}
	for(int y = startY; y < n; y++)
		for(int x = 0; x < m; x++)
		{
			if(map[y][x] != 0) continue;
			map[y][x] = 1;
			bfs(virus, stage + 1, y);
			map[y][x] = 0;
		}
}

int main(void)
{
	cin >> n >> m;
	queue<pair<int,int>> virus;

	for(int row = 0; row < n; row++)
	{
		for(int col = 0; col < m; col++)
		{
			cin >> map[row][col];
			if(map[row][col] == 1 || map[row][col] == 2)
			{
				numOfVirusAndWall++;
				if(map[row][col] == 2)
					 virus.push(make_pair(col,row));
			}
		}
	}

	bfs(virus, 0, 0);
	cout << result << "\n";

	return 0;
}