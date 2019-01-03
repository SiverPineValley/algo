#include <stdio.h>

#define SWAP(x, y, temp) ( temp=x, x=y, y=temp )

int time = 0;
int sorted[10];
const int size = sizeof(sorted) / sizeof(int);

void show(int* data, int size) {

	for(int i = 0; i < size; i++) {
		printf("%d ",data[i]);
	}
	printf("\n");

	return;
}

void merge( int* array, int start, int middle, int end ) {

	int first = start, second = middle + 1, sortnum = start;

	// 두 개의 array를 비교해서 작은 순으로 채워 넣는다.
	while( ( first <= middle ) && ( second <= end ) ) {
		time++;

		if( array[first] >= array[second] ) {
			sorted[sortnum] = array[second];
			second++;
		} else {
			sorted[sortnum] = array[first];
			first++;
		}
		sortnum++;

	}

	// 남는 데이터를 채워 넣는다.
	if ( first > middle ) {
		for( int t = second; t <= end; t++ ) {
			time++;
			sorted[sortnum] = array[t];
			sortnum++;
		}
	} else {
		for( int t = first; t <= middle; t++ ) {
			time++;
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

	// 반으로 나눠서 첫 번째 반, 나머지 반을 mergesort한다.
	if( start < end ) {
		int middle = ( start + end ) / 2;
		mergesort( array, start, middle );
		mergesort( array, middle + 1, end );
		merge( array, start, middle, end );
	}
	return;
}

int main(int argc, char* args) {

	int array[10] = {1,10,5,8,7,6,4,3,2,9};

	mergesort( array, 0, size - 1 );

	show( array, size );
	
	printf("Time Complexity: %d\n",time);

	return 0;
}