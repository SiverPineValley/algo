//10972
#include <iostream>
#define swap(a,b,n) (n = a, a = b, b = n)
using namespace std;
bool next_permutation(int *a, int n)
{	
	int temp;
	int i = n-1;
	while(i > 0 && a[i-1] >= a[i]) i -= 1;	// i-1을 찾기
	if(i <= 0) return false;				// 마지막 순열
	int j = n-1;
	while(a[j] <= a[i-1]) j -= 1;			// 크면서 가장 작은수 j 찾기
	swap(a[i-1],a[j],temp);
	j=n-1;
	while(i < j)							// SWAP 코드
	{
	swap(a[i],a[j],temp);
	i += 1; j -= 1;
	}
	return true;
}

int main(void)
{	
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];	
	if(next_permutation(a,n) == true)
	{
		for(int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	else cout << -1 << "\n";
	return 0;
}
