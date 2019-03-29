// 동전2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> d(10001, -1);

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	d[0] = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= k; j++)
			if( j - a[i] >= 0 )
				if( ( d[j] == -1 || d[j] > d[j-a[i]]+1 ) && ( d[j - a[i]] != -1 ) ) d[j] = d[j-a[i]] + 1;

	cout << d[k] << "\n";
	return 0;
}