// 감시
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

// 우, 좌, 하, 상
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int map[8][8];
int row, column;
int result = 0;
// 종류, x, y
queue<tuple<int,int,int>> q;

void printMap()
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

}

int main(void)
{
	// 초기화와 입력
	queue<tuple<int,int>> fives;
	cin >> row >> column;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++)
		{
			cin >> map[i][j];
			if ( 1 <= map[i][j] && map[i][j] <= 4 ) q.push(make_tuple(map[i][j],j,i));
			else if( map[i][j] == 5 ) fives.push(make_tuple(j,i));
		}

	int fivelength = fives.size();
	// map에서 5인 것들 처리
	for(int i = 0; i < fivelength; i++)
	{
		int cx, cy, nx, ny;
		tie(cx, cy) = fives.front();
		cout << "Current: " << cx << " " << cy << "\n";
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
				cout << nx << " " << ny << "\n";
				cout << j << "\n";
				if(map[ny][nx] == 0)
				{
					map[ny][nx] = 7;
					result++;
				}
				else if(1 <= map[ny][nx] && map[ny][nx] <= 4)
					tog = 1;
				nx += dx[j];
				ny += dy[j];
			}
		}
	}
	printMap();

	return 0;
}