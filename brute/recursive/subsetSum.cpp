// 1182
// 백준's 코드
#include <iostream>
#include <vector>
using namespace std;
vector<int> subset;
int ans = 0;
int N, S;
void subsetSum(int i, int sum)
{
	if(i == N)
	{
		if(sum == S)
			ans++;
		return;
	}
	subsetSum(i+1,sum+subset[i]);
	subsetSum(i+1,sum);
}

int main(void)
{	
	cin >> N >> S;
	subset.resize(N);
	for(int i = 0; i < N; i++)
		cin >> subset[i];
	subsetSum(0,0);
	if(S == 0) ans--;	// 공집합 제외
	cout << ans << "\n";
	return 0;
}