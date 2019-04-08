// 플레이리스트
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

/*
	모든 노래를 플레이리스트에 추가해야 한다.
	같은 노래를 추가하려면, 플레이리스트에서 두 노래 사이에 적어도 M개의 곡이 있어야 한다.
 */

// n은 저장된 노래 수, m은 같은 두 노래 사이에 존재하는 노래 수, p는 들으려는 노래 수
int n, m, p;
long long d[101][101];
long long mod = 1000000007ll;

/*
*	position은 현재 위치
*	x는 이미 추가한 노래의 수
*	y는 아직 추가하지 않은 노래의 수
*	플레이리스트를 만들 때: x = 0, y = n
*	플레이리스트를 다 만든 후: x = n, y = 0
 */
long long topdown(int position, int x, int y)
{
	// 현재 position이 들으려는 노래 수에 다다르고, 추가하지 않은 노래 수가 없을 때
	// 1을 리턴하고, 아직 y가 0이 아니면, 0을 리턴한다.
	if (position == p)
	{
		if (y == 0) return 1;
		else return 0;
	}
	
	// ans를 d[position][x]에 고정.
	long long &ans = d[position][x];

	// 이미 방문했으면 ans 리턴
	if (ans != -1) return ans;
	ans = 0;
	if (y > 0)
		ans += topdown(position+1, x+1, n - (x+1)) * y;
	if (x > m)
		ans += topdown(position+1, x, n - x) * (x-m);
	ans %= mod;
	return ans;
}

int main(void)
{
	cin >> n >> m >> p;
	memset(d,-1,sizeof(d));
	cout << topdown(0,0,n) << "\n";
	return 0;
}