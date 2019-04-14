// 돌 그룹
// 백준's 코드
#include <iostream>
#include <queue>
using namespace std;
bool check[1501][1501];
int sum;
void compare(int x, int y)
{
	if (check[x][y]) return;
	check[x][y] = true;
	int a[3] = {x, y, sum-x-y};
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			if (a[i] < a[j])
			{
				int b[3] = {x, y, sum-x-y};
				b[i] += a[i];
				b[j] -= a[i];
				compare(b[0], b[1]);
			}
		}
	}
}
int main(void) {
	int x, y, z;
	cin >> x >> y >> z;
	sum = x + y + z;
	if (sum % 3 != 0)
	{
		cout << 0 << '\n';
		return 0;
	}
	compare(x, y);
	if (check[sum/3][sum/3])
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
	return 0;
}
