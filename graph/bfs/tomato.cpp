// 7576
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
int n, m; // n 세로, m 가로
int ary[100][100];
int c[100][100];
int s = 0;
queue<pair<int,int>> q;
int tomato(int sx, int sy)
{
	int final = 0;
	int th = 0;
	while(!q.empty())
	{
		pair<int,int> temp = q.front();
		q.pop();
		sx = temp.first;
		sy = temp.second;
		if(ary[sx][sy] == 1)
		{
			if( (sx+1) < n )
			{
				if( ary[sx+1][sy] == 0 )
				{
					th++;
					ary[sx+1][sy] = 1;
					c[sx+1][sy] = c[sx][sy] + 1;
					final = c[sx+1][sy];
					q.push(make_pair(sx+1,sy));
				}
			}
			if( (sy+1) < m )
			{
				if( ary[sx][sy+1] == 0 )
				{
					th++;
					ary[sx][sy+1] = 1;
					c[sx][sy+1] = c[sx][sy] + 1;
					final = c[sx][sy+1];
					q.push(make_pair(sx,sy+1));
				}
			}
			if( (sx-1) >= 0 )
			{
				if( ary[sx-1][sy] == 0 )
				{
					th++;
					ary[sx-1][sy] = 1;
					c[sx-1][sy] = c[sx][sy] + 1;
					final = c[sx-1][sy];
					q.push(make_pair(sx-1,sy));
				}
			}
			if( (sy-1) >= 0 )
			{
				if( ary[sx][sy-1] == 0 )
				{
					th++;
					ary[sx][sy-1]  = 1;
					c[sx][sy-1] = c[sx][sy] + 1;
					final = c[sx][sy-1];
					q.push(make_pair(sx,sy-1));
				}
			}
		}
	}
	if(th == s) return final;
	else return -1;
}

int main(void)
{
	int sx, sy;
	cin >> m >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> ary[i][j];
			if(ary[i][j] == 1)
			{
				sx = i;
				sy = j;
				q.push(make_pair(sx,sy));
			}
			else if(ary[i][j] == 0)
			{
				s++;
			}
		}
	}
	cout << tomato(sx,sy) << "\n";
	return 0;
}