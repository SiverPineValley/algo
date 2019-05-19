// 뱀
// 오답인데 이유를 모름...
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

// n은 보드의 크기, k는 사과 개수, l은 뱀의 변환 횟수
int n, k, l;
int map[100][100];
queue<pair<char,int>> q;
// 뱀의 x, y, d
queue<tuple<int,int,int>> snake;

// 북(0), 동(1), 남(2), 서(3)
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void showmap(int now)
{
	int x = -1, y = -1, d = -1;
	char c;
	tie(x,y,d) = snake.front();
	if(d == 0) c = 'N';
	else if(d == 1) c = 'E';
	else if(d == 2) c = 'S';
	else c = 'W';
	cout << "now: " << now << "\n";
	cout << "Snake Head: " << x << " " << y << " " << c << "\n";
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << map[i][j]<< " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int checkDirectionChange(int curD, int curT)
{
	int nextD;
	if(curT == q.front().first)
	{
		// 왼쪽
		if(q.front().second ==  'L')
		{
			if(curD == 0) nextD = 3;
			else nextD = curD - 1;
		}
		// 오른쪽
		else
		{
			if(curD == 3) nextD = 0;
			else nextD = curD + 1;
		}
		q.pop();
		return nextD;
	}
	return curD;
}

int main(void)
{
	cin >> n >> k;
	// 맵 초기화
	memset(map,0,sizeof(map));
	// 맵에 사과 위치 입력
	for(int i = 0; i < k; i++)
	{
		int tx, ty;
		cin >> ty >> tx;
		map[ty][tx] = 1;
	}
	cin >> l;
	// 위치 변환 입력
	for(int i = 0; i < l; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		q.push(make_pair(x,c));
	}

	int length = 1;
	int cd = 1;
	int ans = 0;
	bool iseat = false;
	map[0][0] = 2;
	snake.push(make_tuple(0,0,cd));
	while(true)
	{
		// showmap(ans);
		ans++;
		int hx, hy, hd, nx, ny, nd;
		tie(hx,hy,hd) = snake.front();
		snake.pop();
		// 머리를 한 칸 움직인다.
		nx = hx + dx[hd];
		ny = hy + dy[hd];
		if(nx < 0 || nx >= n || ny < 0 || ny >= n ) // 맵을 벗어나서 종료
			break;
		else if(map[ny][nx] == 2 || map[ny][nx] == 3) // 자기 몸에 닿아서 종료 혹은 지나갔던 곳
			break;
		else if(map[ny][nx] == 1) // 몸길이를 1 증가시킨다.
		{
			iseat = true;
		}
		map[ny][nx] = 2;

		// 머리 방향 바뀌는지 체크
		nd = checkDirectionChange(hd, ans);
		snake.push(make_tuple(nx,ny,nd));
	
		// 몸이 머리 따라가게
		for(int i = 1; i < length; i++)
		{
			tie(hx,hy,nd) = snake.front();
			snake.pop();
			nx = hx + dx[nd];
			ny = hy + dy[nd];
			snake.push(make_tuple(nx,ny,hd));
			hd = nd;
			map[ny][nx] = 2;
		}

		// 사과를 먹었던 경우
		if(iseat)
		{
			length++;
			iseat = false;
			map[hy][hx] = 2;
			snake.push(make_tuple(hx,hy,hd));

		}
		// 안먹었던 경우
		else
		{
			map[hy][hx] = 0;
			// map[hy][hx] = 3;
		}
	}
	cout << ans << "\n";
	return 0;
}