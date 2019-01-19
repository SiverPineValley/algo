// 11724
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<vector<int>> e(1001);
bool check[1001];
void dfs(int f)
{
	stack<pair<int,int>> s;
	s.push(make_pair(f,0));
	check[f] = true;
	while(!s.empty())
	{
		int node = s.top().first;
		int start = s.top().second;
		s.pop();
		for(int i = start; i < e[node].size(); i++)
		{
			int next = e[node][i];
			if(!check[next])
			{
				check[next] = true;
				s.push(make_pair(node,i+1));
				s.push(make_pair(next,0));
				break;
			}
		}
	}
}

int main(void)
{
	int cnt = 0;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		e[from].push_back(to);
		e[to].push_back(from);
	}
	for(int i = 1; i <= n; i++)
		sort(e[i].begin(), e[i].end());
	for(int i = 1; i <= n; i++)
	{
		if(!check[i])
		{
			dfs(i);
			cnt++;
		}
	}

	cout << cnt << "\n";
	return 0;
}