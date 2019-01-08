#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int calculate(vector<int> &v)
{
	int sum = 0;
	for(int i = 1; i < v.size(); i++)
		sum += abs(v[i] - v[i-1]);
	return sum;
}

int main(void)
{	
	int n, ans;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(),v.end());
	do
	{
		int temp = calculate(v);
		ans = max(ans, temp);
	} while(next_permutation(v.begin(),v.end()));
	cout << ans << "\n";
	return 0;
}