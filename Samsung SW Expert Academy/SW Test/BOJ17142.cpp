// 연구소3
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

#define MAXMAPSIZE 50

// 연구소 크기, 활성화 가능 바이러스 개수
int n, m, numOfVirus;
int map[MAXMAPSIZE][MAXMAPSIZE];
vector<pair<int,int>> virus;
int result = 2501;
int blankMap = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void simulation(int simMap[MAXMAPSIZE][MAXMAPSIZE], queue<pair<int,int>> virusLoc)
{
	int ans = 0;
	int prevblank = 0, blank = 0;
	int turn = virusLoc.size();
	while(!virusLoc.empty())
	{
		int cx = virusLoc.front().first;
		int cy = virusLoc.front().second;
		simMap[cy][cx] = 3;
		turn--;
		virusLoc.pop();
		for(int index = 0; index < 4; index++)
		{
			int nx = cx + dx[index], ny = cy + dy[index];
			if( 0 <= nx && nx < n && 0 <= ny && ny < n )
			{
				if(simMap[ny][nx] == 0 || simMap[ny][nx] == 2)
				{
					if(simMap[ny][nx] == 0) blank++;
					simMap[ny][nx] = 3;
					virusLoc.push(make_pair(nx,ny));
				}
			}
		}
		if(turn == 0)
		{
			turn = virusLoc.size();
			if(prevblank != blank)
			{
				prevblank = blank;
				ans++;
			}
		}
	}

	if(blank == blankMap)
		if(ans < result) result = ans;
}

void bfs(int stage, queue<pair<int,int>> virusLoc, int startLoc)
{
	if(stage == m)
	{
		int tempMap[MAXMAPSIZE][MAXMAPSIZE];
		memcpy(tempMap,map,sizeof(map));
		simulation(tempMap, virusLoc);
		return;
	}

	for(int index = startLoc; index < numOfVirus; index++)
	{
		queue<pair<int,int>> tempQ = virusLoc;
		tempQ.push(virus.at(index));
		bfs(stage + 1, tempQ, startLoc + 1);
	}
}

int main(void)
{
	// 입력 및 초기화
	cin >> n >> m;
	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < n; x++)
		{
			cin >> map[y][x];
			// 바이러스의 위치 기록
			if(map[y][x] == 2)
			{
				virus.push_back(make_pair(x,y));
				numOfVirus++;
			}
			else if(map[y][x] == 0)
				blankMap++;
		}
	}

	queue<pair<int,int>> tempVirusLoc;
	bfs(0, tempVirusLoc, 0);
	if(result == 2501) result = -1;
	cout << result << "\n";
	return 0;
}