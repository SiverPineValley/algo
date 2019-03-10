// 알파벳
#include <iostream>
#include <vector>
using namespace std;
vector<char> temp;
int best = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char board[20][20];
int r, c;

bool check(char c)
{
	for(auto it = temp.begin(); it != temp.end(); it++)
		if( c == *it ) return false;
	return true;
}

void alphabet(int x, int y, int cnt)
{
	int isway = 0;
	for(int n = 0; n < 4; n++)
	{
		int nx = dx[n]+x;
		int ny = dy[n]+y;
		if( ( nx >= 0 ) && ( nx <= ( c - 1 ) ) && ( ny >= 0 ) && ( ny <= ( r - 1 ) ) )
		{
			if( check(board[ny][nx]) )
			{
				isway++;
				temp.push_back(board[ny][nx]);
				alphabet(nx,ny,cnt+1);
				temp.pop_back();
			}
		}
	}
	if((isway == 0) && (cnt > best))
		best = cnt;
}

int main(void)
{
	cin >> r >> c;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			cin >> board[i][j];
	temp.push_back(board[0][0]);
	alphabet(0,0,1);
	cout << best << "\n";
	return 0;
}