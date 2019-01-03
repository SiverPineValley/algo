#include <stdio.h>

#define INT_MAX 99999;

int MatrixChainOrder(int p[], int i, int j)
{
	if(i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p,i,k) + MatrixChainOrder(p,k+1,i) + p[i-1]*p[k]*p[j];

		if(count < min)
		{
			min = count;
		}
		return min;
	}
}

int main()
{
	int arr[] = {4, 10, 5, 6, 32};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Min num of multiplications is %d ", MatrixChainOrder(arr, 1, n-1));

	getchar();
	return 0;
}