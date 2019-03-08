// N-Queens
#include <iostream>
using namespace std;
int n;
int a[15][15];
bool check_col[15], check_dig[40], check_dig2[40];
int ans = 0;

bool check(int row, int col)
{
	if( check_col[col] || check_dig[row+col] || check_dig2[row-col+n] ) return false;
	return true;
}

void nqueens(int row)
{
	if( row == n )
	{
		ans += 1;
		return;
	}
	for( int col = 0; col < n; col++ )
	{
		if( check( row, col ) )
		{
			check_col[col] = true;
			check_dig[row+col] = true;
			check_dig2[row-col+n] = true;
			a[row][col] = true;
			nqueens(row+1);
			check_col[col] = false;
			check_dig[row+col] = false;
			check_dig2[row-col+n] = false;
			a[row][col] = false;
		}
	}
	return;
}

int main(void)
{
	cin >> n;
	nqueens(0);
	cout << ans << "\n";
	return 0;
}