// 백준's 코드
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int mod = 1000000007;
int s;
vector<int> a(3);
long long d[51][51][51][51];		// n개의 노래, numMusic(N)는 각 사람이 부른 곡의 수

long long topdown(int n, int numMusic1, int numMusic2, int numMusic3)
{
	// 남은 곡의 수가 0이고, 각 사람이 부른 노래의 남은 수가 0일때 1을 리턴, 남은 곡의 수만 0이면, 0 리턴.
	if(n == 0)
	{
		if(numMusic1 == 0 && numMusic2 == 0 && numMusic3 == 0) return 1;
		else return 0;
	}

	// 범위에 벗어나도 0 리턴
	if(numMusic1 < 0 || numMusic2 < 0 || numMusic3 < 0) return 0;
	long long &ans = d[n][numMusic1][numMusic2][numMusic3];
	
	// ans 값이 한 번이라도 방문한 값이면 ans 리턴
	if (ans != -1) return ans;
	ans = 0;

	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			for(int k = 0; k < 2; k++)
			{
				if(i + j + k <= 0) continue;
				ans += topdown(n - 1, numMusic1 - i, numMusic2 - j, numMusic3 - k);
			}
	ans %= mod;
	return ans;
}

int main(void)
{
	cin >> s >> a[0] >> a[1] >> a[2];
	memset(d,-1,sizeof(d));
	cout << topdown(s, a[0], a[1], a[2]) << "\n";
	return 0;
}