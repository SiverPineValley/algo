#include <iostream>

using namespace std;

#define MAX( a, b ) ((a) > (b)) ? a : b;

int sum = 0, stack = 0;

int find( int* s, int now, int target ) {
	if( now == target ) return sum;
	else if ( stack == 2 ) {
		now += 2;
		sum += s[now + 2];
		stack = 1;
		return find( s, now, target );
	} else if ( now == 0 ) {
		now++;
		sum += s[now + 1];
		stack = 1;
		return find( s, now, target );
	}
	else {
		if( s[now] )
	}
}

int main(void) {

	int stairnum;
	cin >> stairnum;
	int now = 0;
	int s[stairnum + 1] = { 0, };


	for( int i = 1; i < stairnum + 1; i++ ) {
		cin >> s[i];
	}

	// cout << find(  );

	return 0;
}