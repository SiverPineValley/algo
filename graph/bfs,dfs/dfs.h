#include<iostream>
using namespace std;
bool check[10000];
int a[10000][10000];

// 인접 행렬을 이용한 구현
void dfs_array(int x)
{
	check[x] = true;
	cout << x << " ";
	for(int i = 1; i <= n; i++)
	{
		if(a[x][i] == 1 && check[i] == false)
			dfs(i);
	}
}

// 인접 리스트를 이용한 구현
void dfs_list(int x)
{
	check[x] = true;
	cout << x << "\n";
	for(int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		if(check[y] == false)
			dfs(y);
	}
}