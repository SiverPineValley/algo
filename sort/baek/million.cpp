#include <stdio.h>

#define SWAP(x, y, temp) ( temp=x, x=y, y=temp )

int sorted[1000000];

void merge( int* array, int start, int middle, int end ) {

	int first = start, second = middle + 1, sortnum = start;

	while( ( first <= middle ) && ( second <= end ) ) {

		if( array[first] >= array[second] ) {
			sorted[sortnum] = array[second];
			second++;
		} else {
			sorted[sortnum] = array[first];
			first++;
		}
		sortnum++;

	}

	if ( first > middle ) {
		for( int t = second; t <= end; t++ ) {
			sorted[sortnum] = array[t];
			sortnum++;
		}
	} else {
		for( int t = first; t <= middle; t++ ) {
			sorted[sortnum] = array[t];
			sortnum++;
		}
	}

	for( int t = start; t <= end; t++ ) {
		array[t] = sorted[t];
	}

	return;
}

void mergesort( int* array, int start, int end ) {

	if( start < end ) {
		int middle = ( start + end ) / 2;
		mergesort( array, start, middle );
		mergesort( array, middle + 1, end );
		merge( array, start, middle, end );
	}
	return;
}

int main(void) {

	int array[1000000];
	int size;

	scanf("%d",&size);

	for(int i = 0; i < size; i++) scanf("%d",&array[i]);

	mergesort( array, 0, size - 1 );

	for(int i = 0; i < size; i++) printf("%d\n",array[i]);

	return 0;
}