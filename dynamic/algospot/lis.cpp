// 최대 증가 부분 수열
#include <iostream>
#include <cstring>

#define MAX(A, B) A > B ? A : B

using namespace std;

int n;
int numList[500], cache[500];

int dp(int start)
{
	int& ref = cache[start];
	if(ref != -1) return ref;

	ref = 1;

	for(int end = start + 1; end < n; end++)
		if(numList[end] > numList[start])
			ref = MAX(ref, dp(end) + 1);
	return ref;
}

int main(void)
{

	int c;
	cin >> c;
	while(c--)
	{
		cin >> n;
		memset(cache, -1, sizeof(cache));
		for(int i = 0; i < n; i++)
			cin >> numList[i];
		

		int ans = 0;
		for(int i = 0; i < n; i++)
			ans = MAX(ans, dp(i));
		cout << ans << "\n";
	}

	return 0;
}