#include <iostream>
using namespace std;

int main(void)
{
	int prime[100]; // 소수 저장
	int pn = 0; // 소수의 개수
	bool check[101]; // 지워졌으면 true, 지워지지 않았으면 false
	int n = 100; // 100까지의 소수
	for(int i = 2; i <= n; i++)
	{
		if(!check[i])
		{
			prime[pn++] = i;
			for(int j = i*i; j<=n; j+=i)
				check[j] = true;
		}
	}
	for(int i = 0; i < pn; i++)
	{
		cout << prime[i] << "\n";
	}
	
	return 0;
}