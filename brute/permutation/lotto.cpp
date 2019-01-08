// 6603
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	while(n)
	{
		vector<int> a(n);
		vector<int> b(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			if(i >= 6) b[i] = 1;
			else b[i] = 0;
		}
		do
		{
			for(int i = 0; i < n; i++)
			{
				if(b[i] == 0) cout << a[i] << " ";
			}
			cout << "\n";
		} while(next_permutation(b.begin(),b.end()));
		cout << "\n";
		cin >> n;
	}
	return 0;
}