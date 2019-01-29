// 2178
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
int ary[100][100];
int c[100][100];
void mazeSearch(int n, int m)
{
	int sx = 0;
	int sy = 0;
	if(ary[sx][sy] == 0) return;
	queue<pair<int,int>> q;
	q.push(make_pair(sx,sy));
	c[sx][sy] = 1;
	while(!q.empty())
	{
		pair<int,int> temp = q.front();
		q.pop();
		sx = temp.first;
		sy = temp.second;
		if(ary[sx][sy])
		{
			ary[sx][sy] = 0;
			if( (sx+1) < n )
			{
				if( ary[sx+1][sy] )
				{
					c[sx+1][sy] = c[sx][sy] + 1;
					q.push(make_pair(sx+1,sy));
				}
			}
			if( (sy+1) < m )
			{
				if( ary[sx][sy+1] )
				{
					c[sx][sy+1] = c[sx][sy] + 1;
					q.push(make_pair(sx,sy+1));
				}
			}
			if( (sx-1) >= 0 )
			{
				if( ary[sx-1][sy] )
				{
					c[sx-1][sy] = c[sx][sy] + 1;
					q.push(make_pair(sx-1,sy));
				}
			}
			if( (sy-1) >= 0 )
			{
				if( ary[sx][sy-1] )
				{
					c[sx][sy-1] = c[sx][sy] + 1;
					q.push(make_pair(sx,sy-1));
				}
			}
		}
	}
}

int main(void)
{
	int n, m;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%1d",&ary[i][j]);
		}
	}
	mazeSearch(n,m);
	printf("%d\n",c[n-1][m-1]);
	return 0;
}