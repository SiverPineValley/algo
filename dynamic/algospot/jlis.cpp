// 합친 LIS
// 종만's 답
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int N, M;
vector<int> A;
vector<int> B;
vector<vector<int>> dp;
long long MIN = LLONG_MIN;

int solve(int indA, int indB) {
	if (N <= indA || M <= indB) return -1;
	int& ret = dp[indA + 1][indB + 1];
	if (ret != -1) return ret;
	ret = 2;

	long long a = (indA == -1) ? MIN : A[indA];
	long long b = (indB == -1) ? MIN : B[indB];

	long long maxNum = max(a, b); 

	for (int i = indA + 1; i < N; i++) {
		if (maxNum >= A[i]) continue;
		ret = max(ret, solve(i, indB) + 1);
	}
	for (int i = indB + 1; i < M; i++) {
		if (maxNum >= B[i]) continue;
		ret = max(ret, solve(indA, i) + 1);
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> N >> M;

		A = vector<int>(N);
		B = vector<int>(M);
		dp = vector<vector<int>>(N + 1, vector<int>(M + 1, -1));

		for (int i = 0; i < N; i++) cin >> A[i];
		for (int i = 0; i < M; i++) cin >> B[i];

		cout << solve(-1, -1) - 2 << endl; 
	}
	return 0;
}