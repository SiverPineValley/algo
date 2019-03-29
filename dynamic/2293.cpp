// 동전
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> d(10001);

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	d[0] = 1;
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= k; j++)
			 if(j-a[i] >= 0)
			 	d[j] += d[j-a[i]];
	cout << d[k] << "\n";
	return 0;
}