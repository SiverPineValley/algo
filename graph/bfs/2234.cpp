// 성곽
#include <queue>
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

// n은 가로 m은 세로
int n, m, now = -1;
// 서북동남
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main(void)
{
	queue<pair<int,int>> q;
	int check[50][50];
	vector<int> size;
	cin >> n >> m;
	vector<vector<int>> map(m, vector<int> (n));
	for(int i = 0 ; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> map[i][j];
	memset(check, -1, sizeof(check));

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if( check[i][j] == -1 )
			{
				int ssize = 1;
				now += 1;
				q.push(make_pair(j,i));
				check[i][j] = now;
				while(!q.empty())
				{
					int cx = q.front().first, cy = q.front().second;
					q.pop();

					for(int k = 0; k < 4; k++)
					{
						int t = (1 << k);
						// 갈 수 있는 위치인지
						if( (t & map[cy][cx]) == 0 )
						{
							int nx = cx + dx[k];
							int ny = cy + dy[k];
							// 다음 위치가 map 범위 내인지
							if( nx >= 0 && nx < n && ny >= 0 && ny < m )
							{
								if( check[ny][nx] == -1 )
								{
									check[ny][nx] = now;
									ssize++;
									q.push(make_pair(nx,ny));
								}
							}
						}
					}
				}
				size.push_back(ssize);
			}
		}
	}

	int best = -1;
	int biggest = size[check[0][0]];

	// 인접한 것 중 더했을 때 가장 큰 놈 찾기 - 매우 비효율적인 방법
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < 4; k++)
			{
				int nx = j + dx[k];
				int ny = i + dy[k];
				if( nx >= 0 && nx < n && ny >= 0 && ny < m )
				{
					if(check[i][j] != check[ny][nx])
					{
						int s = size[check[i][j]] + size[check[ny][nx]];
						if(s > best) best = s;
					}
				}
			}
		}
	}

	for(int i = 0; i < size.size(); i++)
		if(size[i] > biggest)
			biggest = size[i];

	cout << size.size() << "\n" << biggest << "\n" << best << "\n";
	return 0;
}