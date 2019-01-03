#include <stdio.h>

int main(void) {

	int non, temp;
	int num[10001] = { 0, };

	scanf("%d",&non);

	for( int i = 0; i < non; i++ ) {
		scanf("%d",&temp);
		num[temp]++;
	}

	for( int i = 1; i < 10001; i++ ) {
		while( num[i] != 0 ) {
			printf("%d\n",i);
			num[i]--;
		}
	}

	return 0;
}