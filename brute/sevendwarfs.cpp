#include <iostream>
#include <algorithm>
using namespace std;
/*
*
* 9명의 난쟁이 중에 7명의 난쟁이를 골라 키의 합이 100이 되도록 하는 해를 찾는
* Brute Force 소스 코드
* 
 */
int main(void)
{
	int d[9], a[7];
	for(int i = 0; i < 9; i++)
		cin >> d[i];
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(i != j)
			{
				int sum = 0;
				int tn = 0;
				for(int t = 0; t < 9; t++)
				{
					if( (t != i) && (t != j) )
					{
						sum += d[t];
						a[tn] = d[t];
						tn++;
					}
				}
				if(sum == 100)
				{
					sort(a,a+7);
					for(int i = 0; i < 7; i++)
						cout << a[i] << "\n";
					return 0;
				}
			}
		}
	}
	return 0;
}