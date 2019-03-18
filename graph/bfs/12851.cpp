// 숨박꼭질2
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	int n, k;
	cin >> n >> k;
	queue<int> q;
	vector<bool> check(200001);
	vector<int> dist(200001);
	vector<int> cnt(200001);

	check[n] = true;
	dist[n] = 0;
	cnt[n] = 1;
	q.push(n);

	while(!q.empty())
	{
		int now = q.front();
		int next;
		q.pop();

		// next =  now + 1
		next = now + 1;
		if( (next < 200000) )
		{
			if(check[next] == false)
			{
				check[next] = true;
				q.push(next);
				dist[next] = dist[now] + 1;
				cnt[next] = cnt[now];
			}
			else if(dist[next] == dist[now] + 1)
				cnt[next] += cnt[now];
		}
		// next =  now - 1
		next = now - 1;
		if( (next >= 0) )
		{
			if(check[next] == false)
			{
				check[next] = true;
				q.push(next);
				dist[next] = dist[now] + 1;
				cnt[next] = cnt[now];
			}
			else if(dist[next] == dist[now] + 1)
				cnt[next] += cnt[now];
		}
		// next =  now * 2
		next = now*2;
		if( (next < 200000) )
		{
			if(check[next] == false)
			{
				check[next] = true;
				q.push(next);
				dist[next] = dist[now] + 1;
				cnt[next] = cnt[now];
			}
			else if(dist[next] == dist[now] + 1)
				cnt[next] += cnt[now];
		}
	}
	cout << dist[k] << "\n" << cnt[k] << "\n";
	return 0;
}