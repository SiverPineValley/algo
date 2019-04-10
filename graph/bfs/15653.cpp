// 구슬 탈출4
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dx[] = {1, -1, 0, 0}; // 오른쪽, 왼쪽, 위쪽, 아래쪽
int dy[] = {0, 0, 1, -1};

// n은 가로 크기, m은 세로 크기
// r은 red, b는 blue, o는 출구
// q는 red, blue의 x,y 좌표
int n, m;
pair<int,int> b, r, o;
int nrx, nry, nbx, nby, ncnt;
int best = 1000000;
vector<string> a(10);
queue<pair<pair<int,int>,pair<int,int>>> q;
queue<int> qc;

// who가 0이면, r먼저 움직이고, 1이면 b먼저 움직인다.
void next(int crx, int cry, int cbx, int cby, int who, int dir)
{	
	int p = 1;
	if(!who)
	{
		// red
		while(true)
		{
			nrx = crx + dx[dir] * p;
			nry = cry + dy[dir] * p;
			if(nrx >= 0 && nrx < n && nry >= 0 && nry < m)
			{
				if( a[nry][nrx] == 'O' )
					break;
				else if( a[nry][nrx] == '#' )
				{
					nrx -= dx[dir];
					nry -= dy[dir];
					break;
				}
			}
		}
		// blue
		while(true)
		{
			nbx = cbx + dx[dir] * p;
			nby = cby + dy[dir] * p;
			if(nrx >= 0 && nrx < n && nry >= 0 && nry < m)
			{
				if( a[nby][nbx] == 'O' )
					break;
				else if( a[nby][nbx] == '#' || a[nby][nbx] == a[nry][nrx] )
				{
					nbx -= dx[dir];
					nby -= dy[dir];
					break;
				}
			}
		}
	}
	else
	{

	}
}

int main(void)
{
	// map 받아오기
	for(int i = 0; i < m; i++)
		cin >> a[i];

	// r, b, o 체크
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
		{
			if(a[i][j] == 'R') r = make_pair(j,i);
			else if(a[i][j] == 'B') b = make_pair(j,i);
			else if(a[i][j] == 'O') o = make_pair(j,i);
		}
	q.push(make_pair(r, b));
	qc.push(0);

	// bfs
	while(!q.empty())
	{
		int crx = q.front().first.first, cry = q.front().first.second;
		int cbx = q.front().second.first, cby = q.front().second.second;
		ncnt = qc.front();
		q.pop();
		qc.pop();
		for(int i = 0; i < 4; i++)
		{
			// 오른쪽
			if( i == 0 )
			{
				// red가 더 오른쪽
				if( crx > cbx )
					next(crx, cry, cbx, cby, 0, 0);
				else
					next(crx, cry, cbx, cby, 1, 0);
			}
			// 왼쪽
			else if( i == 1 )
			{
				// red가 더 오른쪽
				if( crx > cbx )
					next(crx, cry, cbx, cby, 1, 1);
				else
					next(crx, cry, cbx, cby, 0, 1);
			}
			else if( i == 2 )
			{
				// red가 더 아래쪽
				if( cry > cby )
					next(crx, cry, cbx, cby, 1, 2);
				else
					next(crx, cry, cbx, cby, 0, 2);
			}
			else
			{
				// red가 더 아래쪽
				if( cry > cby )
					next(crx, cry, cbx, cby, 0, 3);
				else
					next(crx, cry, cbx, cby, 1, 3);
			}
		}
	}

	cout << best << "\n";
	return 0;
}