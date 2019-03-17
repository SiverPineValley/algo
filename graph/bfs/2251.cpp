// 물통
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main(void)
{
	int a, b, c;
	int ca, cb, cc;
	vector<int> ans;
	queue<pair<int,int>> q;
	cin >> a >> b >> c;
	bool check[201][201];
	q.push(make_pair(0,0));
	check[0][0] = true;
	ans.push_back(c);

	while(!q.empty())
	{
		int ca = q.front().first, cb = q.front().second;
		int cc = c - (ca + cb);
		int na, nb;
		q.pop();
		// a -> b
		na = 0;
		nb = ca + cb;
		if(nb >= b)
		{
			na = nb-b;
			nb = b;
		}
		if(check[na][nb] == false)
		{
			check[na][nb] = true;
			q.push(make_pair(na,nb));
			if(na == 0)
				ans.push_back(c - nb);
		}
		// a -> c
		na = 0;
		nb = cb;
		if(check[na][nb] == false)
		{
			check[na][nb] = true;
			q.push(make_pair(na,nb));
			if(na == 0)
				ans.push_back(c - nb);
		}
		// b -> a
		na = ca + cb;
		nb = 0;
		if(na >= a)
		{
			nb = na-a;
			na = a;
		}
		if(check[na][nb] == false)
		{
			check[na][nb] = true;
			q.push(make_pair(na,nb));
			if(na == 0)
				ans.push_back(c - nb);
		}
		// b -> c
		na = ca;
		nb = 0;
		if(check[na][nb] == false)
		{
			check[na][nb] = true;
			q.push(make_pair(na,nb));
			if(na == 0)
				ans.push_back(c - nb);
		}
		// c -> a
		na = ca + cc;
		nb = cb;
		if(na >= a)
			na = a;
		if(check[na][nb] == false)
		{
			check[na][nb] = true;
			q.push(make_pair(na,nb));
			if(na == 0)
				ans.push_back(c - nb);
		}
		// c -> b
		na = ca;
		nb = cb + cc;
		if(nb >= b)
			nb = b;
		if(check[na][nb] == false)
		{
			check[na][nb] = true;
			q.push(make_pair(na,nb));
			if(na == 0)
				ans.push_back(c - nb);
		}
	}
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}