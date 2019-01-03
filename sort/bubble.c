#include <stdio.h>

int main(int argc,char* args) {

	int array[10] = {1,10,5,8,7,6,4,3,2,9};
	int i, j, temp;
	int time = 0;
	
	for(i = 0; i < 10; i++) {
		time++;
		for(j = 0; j < 9 - i; j++) {
			time++;
			if(array[j] > array[j+1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}


	for(i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\nTime Complexity: %d\n",time);

	return 0;
}