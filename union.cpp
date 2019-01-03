#include <iostream>

using namespace std;

int getParent( int* parent, int x ) {
	if( parent[x] == x ) return x;
	return parent[x] = getParent( parent, parent[x] );
}

void UnionParent( int* parent, int a, int b ) {
	a = getParent( parent, a );
	b = getParent( parent, b );
	if( a < b ) parent[b] = a;
	else parent[a] = b;
}

// 같은 부모 노드를 가지는지 확인
int findParent( int* parent, int a, int b ) {
	a = getParent( parent, a );
	b = getParent( parent, b );

	if( a == b ) return 1;
	else return 0;
}

int main(void) {

	int parent[10];
	int size = sizeof(parent) / sizeof(int);

	for( int i = 0; i < size; i++ ) {
		parent[i] = i;
	}

	UnionParent( parent, 1, 2 );
	UnionParent( parent, 2, 3 );
	UnionParent( parent, 3, 4 );
	UnionParent( parent, 5, 6 );
	UnionParent( parent, 6, 7 );
	UnionParent( parent, 7, 8 );

	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));
	UnionParent( parent, 1, 5 );
	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));

	return 0;
}