// 미세먼지야 안녕!
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define MAX 51

struct locOfobject
{
	int x;
	int y;
	int value;
};

int map[MAX][MAX];
int r, c, t, ans = 0;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<locOfobject> cleaner;
queue<locOfobject> dust;

void spread()
{
	vector<locOfobject> cal;
	while(!dust.empty())
	{
		int cx = dust.front().x, cy = dust.front().y, cs = dust.front().value;
		int ns = map[cy][cx] / 5;
		dust.pop();

		int able = 0;

		for(int index = 0; index < 4; index++)
		{
			// 맵을 벗어나거나, 공기청정기가 있거나, 더할 값이 0이면 아무것도 수행하지 않는다.
			int nx = cx + dx[index], ny = cy + dy[index];
			if(nx < 1 || nx > c || ny < 1 || ny > r) continue;
			if(map[ny][nx] == -1 || ns == 0) continue;

			// 위의 조건에 걸리지 않으면, cal에 추가하고, able을 하나 더해준다.
			cal.push_back({nx,ny,ns});
			able++;
		}
		// 모든 방향을 확인한 뒤, 자기 자신의 남은 value를  cal에 추가해준다.
		cal.push_back({cx,cy,cs - ns * able});
		map[cy][cx] = 0;
	}

	// cal 계산
	for(auto calComponent : cal)
	{
		map[calComponent.y][calComponent.x] += calComponent.value;
	}
}

void clean()
{
	int cx = cleaner[0].x, cy = cleaner[0].y, toggle, up;
	int nx = cx, ny = cy;
	if(ny == 1)
	{
		toggle = 1;
		up = 1;
	}
	else
	{
		toggle = 0;
		up = 0;
	}
	while(true)
	{
		if(toggle == 0 && up == 0) ny--;
		else if(toggle == 0 && up == 1) ny++;
		else if(toggle == 1 && up == 0) nx--;
		else nx++;

		if((ny == 1 && nx == 1) || (ny == cleaner[0].y && nx == c))
		{
			toggle = 1 - toggle;
			up = 1 - up;
		}
		else if(ny == 1 && nx == c) toggle = 1 - toggle;
		else if(ny == cleaner[0].y && nx == 1)
		{
			map[cy][cx] = 0;
			break;
		}

		if(map[ny][nx] != 0)
		{
			if(map[cy][cx] != -1) map[cy][cx] = map[ny][nx];
			map[ny][nx] = 0;
		}
		cx = nx; cy = ny;
	}

	nx = cx = cleaner[1].x, ny = cy = cleaner[1].y;
	if(ny == r)
	{
		toggle = 1;
		up = 1;
	}
	else
	{
		toggle = 0;
		up = 1;
	}
	while(true)
	{
		if(toggle == 0 && up == 0) ny--;
		else if(toggle == 0 && up == 1) ny++;
		else if(toggle == 1 && up == 0) nx--;
		else nx++;

		if(ny == r && nx == c)
		{
			toggle = 1 - toggle;
			up = 1 - up;
		}
		else if((ny == r && nx == 1) || (ny == cleaner[1].y && nx == c)) toggle = 1 - toggle;
		else if(ny == cleaner[1].y && nx == 1)
		{
			map[cy][cx] = 0;
			break;
		}

		if(map[ny][nx] != 0)
		{
			if(map[cy][cx] != -1) map[cy][cx] = map[ny][nx];
			map[ny][nx] = 0;
		}
		cx = nx; cy = ny;
	}

	// queue에 다시 추가
	for(int y = 1; y <= r; y++)
		for(int x = 1; x <= c; x++)
			if(map[y][x] != -1 && map[y][x] != 0)
			{
				
				dust.push({x,y,map[y][x]});
			}
}

void simulation()
{
	while(t--)
	{
		spread();
		clean();

		if(t == 0)
		{
			// ans 계산
			for(int y = 1; y <= r; y++)
				for(int x = 1; x <= c; x++)
					if(map[y][x] != -1 && map[y][x] != 0) ans += map[y][x];
		}
	}
}

int main(void)
{
	memset(map, 0, sizeof(map));
	cin >> r >> c >> t;
	for(int y = 1; y <= r; y++)
	{
		for(int x = 1; x <= c; x++)
		{
			cin >> map[y][x];
			if(map[y][x] == -1) cleaner.push_back({x, y, -1});
			else if(map[y][x] != 0) dust.push({x, y, map[y][x]});
		}
	}

	simulation();

	cout << ans << "\n";

	return 0;
}