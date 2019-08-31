// 낚시왕
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <utility>
using namespace std;

struct shark
{
	int x;
	int y;
	int speed;
	int direction; // 위, 아래, 오른쪽, 왼쪽
	int size;
};

shark field[101][101];
queue<shark> sharks;
int r, c, m, fisherman = 0, ans = 0;

void clear(int x, int y)
{
	field[y][x].x = 0;
	field[y][x].y = 0;
	field[y][x].speed = 0;
	field[y][x].direction = 0;
	field[y][x].size = 0;
}

shark initialize(int x, int y, int speed, int direction, int size)
{
	shark newShark = {x,y,speed,direction,size};
	return newShark;
}

void catch_shark()
{
	for(int y = 1; y <= r; y++)
	{
		if(field[y][fisherman].direction > 0)
		{
			ans += field[y][fisherman].size;
			clear(fisherman,y);
			break;
		}
	}
}

void move_shark()
{
	// 상어 이동
	map<pair<int,int>,shark> move;
	while( !sharks.empty() )
	{
		auto first = sharks.front();
		sharks.pop();
		if(field[first.y][first.x].direction == 0) continue;
		
		clear(first.x, first.y);
		
		shark moved;
		// 위, 아래
		if(first.direction == 1 || first.direction == 2)
		{
			int many = first.speed, cx = first.x, cy = first.y;
			int nx = cx, ny = cy;

			many  %= (2 * (r - 1)); // 이쉑 안써서 틀렸었음

			while(many--)
			{
				if(first.direction == 1) ny  = cy - 1;
				else ny  = cy + 1;

				if(ny < 1 || ny > r)
				{
					first.direction = 3 - first.direction;
					many++;
					continue;
				}
				cy = ny;
			}
			moved = initialize(cx, cy, first.speed, first.direction, first.size);
		}
		// 오른쪽, 왼쪽
		else if(first.direction == 3 || first.direction == 4)
		{
			int many = first.speed, cx = first.x, cy = first.y;
			int nx = cx, ny = cy;

			many  %= (2 * (c - 1));

			while(many--)
			{
				if(first.direction == 3) nx  = cx + 1;
				else nx  = cx - 1;

				if(nx < 1 || nx > c)
				{
					first.direction = 7 - first.direction;
					many++;
					continue;
				}
				cx = nx;
			}
			moved = initialize(cx, cy, first.speed, first.direction, first.size);
		}

		auto finded = move.find(make_pair(moved.x,moved.y));
		if(finded->second.x == moved.x && finded->second.y == moved.y && finded->second.direction != 0)
		{
			if(finded->second.size < moved.size)
			{
				move[pair<int,int> (moved.x,moved.y)] = moved;
			}
		}
		else move.insert(make_pair(make_pair(moved.x, moved.y), moved));
	}

	// 실제 map에 배치
    for(auto iter = move.begin(); iter != move.end(); ++iter)
    {
    	field[iter->second.y][iter->second.x].x = iter->second.x;
    	field[iter->second.y][iter->second.x].y = iter->second.y;
    	field[iter->second.y][iter->second.x].size = iter->second.size;
    	field[iter->second.y][iter->second.x].speed = iter->second.speed;
    	field[iter->second.y][iter->second.x].direction = iter->second.direction;
    	sharks.push(iter->second);
    }
        
}

void simulation()
{
	while( ++fisherman <= c )
	{
		// 가장 가까운 상어 잡기
		catch_shark();
		// 상어 이동시키기
		move_shark();
	}
}

int main(void)
{
	// 초기화와 입력
	memset(field, 0, sizeof(field));
	cin >> r >> c >> m;

	for(int num = 0; num < m; num++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		field[r][c].x = c;
		field[r][c].y = r;
		field[r][c].speed = s;
		field[r][c].direction = d;
		field[r][c].size = z;
		sharks.push({c,r,s,d,z});
	}

	simulation();

	cout << ans << "\n";

	return 0;
}