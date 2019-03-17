// DSLR
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(void)
{
	int T;
	cin >> T;
	while(T--)
	{
		int a, b;
		cin >> a >> b;
		queue<int> q;
		vector<int> from(10001);
		vector<char> how(10001);
		vector<bool> check(10001);
		check[a] = true;
		q.push(a);

		while(!q.empty())
		{
			int now = q.front();
			int next;
			q.pop();

			// D
			next = (now * 2) % 10000;
			if(check[next] == false)
			{
				check[next] = true;
				q.push(next);
				from[next] = now;
				how[next] = 'D';
			}
			// S
			next = (now - 1);
			if(next == -1) next = 9999;
			if(check[next] == false)
			{
				check[next] = true;
				q.push(next);
				from[next] = now;
				how[next] = 'S';
			}
			// L
			next = ((now % 1000) * 10) + now/1000;
			if(check[next] == false)
			{
				check[next] = true;
				q.push(next);
				from[next] = now;
				how[next] = 'L';
			}
			// R
			next = (now/10) + ((now % 10) * 1000);
			if(check[next] == false)
			{
				check[next] = true;
				q.push(next);
				from[next] = now;
				how[next] = 'R';
			}
		}
		string ans = "";
		while(b != a)
		{
			ans += how[b];
			b = from[b];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
	return 0;
}