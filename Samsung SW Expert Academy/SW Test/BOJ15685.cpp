// 드래곤 커브
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct curve
{
	int x;
	int y;
	int gen;
	int dir;
};

int n;
int map[101][101];
// 오위왼아
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

// 답 개수 세기
void countSqaure()
{
	int ans = 0;
	for(int y = 0; y < 100; y++)
	{
		for(int x = 0; x < 100; x++)
		{
			if(map[y][x] == 1 && map[y][x+1] == 1 && map[y+1][x] == 1 && map[y+1][x+1] == 1) ans++;
		}
	}
	printf("%d", ans);
}

void simulation(int x, int y, int d, int g)
{
	vector<int> curves;
	int cx = x, cy = y, nx, ny;
	curves.push_back(d);

	// 각각 Gen까지
	for(int gen = 0; gen < g; gen++)
	{
		int size = curves.size();
		for(int s = size - 1; s >= 0; s--)
		{
			int nextCurve = (curves[s] + 1) % 4;
			nx = cx + dx[nextCurve]; ny = cy + dy[nextCurve];

			map[ny][nx] = 1;
			cx = nx;
			cy = ny;

			curves.push_back(nextCurve);
		}
	}
}

int main(void)
{
	memset(map, 0, sizeof(map));
	scanf("%d", &n);
	for(int num = 0; num < n; num++)
	{
		int tempX, tempY, tempDir, tempGen, nx, ny;
		scanf("%d %d %d %d", &tempX, &tempY, &tempDir, &tempGen);

		// 방금 입력 받은거 맵에 표시
		map[tempY][tempX] = 1;
		nx = tempX + dx[tempDir]; ny = tempY + dy[tempDir];
		map[ny][nx] = 1;

		// 각각 시뮬레이션
		simulation(nx, ny, tempDir, tempGen);
	}
	
	countSqaure();
	return 0;
}