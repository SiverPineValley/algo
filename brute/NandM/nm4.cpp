// 15652
// 백준's 코드
#include <iostream>
using namespace std;
int a[10];
void nm(int index, int start, int N, int M)
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
	for(int i = start; i<=N; i++)
	{
		a[index] = i;
		nm(index+1,i,N,M);
	}
}
int main(void)
{
	int N, M;
	cin >> N >> M;
	nm(0,1,N,M);
	return 0;
}