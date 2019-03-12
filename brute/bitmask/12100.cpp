// 2048 (EASY)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int ans = 0;

int move(vector<vector<int>> &b, int d)
{
	cout << d << " \n";
	int best = 0;
	if(d == 0) // 위
	{
		for(int i = 0; i < n; i++)
		{
			bool find = false;
			queue<int> tq;
			int cur = -1;
			for(int j = n-1; j >= 0; j--)
			{
				if(b[j][i] == 0) continue;
				if(find)
				{
					if(cur == b[j][i])
					{
						b[j][i] *= 2;
						tq.push(b[j][i]);
						find = false;
					}
					else
					{
						tq.push(cur);
						cur = b[j][i];
					}
				}
				else
				{
					cur = b[j][i];
					find = true;
				}
			}
			if( ( i == n-1 ) && ( tq.back() != cur ) ) tq.push(cur);
			for(int j = 0; j < n; j++)
			{
				if(!tq.empty())
				{
					auto temp = tq.front();
					if(temp > best) best = temp;
					tq.pop();
					b[j][i] = temp;
				}
				else b[j][i] = 0;
			}
		}
	}
	else if(d == 1) // 아래
	{
		for(int i = 0; i < n; i++)
		{
			bool find = false;
			queue<int> tq;
			int cur = -1;
			for(int j = 0; j < n; j++)
			{
				if(b[j][i] == 0) continue;
				if(find)
				{
					if(cur == b[j][i])
					{
						b[j][i] *= 2;
						tq.push(b[j][i]);
						find = false;
					}
					else
					{
						tq.push(cur);
						cur = b[j][i];
					}
				}
				else
				{
					cur = b[j][i];
					find = true;
				}
			}
			if( ( i == n-1 ) && ( tq.back() != cur ) ) tq.push(cur);
			for(int j = n-1; j >= 0; j--)
			{
				if(!tq.empty())
				{
					auto temp = tq.front();
					if(temp > best) best = temp;
					tq.pop();
					b[j][i] = temp;
				}
				else b[j][i] = 0;
			}
		}
	}
	else if(d == 2) // 오른쪽
	{
		for(int i = 0; i < n; i++)
		{
			bool find = false;
			queue<int> tq;
			int cur = -1;
			for(int j = 0; j < n; j++)
			{
				if(b[i][j] == 0) continue;
				if(find)
				{
					if(cur == b[i][j])
					{
						b[i][j] *= 2;
						tq.push(b[i][j]);
						find = false;
					}
					else
					{
						tq.push(cur);
						cur = b[i][j];
					}
				}
				else
				{
					cur = b[i][j];
					find = true;
				}
			}
			if( ( i == n-1 ) && ( tq.back() != cur ) ) tq.push(cur);
			for(int j = n-1; j >= 0; j--)
			{
				if(!tq.empty())
				{
					auto temp = tq.front();
					if(temp > best) best = temp;
					tq.pop();
					b[i][j] = temp;
				}
				else b[i][j] = 0;
			}
		}
	}
	else // 왼쪽
	{
		for(int i = 0; i < n; i++)
		{
			bool find = false;
			queue<int> tq;
			int cur = -1;
			for(int j = n-1; j >= 0; j--)
			{
				if(b[i][j] == 0) continue;
				if(find)
				{
					if(cur == b[i][j])
					{
						b[i][j] *= 2;
						tq.push(b[i][j]);
						find = false;
					}
					else
					{
						tq.push(cur);
						cur = b[i][j];
					}
				}
				else
				{
					cur = b[i][j];
					find = true;
				}
			}
			if( ( i == n-1 ) && ( tq.back() != cur ) ) tq.push(cur);
			for(int j = 0; j < n; j++)
			{
				if(!tq.empty())
				{
					auto temp = tq.front();
					if(temp > best) best = temp;
					tq.pop();
					b[i][j] = temp;
				}
				else b[i][j] = 0;
			}
		}
	}
	return best;
}

int main(void)
{
	cin >> n;
	vector<vector<int>> board(n, vector<int> (n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> board[i][j];

	for(int i1 = 0; i1 < 4; i1++)
		for(int i2 = 0; i2 < 4; i2++)
			for(int i3 = 0; i3 < 4; i3++)
				for(int i4 = 0; i4 < 4; i4++)
					for(int i5 = 0; i5 < 4; i5++)
					{
						vector<vector<int>> temp(n, vector<int> (n));
						temp = board;
						move(temp,i1);
						move(temp,i2);
						move(temp,i3);
						move(temp,i4);
						int t = move(temp,i5);
						if(t > ans) ans = t;
					}
	cout << ans << "\n";
	return 0;
}