#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

bool vocasort( string a, string b ) {

	if( a.length() < b.length() ) return true;
	else if ( a.length() == b.length() ) return a < b;
	else return false;
}

int main(void) {

	int num;
	std::list<string> vocas;

	cin >> num;

	for( int i = 0; i < num; i++ ){
		string tstr;

		cin >> tstr;

		vocas.push_back( tstr );
	}

	vocas.sort( vocasort );

	auto temp = vocas.begin();

	for( auto it = vocas.begin(); it != vocas.end(); it++ ) {
		if( ( it != vocas.begin() ) && ( *temp == *it ) ) continue;
		else{
			cout << *it << endl;
			temp = it;
		}
	}

	return 0;
}