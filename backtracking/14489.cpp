// 스타트와 링크
// 백준's 코드 및 recursive
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int a[20][20];
int n;

int backtracking(int index, vector<int> &first, vector<int> &second)
{
	if( index == n )
	{
		if( first.size() != n/2 ) return -1;
		if( second.size() != n/2 ) return -1;
		int t1 = 0, t2 = 0;
		for(int i = 0; i < n/2; i++)
			for(int j = 0; j < n/2; j++)
			{
				if(i == j) continue;
				t1 += a[first[i]][first[j]];
				t2 += a[second[i]][second[j]];
			}
			int d = abs(t1-t2);
			return d;
	}
	if (first.size() > n/2) return -1;
	if (second.size() > n/2) return -1;
	int ans = -1;
	first.push_back(index);
	int t1 = backtracking(index+1,first,second);
	if(ans == -1 || (t1 != -1 && ans > t1))
		ans = t1;
	first.pop_back();
	second.push_back(index);
	int t2 = backtracking(index+1,first,second);
	if(ans == -1 || (t2 != -1 && ans > t2))
		ans = t2;
	second.pop_back();
	return ans;
}

int main(void)
{
	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> a[i][j];
	vector<int> first, second;
	cout << backtracking(0, first, second) << "\n";
	return 0;
}
