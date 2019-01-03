#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y, temp) ( temp=x, x=y, y=temp )

int time = 0;

void up_heapify( int* array, int size ) {

	int temp;

	if( ( size % 2 ) == 1 ) {
		for( int i = 1; i < size; i++ ) {
			int c = i;
			do{
				int root = ( c - 1 ) / 2;
				if( array[root] < array[c] ) SWAP( array[root], array[c], temp );
				c = root;
			} while( c != 0 );
		}		
	} else {
		printf("홀수 개의 원소를 가져야 합니다.\n");
		exit(1);
	}

	return;
}

void heapsort( int* array, int size ) {

	int temp;

	for( int i = size - 1; i >= 0; i-- ) {
		SWAP( array[0], array[i], temp );
		int root = 0;
		int c = 1;
		do {
			time++;
			c = 2 * root + 1;
			// 자식 중에 더 큰 값을 찾기
			if( c < i - 1 && array[c] < array[c + 1] ) c++;

			// 루트보다 자식이 크다면 교환
			if( c < i && array[root] < array[c] ) SWAP(array[root],array[c],temp);
			root = c;
		} while( c < i );
	}
}

void show( int* array, int size ) {
	for( int i = 0; i < size; i++ ) printf("%d ", array[i]);
	printf("\nTime Complexity: %d\n",time);
	return;
} 

int main(void) {

	int array[11] = {1,10,5,8,7,6,4,3,2,11,9};
	int size = sizeof(array) / sizeof(int);

	up_heapify( array, size );
	heapsort( array, size );
	show( array, size );

	return 0;
}