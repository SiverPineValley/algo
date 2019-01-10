// 1759 백준's 소스코드
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool check(string password)
{
	int jaum = 0;
	int moum = 0;
	for(char x : password)
	{
		if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') moum += 1;
		else jaum += 1;
	}
	return jaum >= 2 && moum >= 1;
}

void makePass(int n, vector<char> &alpha, string password, int i)
{
	if(password.length() == n)						// 정답 password면 출력
	{
		if(check(password))
			cout << password << "\n";
		return;
	}
	else if(i >= alpha.size()) return;				// 정답이 아니면 return
	makePass(n, alpha, password + alpha[i], i+1);	// alphabet 추가할 경우
	makePass(n, alpha, password, i+1);				// alphabet 추가하지 않을 경우
}

int main(void)
{
	int L, C; // L은 길이 C는 알파벳 수
	cin >> L >> C;
	vector<char> alphabet(C);
	for(int i = 0; i < C; i++)
		cin >> alphabet[i];
	sort(alphabet.begin(), alphabet.end());
	makePass(L, alphabet, "", 0);
	return 0;
}