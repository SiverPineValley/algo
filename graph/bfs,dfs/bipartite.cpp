// 1707
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
vector<int> check(20001);
vector<vector<int>> g(20001);
void DFSandCheck(int f, int v)
{
	stack<pair<int,int>> s;
	s.push(make_pair(f,0));
	check[f] = 1;
	while(!s.empty())
	{
		int node = s.top().first;
		int start = s.top().second;
		s.pop();
		for(int i = start; i < g[node].size(); i++)
		{
			int next = g[node][i];
			if(!check[next])
			{
				if(check[node] == 1) check[next] = 2;
				else check[next] = 1;
				s.push(make_pair(node,i+1));
				s.push(make_pair(next,0));
				break;
			}
		}
	}
}

int main(void)
{
	int k, v, e;
	cin >> k;
	while(k--)
	{
		cin >> v >> e;
        for (int i=1; i <= v; i++)
        {
            g[i].clear();
            check[i] = 0;
        }
		for(int i = 0; i < e; i++)
		{
			int from, to;
			cin >> from >> to;
			g[from].push_back(to);
			g[to].push_back(from);
		}
		for(int i = 1; i <= v; i++)
			sort(g[i].begin(), g[i].end());

        for (int i=1; i <= v; i++)
        {
            if (check[i] == 0)
            {
                DFSandCheck(i,v);
            }
        }
		bool solution = true;
		for(int i = 1; i <= v; i++)
		{
			for(int j = 0; j < g[i].size(); j++)
			{
				if( (check[i] == check[g[i][j]]) ) solution = false;
			}
		}
		if(solution) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}