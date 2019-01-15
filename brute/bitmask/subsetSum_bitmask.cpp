//1182
//백준's 코드
#include<iostream>
#include<vector>
using namespace std;
int main(void)
{	
	int N, S;
	int ans = 0;
	vector<int> subset;
	cin >> N >> S;
	subset.resize(N);
	for(int i = 0; i < N; i++)
		cin >> subset[i];
	for(int i=1; i<(1<<N); i++)
	{
		int sum = 0;
		for(int j = 0; j<N; j++)
		{
			if(i&(1<<j)) sum += subset[j];
		}
		if(sum == S) ans++;
	}
	cout << ans << "\n";
	return 0;
}