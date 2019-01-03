#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare( pair<string, pair<int, int> > a,
			pair<string, pair<int, int> > b ) {
	if( a.second.first == b.second.first ) {
		return a.second.second > b.second.second;
	} else {
		return a.second.first > b.second.first;
	}
}

int main(void) {
	vector<pair<string,pair<int,int>>> v;
	v.push_back(pair<string, pair<int,int>>("전지호", make_pair(90, 19950305)));
	v.push_back(pair<string, pair<int,int>>("최성욱", make_pair(89, 19951108)));
	v.push_back(pair<string, pair<int,int>>("정민환", make_pair(94, 19950417)));
	v.push_back(pair<string, pair<int,int>>("이진형", make_pair(85, 19950617)));
	v.push_back(pair<string, pair<int,int>>("김민준", make_pair(87, 19950913)));

	sort(v.begin(), v.end(), compare);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}

	cout << "\n";
	return 0;
}