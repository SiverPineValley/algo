// 사다리 조작
#include <iostream>
#include <cstring>
using namespace std;

// 세로선의 개수 N, 가로선의 개수 M, 세로선마다 가로선을 놓을 수 있는 위치의 개수 H
int n, m, h, result = 4, ladder;
int map[31][31];

// Debug - Print Map
void printMap(int map[31][31])
{
	for(int i = 1; i <= h; i++)
	{
		for(int j = 1; j <= n; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
}

// Test 성공인지 확인
bool simulation(int map[31][31])
{
	// 각 가로
	for(int i = 1; i <= n; i++)
	{
		int x = i;
		int y = 1;// 0: 왼쪽, 1: 오른쪽
		// 하나씩 내려가면서 확인
		for(; y <= h; y++)
		{
			if(map[y][x] == 0)
				continue;
			if(x == 1)
				x += 1;
			else if(x == n)
				x -= 1;
			else
			{
				if(map[y][x-1] == map[y][x])
					x -= 1;
				else
					x += 1;
			}
		}
		// cout << "x: " << x << " i: " << i << "\n";
		if(x != i) return false;
	}
	return true;
}

// Backtracking Function
void solve(int t_map[31][31], int cnt, int ladder)
{
	if(result <= cnt) return;		// cnt가 result와 같거나 크면, 그냥 return
	if(simulation(t_map) == 1)		// simulation 결과 성공적이면, result = cnt 이후 return
	{
		result = cnt;
		return;
	}
	else if(cnt == 3) return;
	for(int i = 1; i <= h; i++)		// simulation이 만족하지 못했으면, Backtracking
	{
		for(int j = 1; j < n;)
		{
			if(t_map[i][j] != 0) j += 2;			// 현재 탐색한 곳이 0이 아니면 x 2만큼 우로 이동
			else
			{
				if(t_map[i][j+1] != 0) j += 3;		// 다음 위치가 0이 아니면 x 3만큼 우로 이동
				else
				{
					t_map[i][j] = t_map[i][j+1] = ladder; cnt++; ladder++;	// 둘 다 0이면 사다리를 놓는다.
					solve(t_map, cnt, ladder);
					t_map[i][j] = t_map[i][j+1] = 0; cnt--; ladder--;		// Backtracking을 위해 사다리 뺀다.
					j += 1;													// x 1만큼 우로 이동
				}
			}
		}
	}
}

int main(void)
{
	// 초기화 및 입력
	memset(map,0,sizeof(map));
	cin >> n >> m >> h;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> y >> x;
		map[y][x] = i+1;
		map[y][x+1] = i+1;
		ladder = i+1;
	}
	solve(map, 0, ladder);
	if(result == 4) result = -1;
	cout << result << "\n";

	return 0;
}