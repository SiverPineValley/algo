#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a > b ? a : b)

int coinrow( int* arr, int index ) {

	

}

int main(void) {

	int arr[6] = { 5, 1, 2, 10, 6, 2 };
	int size = sizeof(arr) / sizeof(int);

	coinrow(arr, size);

	return 0;
}