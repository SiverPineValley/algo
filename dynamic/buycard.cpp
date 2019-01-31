// 11052
#include <iostream>
#include <vector>
using namespace std;
vector<int> p;
int buycard(int n)
{
	vector<int> d(n+1);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			d[i] = max(d.at(i),d.at(i-j)+p.at(j));
		}
	}
	return d.at(n);
}

int main(void)
{
	int n;
	cin >> n;
	p.resize(n+1);
	for(int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	cout << buycard(n) << "\n";
	return 0;
}