// 15651
// 백준's 코드
#include <iostream>
using namespace std;
int a[10];
void nm(int index, int N, int M)
{
	if(index == M)
	{
		for(int i = 0; i < M; i++)
		{
			cout << a[i];
			if(i != M-1) cout << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = 1; i<=N; i++)
	{
		a[index] = i;
		nm(index+1,N,M);
	}
}
int main(void)
{
	int N, M;
	cin >> N >> M;
	nm(0,N,M);
	return 0;
}