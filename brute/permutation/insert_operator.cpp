// 14888
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	int n, t = 0, max = -1000000, min = 1000000;
	cin >> n;
	vector<int> a(n);
	vector<int> o(n-1);
	vector<int> r;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < 4; i++)
	{
		int temp;
		cin >> temp;
		for(int j = 0; j < temp; j++)
		{
			o[t] = i;
			t++;
		}
	}

	do
	{
		int sum = a[0];
		for(int i = 1; i < n; i++)
		{
			if(o[i-1] == 0) sum = sum + a[i];
			else if(o[i-1] == 1) sum = sum - a[i];
			else if(o[i-1] == 2) sum = sum * a[i];
			else sum = sum / a[i];
		}
		r.push_back(sum);
	} while(next_permutation(o.begin(),o.end()));
    auto ans = minmax_element(r.begin(), r.end());
    cout << *ans.second << '\n';
    cout << *ans.first << '\n';
	return 0;
}