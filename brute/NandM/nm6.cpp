// 15655
// 백준's 코드
#include <iostream>
#include <algorithm>
using namespace std;
int a[10]; int num[10];
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
		a[index] = num[i-1];
		nm(index+1,i+1,N,M);
	}
}
int main(void)
{
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> num[i];
	sort(num,num+N);
	nm(0,1,N,M);
	return 0;
}