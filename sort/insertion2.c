#include <stdio.h>

int* insertion( int* array, int size ) {

	int i, j, temp;

	for(i = 0; i < size; i++) {

		if( (i > 0) && ( array[i] < array[i - 1] ) ){

			for( j = i; j > 0; j-- ){
				if( array[j] < array[j - 1] ) {
					temp = array[j - 1];
					array[j - 1] = array[j];
					array[j] = temp;
				}
			}

		}

	}

	return array;

}

int main(void) {

	int array[10];
	int input = 0;
	int size = 0;

	while( size <= 9 ) {

		printf("정수를 입력해주세요.:");
		scanf("%d", &input);
		getc(stdin);

		size++;

		array[size-1] = input;
		insertion( array, size );

		for( int i = 0; i < size; i++ ) {
			printf("%d ",array[i]);		
		}

		printf("\n");

	}

	return 0;
}