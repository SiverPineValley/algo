// ABC
// 백준's 코드
#include <iostream>
#include <cstring>
using namespace std;
bool d[31][31][31][436];
char ans[32];
int n, k;

// D[i][a][b][p]: 길이가 i이고, A의 개수가 a개, B의 개수가 b, S[i] < s[j] 쌍이 p개 있는 문자열이 가능한가?
int topbottom(int i, int a, int b, int p)
{
	if (i == n)
	{
		if (p == k) return true;
		else return false;
	}
	if (d[i][a][b][p]) return false;
	d[i][a][b][p] = true;

	// i번째 글짜가 A인 경우 D[i+1][a+1][b][p]
	ans[i] = 'A';
	if (topbottom(i+1, a+1, b, p)) return true;

	// i번째 글짜가 B인 경우 D[i+1][a+1][b+1][p+a]
	ans[i] = 'B';
	if (topbottom(i+1, a, b+1, p+a)) return true;

	// i번째 글짜가 C인 경우 D[i+1][a][b][p+a+b]
	ans[i] = 'C';
	if (topbottom(i+1, a, b, p+a+b)) return true;

	return false;
}
int main() {
	cin >> n >> k;
	if (topbottom(0,0,0,0))
		cout << ans << '\n';
	else
		cout << -1 << '\n';
	return 0;
}