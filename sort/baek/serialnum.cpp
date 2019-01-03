#include <iostream>
#include <algorithm>
#include <list>
#include <ctype.h>

using namespace std;

int comstring( string a ) {
	int sum = 0;
	for( int i = 0; i < a.length(); i++ ) if( isdigit(a.at(i)) ) sum += ( a.at(i) - '0' );
	return sum;
}

bool serialsort( string a, string b ) {

	if( a.length() != b.length() ) return a.length() < b.length();
	else {
		int sa, sb;
		sa = comstring(a);
		sb = comstring(b);

		if( sa != sb ) return sa < sb;
		else {
			return a < b;
		}
	}
}

int main(void) {

	int num;
	std::list<string> guitars;

	cin >> num;

	for( int i = 0; i < num; i++ ){
		string tstr;

		cin >> tstr;

		guitars.push_back( tstr );
	}

	guitars.sort( serialsort );

	auto temp = guitars.begin();

	for( auto it = guitars.begin(); it != guitars.end(); it++ ) {
		if( ( it != guitars.begin() ) && ( *temp == *it ) ) continue;
		else{
			cout << *it << endl;
			temp = it;
		}
	}

	return 0;
}