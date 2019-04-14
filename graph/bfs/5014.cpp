// 스타트링크
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int f, s, g, u, d;
vector<int> check(1000001, -1);
queue<pair<int,int>> q;

int main(void)
{
	// f : 스타트링크의 전체 층수
	// g : 스타트링크가 있는 층
	// s : 강호가 있는 층
	// u : 위로 가는 버튼
	// d : 아래로 가는 버튼
	cin >> f >> s >> g >> u >> d;
	check[s] = 0;
	q.push(make_pair(s,check[s]));
	while(!q.empty())
	{
		int now = q.front().first, num = q.front().second;
		q.pop();
		int n1 = now + u, n2 = now - d;
		if( n1 >= 1 && n1 <= f )
			if( check[n1] == -1 )
			{
				check[n1] = num + 1;
				q.push(make_pair(n1,check[n1]));
			}
		if( n2 >= 1 && n2 <= f )
			if( check[n2] == -1 )
			{
				check[n2] = num + 1;
				q.push(make_pair(n2,check[n2]));
			}
		if(n1 == g || n2 == g) break;
	}
	if(check[g] == -1) cout << "use the stairs\n";
	else cout << check[g] << "\n";
	return 0;
}