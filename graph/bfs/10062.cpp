// 은기의 DNA 분자
// not complete
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

/*
*	A ↔ TC (A는 TC로 변할 수 있고, 그 역으로 변할 수도 있다)
* 	C ↔ AG
*   G ↔ CT
*   T ↔ GA
 */
int n, maxLength = 0;
queue<string> q;
string one[4] = {"A", "C", "G", "T"};
string two[4] = { "TC", "AG", "CG", "GA" };

int main(void)
{
	cin >> n;
	vector<string> s(n);
	int ans[100][100];
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
		if(s[i].length() > maxLength) maxLength = s[i].length();
	}

	for(int i = 0; i < n; i++)
	{
		set<string> sets;
		q.push(s[i]);
		sets.insert(s[i]);

		while(!q.empty())
		{
			string cs = q.front();
			string temp = cs;
			q.pop();

			if(cs.length() <= maxLength)
			{
				// 한글자 짜리 치환
				for(int j = 0; j < cs.length();j++)
				{
					for(int k = 0; k < 4; k++)
					{
						if(cs[j] == one[k][0])
						{
							temp.erase(j,1);
							temp.insert(j,two[k]);
							if(sets.count(temp) == 0)
							{
								sets.insert(temp);
								q.push(temp);
							}
							temp = cs;
						}
					}
				}

				// 두글자 짜리 치환
				for(int j = 0; j < 4; j++)
				{
					int end = 0;
					int now = 0;
					while(!end)
					{
						auto loc = temp.find(two[j], now);
						if( loc != string::npos )
						{
							temp.erase(loc,2);
							temp.insert(loc,one[j]);
							if(sets.count(temp) == 0)
							{
								sets.insert(temp);
								q.push(temp);
							}
							now = loc + 1;
							temp = cs;
						}
						else end = 1;
					}
				}
				for(auto it = sets.begin(); it != sets.end(); it++)
					cout << *it << " ";
				cout << "\n";

				// Array 채우기
				for(int j = 0; j < n; j++)
				{
					if(sets.count(s[j]) != 0)
						ans[i][j] = 1;
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << ans[i][j];
		cout << "\n";
	}
	return 0;
}