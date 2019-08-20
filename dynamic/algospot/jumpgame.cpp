#include <iostream>
#include <cstring>
using namespace std;

int map[100][100], n, check[100][100];

int dynamic(int curX, int curY)
{
	// 기저사례 : 벗어난 경우
	if(curX >= n || curY >= n) return 0;
	// 기저사례 : 정답
	if(curX == n - 1 && curY == n - 1) return 1;

	int& ref = check[curY][curX];
	if(ref != -1) return ref;

	// 나머지 처리
	int jump = map[curY][curX];
	int nextX = curX + jump, nextY = curY + jump;

	// 재귀호출
	return ref = (dynamic(nextX, curY) || dynamic(curX, nextY));
}

int main(void)
{
	int testCase;

	cin >> testCase;
	while(testCase--)
	{
		cin >> n;
		for(int y = 0; y < n; y++)
		{
			for(int x = 0; x < n; x++)
				cin >> map[y][x];
		}
		memset(check, -1, sizeof(check));
		
		if(dynamic(0,0) == 1) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}