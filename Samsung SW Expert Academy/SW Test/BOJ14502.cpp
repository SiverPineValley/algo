// 연구소
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

#define MAXSIZE 8

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int numOfVirusAndWall = 0;		// 초기 Map에서 Virus와 Wall의 개수
int n, m;

int simulation(int map[MAXSIZE][MAXSIZE], queue<pair<int,int>> virus)
{
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
				if(map[ny][nx] == 0)
				{
					map[ny][nx] = 2;
					virus.push(make_pair(nx,ny));
					blank++;
				}
			}
		}
	}
	return blank;
}

int main(void)
{
	cin >> n >> m;
	int map[MAXSIZE][MAXSIZE];
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

	cout << simulation(map, virus) << "\n";

	return 0;
}