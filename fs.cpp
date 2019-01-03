#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool c[7], d[7];

void bfs( int start, vector<int> v[] ) {
	queue<int> q;
	q.push(start);
	c[start] = true;

	while(!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for(int i = 0; i < v[x].size(); i++ ) {
			int y = v[x][i];
			if(!c[y]) {
				q.push(y);
				c[y] = true;
			}
		}
	}

}

void dfs( int x, vector<int> v[] ) {
	if(d[x]) return;
	d[x] = true;
	cout << x << ' ';
	for(int i = 0; i < v[x].size(); i++ ) {
		int y = v[x][i];
		dfs(y, v);
	}
	return;
}

int main(void) {

	vector<int> v[8];

	// 1 -- 2
	v[1].push_back(2);
	v[2].push_back(1);

	// 1 -- 3
	v[1].push_back(3);
	v[3].push_back(1);

	// 2 -- 3
	v[2].push_back(3);
	v[3].push_back(2);

	// 2 -- 4
	v[2].push_back(4);
	v[4].push_back(2);

	// 2 -- 5
	v[2].push_back(5);
	v[5].push_back(2);

	// 3 -- 6
	v[3].push_back(6);
	v[6].push_back(3);

	// 3 -- 7
	v[3].push_back(7);
	v[7].push_back(3);

	// 4 -- 5
	v[4].push_back(5);
	v[5].push_back(4);

	// 6 -- 7
	v[6].push_back(7);
	v[7].push_back(6);

	cout << "BFS: ";
	bfs(1, v);
	cout << endl;

	cout << "DFS: ";
	dfs(1, v);
	cout << endl;

	return 0;
}