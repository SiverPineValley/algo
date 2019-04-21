// 4연산
// 백준's 코드
#include <iostream>
#include <tuple>
#include <queue>
#include <string>
#include <set>
using namespace std;
const long long limit = 1000000000LL;
int main(void)
{
	long long s, t;
	cin >> s >> t;
	// 중복 검사용. ary 대신 set 사용
	set<long long> check;
	queue<pair<long long,string>> q;
	q.push(make_pair(s,""));
	check.insert(s);
	while (!q.empty())
	{
		long long x;
		string str;
		tie(x, str) = q.front(); q.pop();
		if (x == t)
		{
			if (str.length() == 0)
				str = "0";
			cout << str << '\n';
			return 0;
		}
		if (0 <= x*x && x*x <= limit && check.count(x*x) == 0)
		{
			q.push(make_pair(x*x, str+"*"));
			check.insert(x*x);
		}
		if (0 <= x+x && x+x <= limit && check.count(x+x) == 0)
		{
			q.push(make_pair(x+x, str+"+"));
			check.insert(x+x);
		}
		if (0 <= x-x && x-x <= limit && check.count(x-x) == 0)
		{
			q.push(make_pair(x-x, str+"-"));
			check.insert(x-x);
		}
		if (x != 0 && 0 <= x/x && x/x <= limit && check.count(x/x) == 0)
		{
			q.push(make_pair(x/x, str+"/"));
			check.insert(x/x);
		}
	}
	cout << -1 << '\n';
	return 0;
}
