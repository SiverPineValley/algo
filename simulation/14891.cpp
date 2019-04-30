// 톱니바퀴
#include <iostream>
#include <cstdio>
using namespace std;

// 각 톱니바퀴의 극
int toothed[4][8];
// k번의 원호와 방향
int dir[100][2];
int k;

void rotate(int* temp)
{
	for(int i = 0; i < 4; i++)
	{
		if(temp[i] == 1)
		{
			int m = toothed[i][7];
			for(int j = 6; j >= 0; j--)
				toothed[i][j+1] = toothed[i][j];
			toothed[i][0] = m;
		}
		else if(temp[i] == -1)
		{
			int m = toothed[i][0];
			for(int j = 1; j < 8; j++)
				toothed[i][j-1] = toothed[i][j];
			toothed[i][7] = m;
		}
	}
}

int main(void)
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 8; j++)
			scanf("%1d",&toothed[i][j]);
	cin >> k;
	for(int i = 0; i < k; i++)
		cin >> dir[i][0] >> dir[i][1];

	// K번 회전
	for(int i = 0; i < k; i++)
	{
		int temp[4];
		int target = dir[i][0];
		temp[target-1] = dir[i][1];
		// 1번을 돌릴 때
		if(target == 1)
		{
			if(toothed[0][2] == toothed[1][6]) temp[1] = temp[2] = temp[3] = 0;
			else{
				temp[1] = temp[0] * (-1);
				if(toothed[1][2] == toothed[2][6]) temp[2] = temp[3] = 0;
				else
				{
					temp[2] = temp[0];
					if(toothed[2][2] == toothed[3][6]) temp[3] = 0;
					else temp[3] = temp[1];
				}
			}
		}
		else if(target == 4)
		{
			if(toothed[3][6] == toothed[2][2]) temp[0] = temp[1] = temp[2] = 0;
			else{
				temp[2] = temp[3] * (-1);
				if(toothed[2][6] == toothed[1][2]) temp[0] = temp[1] = 0;
				else
				{
					temp[1] = temp[3];
					if(toothed[1][6] == toothed[0][2]) temp[0] = 0;
					else temp[0] = temp[2];
				}
			}
		}
		else if(target == 2)
		{
			if(toothed[1][6] == toothed[0][2]) temp[0] = 0;
			else temp[0] = temp[1] * (-1);

			if(toothed[1][2] == toothed[2][6]) temp[2] = temp[3] = 0;
			else
			{
				temp[2] = temp[1] * (-1);
				if(toothed[2][2] == toothed[3][6]) temp[3] = 0;
				else temp[3] = temp[1];
			}
		}
		else
		{
			if(toothed[2][2] == toothed[3][6]) temp[3] = 0;
			else temp[3] = temp[2] * (-1);

			if(toothed[2][6] == toothed[1][2]) temp[1] = temp[0] = 0;
			else
			{
				temp[1] = temp[2] * (-1);
				if(toothed[0][2] == toothed[1][6]) temp[0] = 0;
				else temp[0] = temp[2];
			}
		}
		rotate(temp);
	}

	// 점수 계산
	int ans = 0;
	for(int i = 0; i < 4; i++)
	{
		// cout << toothed[i][0] << " ";
		int temp = 1;
		if(toothed[i][0] == 1) temp = temp << (i);
		else temp = 0;
		ans += temp;
	}
	// cout << "\n";
	cout << ans << "\n";

	return 0;
}