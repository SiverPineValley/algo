#include<iostream>
#include<queue>
using namespace std;
bool check[10000];
int a[10000][10000];

// 인접 행렬을 이용한 구현
void bfs_array(int x)
{
	queue<int> q;
	check[1] = true; q.push(1);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		cout << x << " ";
		for(int i = 1; i <= n; i++)
		{
			if(a[x][i] == 1 && check[i] == false)
			{
				check[i] = true;
				q.push(i);
			}
		}
	}
}

// 인접 리스트를 이용한 구현
void bfs_list(int x)
{
	queue<int> q;
	check[1] = true; q.push(1);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		cout << x << "\n";
		for(int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if(check[y] == false)
			{
				check[y] = true
				q.push(y);
			}
		}
	}
}