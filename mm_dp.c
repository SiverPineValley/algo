#include <stdio.h>

int MatrixDPM ( int arr[], int n )
{
	int M[n][n];
	int P[n][n];

	for( int i = 0; i <= n; i++ )
	{
		M[i][i] = 0;
	}

	for( int d = 1; d <= n-1; d++)
	{
		for( int i = 0; d <= n-d; i++)
		{
			int j=i+d;
			for ( int t = i; t <= j-1; t++ )
			{
				int a = M[i][j];
				int b = M[i][t] + M[t + 1][j] + arr[i] * arr[i + 1] * arr[t];
				if( a > b )
				{
					M[i][j] = b;
					P[i][j] = t + 1;
				}
			}

			
		}
	}

	return M[1][n-1];
}

int main()
{
	int arr[] = { 10, 4, 5, 20, 2, 50 };
	int n = 6;

	printf("Min num of Matrix Multiplications is: %d\n",MatrixDPM(arr, n));
	return 0;
}