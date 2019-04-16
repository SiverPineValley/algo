// 말이 되고픈 원숭이
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
// 말의 움직임
int hx[] = {2, 1, 2, 1, -2, -1, -2, -1};
int hy[] = {1, 2, -1, -2, -1, -2, 1, 2};
// 그냥 움직임
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
// 말의 움직임 횟수, 가로, 세로
int k, w, h;
int map[200][200];
int check[200][200][31];
queue<tuple<int,int,int>> q;

int main(void)
{
	cin >> k >> w >> h;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			cin >> map[i][j];
	memset(check, -1, sizeof(check));
	q.push(make_tuple(0,0,0));
	check[0][0][0] = 0;

	while(!q.empty())
	{
		int cx, cy, ch, nx, ny, nh;
		tie(cx, cy, ch) = q.front();
		nh = ch + 1;
		q.pop();
		for(int i = 0; i < 8; i++)
		{
			nx = cx + hx[i];
			ny = cy + hy[i];
			if( nx < 0 || nx >= w || ny < 0 || ny >= h || nh > k ) continue;
			if( map[ny][nx] != 1 && check[ny][nx][nh] == -1 )
			{
				check[ny][nx][nh] = check[cy][cx][ch] + 1;
				q.push(make_tuple(nx,ny,nh));
			}
		}
		for(int i = 0; i < 4; i++)
		{
			nx = cx + dx[i];
			ny = cy + dy[i];
			if( nx < 0 || nx >= w || ny < 0 || ny >= h || ch > k ) continue;
			if( map[ny][nx] != 1 && check[ny][nx][ch] == -1 )
			{
				check[ny][nx][ch] = check[cy][cx][ch] + 1;
				q.push(make_tuple(nx,ny,ch));
			}
		}
	}

	int ans = -1;
	for(int i = 0; i <= k; i++)
	{
		if(ans == -1) ans = check[h-1][w-1][i];
		else if(ans > check[h-1][w-1][i] && check[h-1][w-1][i] != -1) ans = check[h-1][w-1][i];
	}
	cout << ans << "\n";
	return 0;
}

