// 2529
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void)
{
	vector<int> small(10);
	vector<int> big(10);
	for(int i = 0; i < 10; i++)
	{
		small[i] = i;
		big[i] = 9-i;
	}
	int n;
	cin >> n;
	vector<char> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	// 제일 작은 조합 찾기
	do
	{
		bool ok = true;
		for(int i = 0; (i < n) && ok; i++)
		{
			if((a[i] == '<') && (small[i] < small[i+1])) continue;
			else if((a[i] == '>') && (small[i] > small[i+1])) continue;
			else ok = false;
		}
		if(ok) break;
	} while(next_permutation(small.begin(),small.end()));

	// 제일 큰 조합 찾기
	do
	{
		bool ok = true;
		for(int i = 0; (i < n) && ok; i++)
		{
			if((a[i] == '<') && (big[i] < big[i+1])) continue;
			else if((a[i] == '>') && (big[i] > big[i+1])) continue;
			else ok = false;
		}
		if(ok) break;
	} while(prev_permutation(big.begin(),big.end()));

	// 출력
	for(int i = 0; i <= n; i++)
		cout << big[i];
	cout << "\n";

	for(int i = 0; i <= n; i++)
		cout << small[i];
	cout << "\n";
	return 0;
}