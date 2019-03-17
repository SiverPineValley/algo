// 숨박꼭질4
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;


int main(void)
{
	int n, k;
	queue<int> q;
	stack<int> s;
	vector<int> from(200001);
	vector<int> dist(200001);
	vector<bool> check(200001);
	cin >> n >> k;

	// 첫 번째꺼 queue에 넣어줌
	q.push(n);
	check[n] = true;
	dist[n] = 0;
	// queue가 비워질때까지 반복
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		if((now - 1) >= 0)
			if(check[now - 1] == false)
			{
				from[now - 1] = now;
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
				q.push(now - 1);
			}
		if((now + 1) <= 200000)
			if(check[now + 1] == false)
			{
				from[now + 1] = now;
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
				q.push(now + 1);
			}
		if((now * 2) <= 200000)
			if(check[now * 2] == false)
			{
				from[now * 2] = now;
				check[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
				q.push(now * 2);
			}

	}
	cout << dist[k] << "\n";
	for(int i = k; i != n; i = from[i])
		s.push(i);
	cout << n << " ";
	while(!s.empty())
	{
		int t = s.top();
		s.pop();
		cout << t << " ";
	}
	cout << "\n";
		
	return 0;
}