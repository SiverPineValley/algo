// 두 배열의 합
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	long long t;
	long long ans = 0;
	int n, m;
	cin >> t >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	vector<int> b(m);
	for(int i = 0; i < m; i++)
		cin >> b[i];
	vector<long long> first;
	for(int i = 0; i < n; i++)
	{
		long long sum = 0;
		for(int j = i; j < n; j++)
			first.push_back(sum += a[j]);
	}
	vector<long long> second;
	for(int i = 0; i < m; i++)
	{
		long long sum = 0;
		for(int j = i; j < m; j++)
			second.push_back(sum += b[j]);
	}
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	for (int i = 0; i < first.size(); i++)
	{
        auto p = equal_range(second.begin(), second.end(), t-first[i]);
        ans += p.second - p.first;
    }
	cout << ans << '\n';
	return 0;
}