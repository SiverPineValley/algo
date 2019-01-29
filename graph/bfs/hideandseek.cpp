// 1697
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int main(void)
{
	int n, k;
	int check[200001];
	int dist[200001];
	int now = -1;
	int snd;
	queue<int> q;
	cin >> n >> k;
	q.push(n);
	check[n] = 1;
	dist[n] = 0;
	while(!q.empty())
	{
		now = q.front();
		q.pop();

		if( ((now - 1) >= 0) )
		{
			if(!check[now - 1])
			{
				q.push(now - 1);
				check[now - 1] = 1;
				dist[now - 1] = dist[now] + 1;
			}
		}
		if( ((now + 1) < 200000) )
		{
			if(!check[now + 1])
			{
				q.push(now + 1);
				check[now + 1] = 1;
				dist[now + 1] = dist[now] + 1;
			}
		}
		if( ((now * 2) < 200000) )
		{
			if(!check[now*2])
			{
				q.push(now * 2);
				check[now * 2] = 1;
				dist[now * 2] = dist[now] + 1;
			}
		}
	}
	cout << dist[k] << "\n";
	return 0;
}