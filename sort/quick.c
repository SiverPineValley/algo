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

void quicksort( int* array, int start, int end ) {

	// 원소가 1개이면 그대로 return
	if (start >= end) return;

	// pivot은 항상 array의 가운데
	int left = start, right = end;
	int pivot = (left + right) / 2;
	int temp;

	// left와 right이 같아질때까지 left와 right을 각각 오른쪽, 왼쪽으로 옮기며, 
	// left가 pivot array 값보다 크고, right이 pivot array 값보다 작으면 두 array 값을 swap한다.
	while( left < right ) {
		time++;

		if( ( left < right ) && ( array[left] <= array[pivot] ) ) left++;
		if( ( left != right ) && ( array[right] >= array[pivot] ) ) right--;
		if( ( array[left] > array[pivot] ) && ( array[right] < array[pivot] ) ) SWAP( array[left], array[right] ,temp );
	}

	// left == right이 되면, while을 빠져나와서, left와 right이 만나는 위치에 따라 조건문을 걸어준다.
	// 예를들어, pivot 이전에서 만났을 경우에는 left의 array 값이 pivot의 array보다 클 때 swap하고,
	// pivot 이후에 만났을 경우에는 right의 array 값이 pivot의 array보다 작을 때만 swap한다. 나머지는 swap하지 않는다.
	// 또한 pivot을 옮겨진 위치로 갱신한다.
	if ( ( left < pivot ) && ( array[pivot] < array[left] ) ) { SWAP( array[left], array[pivot], temp ); pivot = left; }
	else if ( ( left > pivot ) && ( array[pivot] > array[left] ) ) { SWAP( array[left], array[pivot], temp ); pivot = left; }
	else;

	// 옮겨진 pivot의 위치가 start와 같다면, start를 제외한 나머지를 quicksort한다. end일 경우에도 마찬가지이다.
	// 그렇지 않다면, pivot의 왼쪽 영역과 오른쪽 영역을 각각 quicksort한다.
	if( pivot == start ) { 
		quicksort( array, start + 1 , end );
	} else if ( pivot == end ) {
		quicksort( array, start, end - 1 );
	} else if ( ( left == end ) || ( left == start ) ) {
		quicksort( array, start, pivot );
		quicksort( array, pivot, end );
	} else {
		quicksort( array, start, pivot - 1 );
		quicksort( array, pivot + 1, end );
	}

	
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