// 아기 상어
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct fish {
	int x;
	int y;
	int size;
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, ans = 0, eat = 0;
int map[21][21];
fish shark, target;

bool compare(const fish &a, const fish &b){
	if(a.size < b.size) return true;
	else if(a.size == b.size)
	{
		if(a.y < b.y)
			return true;
		else if(a.y == b.y)
		{
			if(a.x < b.x)
				return true;		}	
	}

	return false;
}

int find()
{
	queue<fish> q;
	vector<fish> targets;
	int visited[21][21] = { 0, };

	q.push({shark.x,shark.y,0}); visited[shark.y][shark.x] = 1;

	while(!q.empty())
	{
		int cx = q.front().x, cy = q.front().y, cs = q.front().size;
		q.pop();
		for(int index = 0; index < 4; index++)
		{
			int nx = cx + dx[index], ny = cy + dy[index], ns = cs + 1;
			if( nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if( visited[ny][nx] == 1 ) continue;
			if( map[ny][nx] < shark.size && map[ny][nx] > 0 )
			{
				// cout << nx << " " << ny << " " << ns << "\n";
				targets.push_back({nx, ny, ns});
			}
			else if( map[ny][nx] == shark.size || map[ny][nx] == 0 )
			{
				q.push({nx,ny,ns});
			}
			visited[ny][nx] = 1;
		}
	}

	if(targets.empty()) return -1;
	sort(targets.begin(), targets.end(), compare);
	target.x = targets.front().x;
	target.y = targets.front().y;
	target.size = targets.front().size;
	return 0;
}

void simulation()
{
	while(true)
	{
		// cout << "shark: " << shark.x << " " << shark.y << " " << shark.size << " ans: " << ans << "\n";
		if(find() == -1) break;
		map[target.y][target.x] = 0;
		shark.x = target.x;
		shark.y = target.y;
		ans += target.size;
		eat++;
		if(eat == shark.size)
		{
			eat = 0;
			shark.size++;
		}


	}
}

int main(void)
{
	cin >> n;
	for(int y = 1; y <= n; y++)
	{
		for(int x = 1; x <= n; x++)
		{
			cin >> map[y][x];
			if(map[y][x] == 9)
			{
				shark.x = x; shark.y = y; shark.size = 2;
				map[y][x] = 0;
				// cout << "\n" << shark.x << " " << shark.y << "\n";
			}
		}
	}

	simulation();

	cout << ans << "\n";

	return 0;
}