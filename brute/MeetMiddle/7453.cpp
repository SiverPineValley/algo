// 합이 0인 네 정수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	vector<long long> a(n), b(n), c(n), d(n);
	long long ans = 0;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	vector<int> first, second;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			first.push_back(a[i] + b[j]);
			second.push_back(c[i] + d[j]);
		}
	sort(second.begin(), second.end());
	for (int i = 0; i < first.size(); i++)
	{
        auto p = equal_range(second.begin(), second.end(), -1 * first[i]);
        ans += p.second - p.first;
    }
	cout << ans << '\n';
	return 0;
}