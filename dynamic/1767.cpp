// N-Rook II
// 백준's 코드
#include <iostream>
#include <cstring>
using namespace std;

// 체스판의 세로 크기 N, 가로 크기 M, 놓으려고 하는 룩의 수 K가 주어진다.
// N과 M과 K는 100보다 작거나 같은 자연수이다.
int n, m, k;
long long mod = 1000001ll;
long long d[101][101][101]; // nxm 행렬에 k개의 룩을 놓는 경우의 수

long long topdown(int x, int y, int numRook)
{
	// 남은 룩의 수가 0이면 1 리턴
	if( numRook == 0 ) return 1;
	// 조건에 맞지 않는 경우 0 리턴
	if( x <= 0 || y <= 0 || numRook < 0 ) return 0;
	// 아직 방문하지 않은 matrix이면, 그 값을 그대로 리턴
	if ( d[x][y][numRook] != -1 )
		return d[x][y][numRook];
	// N번 행에 놓지 않은 경우 D[N-1][M][K]
	// N에 하나 놓았고, 다른 룩에게 공격받지 않는 경우 D[N-1][M-1][K-1] * M
	// N에 두개 놓았을 경우 D[N-1][M-2][K-2] * M * (M-1) / 2
	// N에 하나 놓았고, 다른 룩에게 공격받는 경우 D[N-2][M-1][K-2] * M * (N-1)
	d[x][y][numRook] = topdown(x-1, y, numRook) +
        topdown(x-1, y-1, numRook-1)*y +
        topdown(x-1, y-2, numRook-2)*y*(y-1)/2 +
        topdown(x-2, y-1, numRook-2)*y*(x-1);
    d[x][y][numRook] %= mod;
    return d[x][y][numRook];
}

int main(void)
{
	cin >> n >> m >> k;
	memset(d,-1,sizeof(d));
	cout << topdown(n, m, k) << "\n";
	return 0;
}