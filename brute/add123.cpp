// N중 for문 9095
// 10 이하의 양의정수를 1,2,3의 합으로 몇 가지의 경우로 가능한지 나타내는 문제
#include<iostream>
using namespace std;
int answer = 0;
void nfor(int tc)
{
	if(tc < 0)
		return;
	else if(tc == 0)
	{
		answer++;
		return;
	}
	nfor(tc - 1);
	nfor(tc - 2);
	nfor(tc - 3);
}

int main(void)
{	
	int tn;
	cin >> tn;
	while(tn)
	{
		tn--;
		int tc;
		cin >> tc;
		nfor(tc);
		cout << answer << "\n" ;
		answer = 0;
	}
	return 0;
}