// 사다리 조작
#include <iostream>
#include <utility>
#include <cstring>
using namespace std;

// 세로선의 개수 N, 가로선의 개수 M, 세로선마다 가로선을 놓을 수 있는 위치의 개수 H
int n, m, h;
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
	}


	
	// printMap(map);

	return 0;
}