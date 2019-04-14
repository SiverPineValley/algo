// 양
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int r, c, sheep = 0, wolf = 0;
vector<string> map(250);
vector<vector<bool>> check(250, vector<bool> (250));
queue<pair<int,int>> q;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y)
{
	int ts = 0, tw = 0;
	q.push(make_pair(x,y));
	if(map[y][x] == 'o') ts++;
	else if(map[y][x] == 'v') tw++;
	check[y][x] = true;

	while(!q.empty())
	{
		int cx = q.front().first, cy = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			if(nx >= 0 && nx < c && ny >= 0 && ny < r)
			{
				if( !check[ny][nx] )
				{
					check[ny][nx] = true;
					if( map[ny][nx] == '.' ) q.push(make_pair(nx,ny));
					else if( map[ny][nx] == 'o' )
					{
						ts++;
						q.push(make_pair(nx,ny));
					}
					else if( map[ny][nx] == 'v' )
					{
						tw++;
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
	}
	if(ts > tw) sheep += ts;
	else wolf += tw;
}

int main(void)
{
	cin >> r >> c;
	for(int i = 0; i < r; i++)
		cin >> map[i];

	for(int i = 0; i < r; i++)
		for(int j = 0 ; j < c; j++)
		{
			if(!check[i][j])
			{
				if(map[i][j] != '#')
					bfs(j, i);
				else check[i][j] = true;
			}
		}

	cout << sheep << " " << wolf << "\n";
	return 0;
}