// 감시
#include <iostream>
#include <tuple>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

// 상, 우, 하, 좌
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int map[8][8];
int row, column;
int result = 0, objects = 0;
// 종류, x, y
vector<tuple<int,int,int>> q;

void printMap(int dummy_map[8][8])
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			cout << dummy_map[i][j] << " ";
		}
		cout << "\n";
	}

}

int nextquad(vector<int> &v)
{
	int now = 0;
	while(true)
	{
		v[now]++;
		if(v[now] == 4)
		{
			v[now] = 0;
			now++;
		}
		else
		{
			return now;
		}

		if(now == v.size())
			return now;
	}
}

int changeMap(int dummy_map[8][8], int cx, int cy, int dir)
{
	int tog = 0, ans = 0;
	int nx, ny;
	nx = cx;
	ny = cy;			
	nx += dx[dir];
	ny += dy[dir];
	while( 0 <= nx && nx < column && 0 <= ny && ny < row && tog == 0 )
	{
		if(dummy_map[ny][nx] == 0)
		{
			dummy_map[ny][nx] = 7;
			ans++;
		}
		else if(dummy_map[ny][nx] == 6) // (1 <= dummy_map[ny][nx] && dummy_map[ny][nx] <= 5) || 
			tog = 1;
		nx += dx[dir];
		ny += dy[dir];
	}
	return ans;
}

int main(void)
{
	// 초기화와 입력
	queue<tuple<int,int>> fives;
	cin >> row >> column;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++)
		{
			// cout << "i: " << i << " j: " << j << "\n";
			cin >> map[i][j];
			if ( 1 <= map[i][j] && map[i][j] <= 4 ) q.push_back(make_tuple(map[i][j],j,i));
			else if( map[i][j] == 5 ) fives.push(make_tuple(j,i));
			if ( map[i][j] != 0 ) objects++;
		}

	int fivelength = fives.size();
	// map에서 5인 것들 처리
	for(int i = 0; i < fivelength; i++)
	{
		int cx, cy, nx, ny;
		tie(cx, cy) = fives.front();
		fives.pop();
		for(int j = 0; j < 4; j++)
		{
			int tog = 0;
			nx = cx;
			ny = cy;			
			nx += dx[j];
			ny += dy[j];
			while( 0 <= nx && nx < column && 0 <= ny && ny < row && tog == 0 )
			{
				if(map[ny][nx] == 0)
				{
					map[ny][nx] = 7;
					result++;
				}
				else if(map[ny][nx] == 6) // (1 <= map[ny][nx] && map[ny][nx] <= 5) || 
					tog = 1;
				nx += dx[j];
				ny += dy[j];
			}
		}
	}
	
	if(q.size() == 0)
	{
		cout << row * column - result - objects;
		return 0;
	}
	int ans = 0;
	vector<int> quad(q.size(),0);
	// Brute-Force
	while(true)
	{
		// Dummy Map에 복사
		int dummy_map[8][8];
		memcpy(dummy_map,map,sizeof(map));

		int part_ans = 0;
		// quad에 따라 dummpy Map 계산
		for(int i = 0; i < q.size(); i++)
		{
			int cx, cy, type;
			tie(type, cx, cy) = q[i];
			if(type == 1)
			{
				part_ans += changeMap(dummy_map, cx,cy,quad[i]);
			}
			else if(type == 2)
			{
				part_ans += changeMap(dummy_map,cx,cy,quad[i]);
				if(quad[i] <= 1) part_ans += changeMap(dummy_map,cx,cy,quad[i] + 2);
				else part_ans += changeMap(dummy_map,cx,cy,quad[i] - 2);
			}
			else if(type == 3)
			{
				part_ans += changeMap(dummy_map,cx,cy,quad[i]);
				int nquad = quad[i] + 1;
				if(nquad == 4) nquad = 0;
				part_ans += changeMap(dummy_map,cx,cy,nquad);
			}
			else
			{
				part_ans += changeMap(dummy_map,cx,cy,quad[i]);
				int nquad = quad[i] + 1;
				int pquad = quad[i] - 1;
				if(nquad == 4) nquad = 0;
				if(pquad == -1) pquad = 3;
				part_ans += changeMap(dummy_map,cx,cy,nquad);
				part_ans += changeMap(dummy_map,cx,cy,pquad);
			}
		}
		// printMap(dummy_map);
		// cout << "\n";
		if(part_ans > ans) ans = part_ans;
		if(nextquad(quad) == quad.size()) break;
	}
	// printMap();
	// cout << ans << " " << result << " " << objects << "\n";
	cout << row * column - ans - result - objects << "\n";

	return 0;
}