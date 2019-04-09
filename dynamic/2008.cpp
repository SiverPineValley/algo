// 사다리 게임
// 백준's 코드
#include <iostream>
#include <cstring>
using namespace std;

// n은 세로 수, m은 가로 수
// a에서 b로 갈때까지의 최소 비용을 구해야 한다.
// X는 지울 때의 비용, Y는 그릴 때의 비용
int n, m, a, b, X, Y;
int p[501];
int d[501][501];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> m >> n >> a >> b >> X >> Y;
	a -= 1;
	b -= 1;
	for (int i=1; i<=n; i++)
	{
		cin >> p[i];
		p[i] -= 1;
	}
	for (int i=1; i<=n; i++)
		for (int j=0; j<m; j++)
			d[i][j] = 1000000000;

	for (int i=0; i<m; i++)
	{
		if (i == a)
			d[0][i] = 0;
		else
			d[0][i] = abs(a - i) * Y;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<m; j++)
		{
			for (int k=0; k<m; k++)
			{
				if (k == j && (p[i] == k || p[i]+1 == k))
					if (d[i][j] > d[i-1][k] + X)
						d[i][j] = d[i-1][k] + X;
				else if ((k <= p[i] && p[i] <= j-1) || (j <= p[i] && p[i] <= k-1))
					if (d[i][j] > d[i-1][k] + (abs(k-j)-1)*Y)
						d[i][j] = d[i-1][k] + (abs(k-j)-1)*Y;
				else
					if (d[i][j] > d[i-1][k] + abs(k-j)*Y)
						d[i][j] = d[i-1][k] + abs(k-j)*Y;
			}
		}
	}
	cout << d[n][b] << '\n';
	return 0;
}