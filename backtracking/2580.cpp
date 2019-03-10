// 스도쿠
#include <iostream>
using namespace std;
int sudoku[10][10];
int c1[10][10];
int c2[10][10];
int c3[10][10];

void fill(int z)
{	
	// 모두 채웠으면, 모두 출력하고 종료.
	if(z == 81)
	{
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				cout << sudoku[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	// 스도쿠의 x, y 좌표. 만약 해당 좌표의 값이 0이 아니면, 다음 좌표 탐색.
	int x = z/9, y = z%9;
	if(sudoku[x][y] != 0)
		fill(z+1);
	// 0이라면, i = 1 ~ 9까지 하나씩 채워보기.
	else
	{
		for(int i = 1; i <= 9; i++)
		{
			if(c1[x][i] == false && c2[y][i] == false && c3[(x/3)*3+(y/3)][i] == false)
			{
				c1[x][i] = c2[y][i] = c3[(x/3)*3+(y/3)][i] = true;
				sudoku[x][y] = i;
				fill(z+1);
				sudoku[x][y] = 0;
				c1[x][i] = c2[y][i] = c3[(x/3)*3+(y/3)][i] = false;
			}
		}
	}
}

int main(void)
{	
	// 채우기. c1은 각 행에 숫자가 채워졌는지. c2는 각 열에 숫자가 채워졌는지. c3는 각 사각형에 채워졌는지.
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];
			if(sudoku[i][j] != 0)
			{
				c1[i][sudoku[i][j]] = true;
				c2[j][sudoku[i][j]] = true;
				c3[(i/3)*3+(j/3)][sudoku[i][j]] = true;
			}
		}
	fill(0);
	return 0;
}