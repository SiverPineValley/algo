// 부분집합의 합2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	long long ans = 0;
	int n, s;
	cin >> n >> s;
	int m = n/2;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> first(1 << m);
	for(int i = 0; i < (1 << m); i++)
		for(int j = 0; j < m; j++)
			if(i & (1 << j))
				first[i] += a[j];
	vector<int> second(1 << (n - m));
	for(int i = 0; i < (1 << (n - m)); i++)
		for(int j = 0; j < (n - m); j++)
			if(i & (1 << j))
				second[i] += a[m + j];
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	int i = 0, j = (1 << (n - m)) - 1;
	while(i < (1 << m) && j >= 0)
	{
		if(first[i] + second[j] == s)
		{
			long long c1 = 1;
			long long c2 = 1;
			i++;
			j--;
			while(i < (1 << m) && first[i] == first[i-1])
			{
				c1++;
				i++;
			}
			while(j >= 0 && second[j] == second[j+1])
			{
				c2++;
				j--;
			}
			ans += c1*c2;
		}
		else if( first[i] + second[j] < s )
			i++;
		else 	
			j--;
	}
	if (s == 0) ans -= 1;
	cout << ans << '\n';
	return 0;
}