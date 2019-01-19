// 1260
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int n, m, s; // 정점 개수, 간선 개수, 시작 정점 번호
vector<vector<int>> e(1001);
stack<pair<int,int>> st;
queue<int> q;

void dfs(int node)
{
	bool check[1001];
	st.push(make_pair(node,0));
	check[node] = true;
	cout << node << " ";
	while (!st.empty())
	{
		int node = st.top().first;
		int start = st.top().second;
		st.pop();
		for (int i=start; i<e[node].size(); i++)
		{
			int next = e[node][i];
			if (!check[next])
			{
				cout << next << " ";
				check[next] = true;
				st.push(make_pair(node,i+1));
				st.push(make_pair(next,0));
				break;
			}
		}
	}
	cout << "\n";
}

void bfs(int node)
{
	q.push(node);
	bool check[1001];
	check[node] = true;
	while(!q.empty())
	{
		int t = q.front();
		cout << t << " ";
		q.pop();
		for(auto it = e[t].begin(); it != e[t].end(); it++)
		{
			if(!check[*it])
			{
				q.push(*it);
				check[*it] = true;
			}
		}
		
	}
	return;
}

int main(void)
{
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		e[from].push_back(to);
		e[to].push_back(from);
	}
	for(int i = 1; i <= n; i++)
		sort(e[i].begin(), e[i].end());
	dfs(s);
	bfs(s);
	return 0;
}