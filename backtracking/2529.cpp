// 부등호
// 백준's 코드
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<char> a(20);
vector<string> ans;
bool check[10];
bool good(char x, char y, char op)
{
	if (op == '<')
		if (x > y) return false;
	if (op == '>')
		if (x < y) return false;
	return true;
}
void backtracking(int index, string num)
{
	if( index == n + 1 )
	{
		ans.push_back(num);
		return;
	}
	for (int i=0; i<=9; i++) {
		if (check[i]) continue;
		if (index == 0 || good(num[index-1], i+'0', a[index-1])) {
			check[i] = true;
			backtracking(index+1, num+to_string(i));
			check[i] = false;
		}
	}
}

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	backtracking(0,"");
	auto r = minmax_element(ans.begin(), ans.end());
	cout << *r.second << '\n';
	cout << *r.first << '\n';
	return 0;
}
