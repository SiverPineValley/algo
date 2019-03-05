// 14889
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int main(void)
{
	int n;
	int best = 100000;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	vector<int> b(n);
	for(int i = 0; i < n/2; i++)
		b[i] = 1;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> a[i][j];
	sort(b.begin(), b.end());
	do
	{
		vector<int> first, second;
		int temp = 0;
		int temp2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (b[i] == 0)
                first.push_back(i);
			else
                second.push_back(i);
		}
		for (int i=0; i<n/2; i++)
		{
			for (int j=0; j<n/2; j++)
			{
				if (i == j) continue;
				temp += a[first[i]][first[j]];
				temp2 += a[second[i]][second[j]];
			}
		}
		int r = abs( temp - temp2 );
		if( r < best )
			best = r;
	} while(next_permutation(b.begin(), b.end()));
	cout << best << "\n";
	return 0;
}