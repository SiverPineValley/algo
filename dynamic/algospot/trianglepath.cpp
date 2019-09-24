#include <iostream>
#include <cstring>

#define MAX(A, B) A > B ? A : B

using namespace std;

int testCase, size;
int cache[100][100];
int triangle[100][100];

int dp(int x, int y)
{
	// 기저
	if(y == (size - 1)) return triangle[y][x];

	// 메모리
	if(cache[y][x] != -1) return cache[y][x];

	return cache[y][x] = (MAX(dp(x, y + 1), dp(x + 1, y + 1))) + triangle[y][x];
}

int main(void)
{	
	cin >> testCase;

	while(testCase--)
	{
		memset(triangle, -1, sizeof(triangle));
		memset(cache, -1, sizeof(cache));
		cin >> size;
		for(int loop = 0; loop < size; loop++)
		{
			for(int index = 0; index <= loop; index++)
				cin >> triangle[loop][index];
		}

		cout << dp(0, 0) << "\n";
	}

	return 0;
}