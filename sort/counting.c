#include <stdio.h>

int main(void) {

	int temp, time = 0;
	int count[11];
	int array[10] = {1,10,5,8,7,6,4,3,2,9};
	int Csize = sizeof(count) / sizeof(int);
	int Asize = sizeof(array) / sizeof(int);

	for(int i = 0; i <= Csize; i++) {
		count[i] = 0;
	}
	for(int i = 0; i < Asize; i++) {
		count[array[i]]++;
	}
	for(int i = 1; i <= Csize; i++) {
		time++;
		if(count[i] != 0) {
			for(int j = 0; j < count[i]; j++) {
				printf("%d ",i);
			}
		}
	}

	printf("\nTime Complexity: %d\n",time);
	return 0;
}
