// 퍼즐
#include <map>
#include <queue>
#include <iostream>
#include <string>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main(void)
{
	queue<int> q;
	map<int, int> d;
	int start = 0;
	for(int i = 0; i < 9; i++)
	{
		int t;
		cin >> t;
		if(t == 0) t = 9;
		start = (start * 10) + t;
	}
	q.push(start);
	d[start] = 0;

	while(!q.empty())
	{
		int now_num = q.front();
		string now = to_string(now_num);
		q.pop();
		int z = now.find('9');
		int x = z / 3;
		int y = z % 3;
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
			{
				string next = now;
				swap(next[x*3+y], next[nx*3+ny]);
				int num = stoi(next);
				if(d.count(num) == 0)
				{
					d[num] = d[now_num] + 1;
					q.push(num);
				}
			}
		}
	}
	if(d.count(123456789) == 0) cout << -1 << "\n";
	else cout << d[123456789] << "\n";
	return 0;
}