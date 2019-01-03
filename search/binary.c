#include<stdio.h>

int binary( int* S, int low, int high, int key ) {

	int mid = (low + high) / 2;
	if(low > high) return 0;
	else {
		if( key == S[mid] ) return mid;
		else if( key < S[mid] ) return binary( S, low, mid - 1, key );
		else return binary( S, mid + 1, high, key );
	}
}

int binary_iter( int* S, int size, int key ) {

	int l = 0;
	int r = size - 1;
	int mid;

	while( l <= r ){
		mid = (l+r)/2;
		if( key == S[mid] ) return mid;
		else if ( key < S[mid] ) r = mid - 1;
		else l = mid + 1;
	}

	return -1;
}

int main(void) {

	int S[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	printf("Recursive: %d\n",binary( S, 0, 9, 4 ));
	printf("Iterative: %d\n",binary_iter( S, 10, 9 ));

	return 0;
}