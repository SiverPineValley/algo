#include <iostream>
using namespace std;
// 이 프라임 판별법은 loot N의 시간복잡도를 가진다.
bool isprime(int n)
{
	if(n < 2) return false;
	for (int i = 2; i*i <= n; i++)
		if(n % i == 0) return false;
	return true;
}