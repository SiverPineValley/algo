// 로봇 청소기
// 백준's 코드
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int w, h;

vector<vector<int>> bfs(vector<string> &map, int sx, int sy)
{
	vector<vector<int>> dist(h, vector<int>(w,-1));
	queue<pair<int,int>> q;
	q.push(make_pair(sx,sy));
	dist[sx][sy] = 0;
	while(!q.empty())
	{
		pair<int,int> now = q.front();
		q.pop();
		int cx = now.first;
		int cy = now.second;
		for(int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (0 <= nx && nx < h && 0 <= ny && ny < w)
				if (dist[nx][ny] == -1 && map[nx][ny] != 'x') // 방문을 안했고, 가구가 아니면
				{
					dist[nx][ny] = dist[cx][cy] + 1;
					q.push(make_pair(nx,ny));
				}
		}

	}
	return dist;
}

int main(void)
{
	while(true) 							
	{
		cin >> w >> h; 										// 가로와 세로
		if (w == 0 && h == 0) break;		
		vector<string> map(h);								// 맵 받아오기.
		for(int i = 0; i < h; i++)
				cin >> map[i];

		vector<pair<int,int>> b(1); 						// 시작점과 각 지저분한 위치 기록
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 'o')
					b[0] = make_pair(i,j);
				else if (map[i][j] == '*')
					b.push_back(make_pair(i,j));
			}
		}

		int l = b.size();
		vector<vector<int>> d(l, vector<int>(l));			// 시작점과 각 지저분한 점들간의 거리를 d에 구함.
		bool ok = true;
		for (int i = 0; i < l; i++)
		{
			auto dist = bfs(map,b[i].first,b[i].second);	// 시작점과 각 지저분한 점들부터 bfs 실행.
			for (int j=0; j<l; j++)
			{
	 			d[i][j] = dist[b[j].first][b[j].second];
				if (d[i][j] == -1)							// 도달할 수 없는 점이 있으면 ok를 -1로
					ok = false;
			}
		}

		if (ok == false)									// 도달할 수 없는 점이 있으면 -1 printing하고 다음 테스트케이스로 넘어감.
		{
			cout << -1 << '\n';
			continue;
		}
		vector<int> p(l-1);
		for (int i=0; i<l-1; i++)
			p[i] = i+1;

		int ans = -1;
		do
		{
			int now = d[0][p[0]];
			for (int i=0; i<l-2; i++)
				now += d[p[i]][p[i+1]];
			if (ans == -1 || ans > now)
				ans = now;
		} while(next_permutation(p.begin(), p.end()));
		cout << ans << '\n';
	}
	return 0;
}