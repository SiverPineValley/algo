#include <stdio.h>

int main(int argc,char* args) {

	int array[10] = {1,10,5,8,7,6,4,3,2,9};
	int i, j, min, index, temp;
	int time = 0;

	for(i = 0; i < 10; i++) {
		time++;
		min = 9999;

		for(j = i; j < 10; j++) {
			time++;
			if( min > array[j] ) {
				min = array[j];
				index = j;
			}
		}

		temp = array[i];
		array[i] = min;
		array[index] = temp;

	}

	for(int k = 0; k < 10; k++) {
		printf("%d ", array[k]);
	}
	printf("\n");
	printf("Time Complexity: %d\n",time);

	return 0;
}