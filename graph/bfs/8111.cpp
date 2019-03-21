// 0과 1
// 백준's 코드
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
	int T;
	while(T--)
	{
		int n;
		cin >> n;
		vector<int> from(n, -1);	// 이전 기록
		vector<int> how(n, -1);		
		vector<int> dist(n, -1);	// 몇 번만에 갔는지 기록
		queue<int> q;
		q.push(1%n);
		dist[1%n] = 0;
		how[1%n] = 1;
		while(!q.empty())
		{
			int now = q.front();
			q.pop();
			for(int i = 0; i <= 1; i++)
			{
				int next = (now * 10 + i) % n;
				if(dist[next] == -1)
				{
					dist[next] = dist[now] + 1;
					from[next] = now;
					how[next] = i;
					q.push(next);
				}
			}
		}
		if(dist[0] == -1)
			cout << "BARK\n";
		else
		{
			string ans = "";
			for(int i = 0; i != -1; i = from[i])
				ans += to_string(how[i]);
			reverse(ans.begin(), ans.end());
			cout << ans << "\n";
		} 
	}	
	return 0;
}