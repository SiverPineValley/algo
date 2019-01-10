// N중 for문 9095
// 10 이하의 양의정수를 1,2,3의 합으로 몇 가지의 경우로 가능한지 나타내는 문제
#include<iostream>
using namespace std;
int go(int count, int sum, int goal)
{
	if(sum > goal) return 0;		// 불가능한 경우
	else if(sum == goal) return 1;	// 답을 찾은 경우
	int now = 0; // 숫자 count개로 합 sum을 만드는 경우의 수
	// 다음 경우
	// 각각 1,2,3을 사용하는 경우
	for(int i = 1; i < 4; i++)
	{
		now += go(count+1, sum+i, goal);
	}
	return now;
}

int go2(int sum, int goal)
{
	if(sum > goal) return 0;
	else if(sum == goal) return 1;
	int now = 0;
	for(int i = 1; i < 4; i++)
	{
		now += go2(sum+i, goal);
	}
	return now;
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
		
		// cout << go(1,0,tc) << "\n" ;
		cout << go2(0,tc) << "\n" ;
	}
	return 0;
}