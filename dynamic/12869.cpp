// 뮤탈리스크
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int d[61][61][61];
int n;
vector<int> h(3);

int topdown(int a, int b, int c)
{
	if(a == 0 && b == 0 && c == 0) return 0;
	if(d[a][b][c] != -1) return d[a][b][c];
	d[a][b][c] = 10000000;
	int na, nb, nc;

    vector<int> p = {1, 3, 9};
    do {
		na = a - p[0];
		if(na < 0) na = 0;
		nb = b - p[1];
		if(nb < 0) nb = 0;
		nc = c - p[2];
		if(nc < 0) nc = 0;
		if (d[a][b][c] > topdown(na, nb, nc))
			d[a][b][c] = topdown(na, nb, nc);
	} while(next_permutation(p.begin(), p.end()));

	d[a][b][c] += 1;
	return d[a][b][c];
}

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> h[i];

	memset(d, -1, sizeof(d));
	cout << topdown(h[0],h[1],h[2]) << "\n";
	return 0;
}