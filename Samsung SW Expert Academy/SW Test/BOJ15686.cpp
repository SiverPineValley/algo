// 치킨 배달
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<int,int>> house, chicken;
vector<int> per;
int result = 1000000;

int main(void)
{
	// 맵 크기, 최대로 살릴 치킨 개수
	int n, m, mapInput;
	cin >> n >> m;

	// 입력
	for(int y = 1; y <= n; y++)
	{
		for(int x = 1; x <= n; x++)
		{
			cin >> mapInput;
			if(mapInput == 1) house.push_back(make_pair(x,y));
			else if(mapInput == 2) chicken.push_back(make_pair(x,y));
		}
	}

	// 순열 준비
	int chickenSize = chicken.size();
	for(int index = chickenSize; index > 0; index--)
	{
		if(index > m) per.push_back(0);
		else per.push_back(1);
	}

	// 순열
	do
	{
		int sumOfcase = 0;
		for(auto houseItem : house)
		{
			int min = 1000000;
			for(int index = 0; index < chickenSize; index++)
			{
				int temp;
				if(per[index] == 1)
				{
					temp = abs(houseItem.first - chicken.at(index).first)
					+ abs(houseItem.second - chicken.at(index).second);
					if(temp < min) min = temp;
				}
			}
			sumOfcase += min;
		}
		if(sumOfcase < result) result = sumOfcase;
	} while(next_permutation(per.begin(), per.end()));

	cout << result << "\n";

	return 0;
}