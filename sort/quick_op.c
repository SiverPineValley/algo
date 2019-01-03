#include <stdio.h>

#define SWAP(x, y, temp) ( temp=x, x=y, y=temp )

int time = 0;

void show(int* data, int size) {

	for(int i = 0; i < size; i++) {
		printf("%d ",data[i]);
	}
	printf("\n");

	return;
}

void quicksort( int* data, int start, int end ) {

	if ( start >= end ) {
		return;
	}

	int key = start;
	int i = start + 1, j = end, temp;

	while( i <= j ) {
		time++;
		while( i <= end && data[i] <= data[key] ) {
			time++;
			i++;
		}
		while( j > start && data[j] >= data[key] ) {
			time++;
			j--;
		}

		if(i > j) {
			SWAP(data[j], data[key], temp);
		} else {
			SWAP(data[i],data[j],temp);
		}

	}
	
	quicksort( data , start , j - 1 );
	quicksort( data, j + 1, end );
	return;
}

int main(int argc,char* args) {

	int array[10] = {1,10,5,8,7,6,4,3,2,9};
	const int size = sizeof(array) / sizeof(int);

	quicksort(array, 0, size - 1);

	show(array, size);
	
	printf("Time Complexity: %d\n",time);

	return 0;
}