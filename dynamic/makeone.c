// 1463
#include <stdio.h>

#define MIN( a , b ) (((a) < (b)) ? (a) : (b))

int makeone( int target ) {

	if( target <= 1 ) return 0;
	return MIN( makeone( target/2 ) + target%2 + 1, makeone( target/3 ) + target%3 + 1 );

}

int main(void) {

	int target;

	scanf("%d",&target);

	printf("%d", makeone( target ));

}