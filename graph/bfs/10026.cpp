// 적록색약
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;

int bfs(vector<string> map)
{
	// ans 는 영역의 수
	queue<pair<int,int>> q;
	vector<vector<bool>> check(n, vector<bool> (n));
	int ans = 0;

	// check가 false인 부분부터 탐색 이때 ans 값을 키워줌.
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if( !check[i][j] )
			{
				ans++;
				q.push(make_pair(j,i));
				check[i][j] = true;
				while(!q.empty())
				{
					int cx = q.front().first, cy = q.front().second;
					char cc = map[cy][cx];
					q.pop();

					// 색이 같고, false이면, 같은 영역으로 생각
					for(int i = 0; i < 4; i++)
					{
						int nx = cx + dx[i];
						int ny = cy + dy[i];
						if( nx < 0 || nx >= n || ny < 0 || ny >= n ) continue;
						if( !check[ny][nx] && cc == map[ny][nx] )
						{
							check[ny][nx] = true;
							q.push(make_pair(nx,ny));
						}
					}
				}
			}
		}
	return ans;
}

int main(void)
{
	// 일반 맵과 색약 맵
	vector<string> map(100);
	vector<string> an_map(100);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> map[i];

		// 색약 맵 생성
		an_map[i] = map[i];
		for(int j = 0; j < n; j++)
		{
			if(map[i][j] == 'G')
				an_map[i][j] = 'R';
			else
				an_map[i][j] = map[i][j];
		}
	}

	cout << bfs(map) << " ";
	cout << bfs(an_map) << "\n";
	return 0;
}