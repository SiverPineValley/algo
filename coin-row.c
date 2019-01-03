#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) a > b ? a : b;

void coinrow( int* arr, int index ) {

	if( index == 0 ) arr[index][1] = 0 ;
	else if( index == 1 ) arr[index][1] = arr[index][0];
	else arr[index][1] = MAX( coinrow(arr, index - 2) + arr[index][0] , coinrow(arr,index - 1) )

}

int main(void) {

	int arr[6][2] = { { 5, 1, 2, 10, 6, 2 }, { 0, } };
	int size = sizeof(arr) / sizeof(int);

	coinrow(arr, size);

	return 0;
}