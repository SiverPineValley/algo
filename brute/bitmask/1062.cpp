// 가르침
// 백준's 코드
#include <iostream>
#include<vector>
#include<string>
using namespace std;

// word는 단어 알파벳 1인 것이 모드. mask는 배운 알파벳 에서도 1이어야 한다.
int check(int mask, vector<int> &words)
{
	int cnt = 0;
	for (int word : words)
	{
		if((word & (1 << 26)-1-mask) == 0) // 배우지 않은 알파벳이 없을 경우에만, cnt를 1 증가시킨다.
			cnt += 1;
	}
	return cnt;
}

// k는 남은 갯수
int teaching(int index, int k, int mask, vector<int> &words)
{
	if(k < 0) return 0;
	if(index == 26) return check(mask, words);
	int ans = 0;
	int t1 = teaching(index + 1, k - 1, mask | ( 1 << index ), words);
	if(ans < t1) ans = t1;
	// antic 중 하나
	if(index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a')
	{
		t1 = teaching(index + 1, k, mask, words);
		if(ans < t1) ans = t1;
	}
	return ans;
}

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> words(n);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for(char x : s)
			words[i] |= ( 1 << ( x - 'a' ) );
	}
	cout << teaching(0, k, 0, words) << "\n";
	return 0;
}