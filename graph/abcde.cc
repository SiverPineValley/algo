// 13023
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void)
{
	vector<pair<int,int>> el; 			// edge list
	vector<int> al[2000];				// adjacency list
	int aa[2000][2000];					// adjacency array
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		al[a].push_back(b);
		al[b].push_back(a);
		el.push_back(make_pair(a,b));
		el.push_back(make_pair(b,a));
		aa[a][b] = aa[b][a] = 1;
	}
	for(int i = 0; i < (2*m); i++)
	{
		for(int j = 0; j < (2*m); j++)
		{
			if(i == j) continue;
			// A -> B
			int A = el[i].first;
			int B = el[i].second;
			// C -> D
			int C = el[j].first;
			int D = el[j].second;
			if( A == B || A == C || A == D || B == C || B == D || C == D ) continue;
			if( !aa[B][C] ) continue;
			// D -> E
			for(int E : al[D])
			{
				if( A == E || B == E || C == E || D == E ) continue;
				cout << 1 << "\n";
				return 0;
			}
		}

	}
	cout << 0 << "\n";
	return 0;
}