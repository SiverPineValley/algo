#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>
#include <stack>
#include <cstring>

using namespace std;

// Array에서 사용할 Swap
#define SWAP(x, y, temp) ( temp=x, x=y, y=temp )

/*
	각 Subset들의 개수를 세는 함수
 */
void calSets( vector<set<int>> s, int sNum, vector<int>* size )
{	
	// sort 하기 위해 Size를 채우기
	for( int i = 0; i < sNum; i++ )
		(*size)[i] = s[i].size();
}

/*
	QuickSort 함수
 */
void quicksort( vector<set<int>>* s, int start, int end, vector<int>* size )
{
	if ( start >= end ) {
		return;
	}
	int key = start;
	int i = start + 1, j = end, temp;
	set<int> temps;

	while( i <= j )
	{
		while( i <= end && (*size)[i] >= (*size)[key] )
			i++;

		while( j > start && (*size)[j] <= (*size)[key] )
			j--;

		if(i > j)
		{
			SWAP((*s)[j],(*s)[key],temps);
			SWAP((*size)[j], (*size)[key], temp);
		}
		else
		{
			SWAP((*s)[i],(*s)[j],temps);
			SWAP((*size)[i],(*size)[j],temp);
		}
	}
	
	quicksort( s , start , j - 1, size );
	quicksort( s, j + 1, end, size );
	return;
}

/*
	Subset들을 Sorting 하는 함수
 */
void sortSets( vector<set<int>>* s, int sNum, vector<int>* size )
{
	calSets( *s, sNum, size );
	quicksort( s, 0, sNum - 1, size );
};

struct Solution
{
	vector<int> isS;
	vector<int> setState;
	int stage;
	int cntState;
	int cntSolved;
};

int main(void)
{
    char buff[1024];
	char *pch;
    int uNum;	// U Num
    int sNum;	// Subset Num
    int bestSol = 99999999;
    vector<set<int>> sets;
	scanf("%d", &uNum);
	scanf("%d\n", &sNum);
    // 스택 생성
	stack<Solution> solution;

	if( uNum == sNum )
	{
		cout << "1";
		return 0;
	}

    // 입력
    // vector<set<int>> sets: vector는 subset을 담고, set은 각 원소들을 담는다.
    // setSize는 각 Subset들의 Size를 담는다. isSol은 해결되었는지를 확인할 때.
    // sst는 solution에 들어갈 state space tree의 각 상태
	sets.resize(sNum);
	vector<int> setSize;
	setSize.resize(sNum, 0);

	for (int i = 0; i < sNum; i++)
    {
		gets(buff);
		pch = strtok(buff, " ");
		while (pch != NULL)
        {
			sets[i].insert(atoi(pch));
			pch = strtok(NULL, " ");
		}
	}

	// 정렬
	sortSets( &sets, sNum, &setSize );

	// 알고리즘
	Solution temp;
	temp.isS.resize(uNum, 0);
	temp.setState.resize(sNum, 0);
	temp.stage = 0;
	temp.cntState = 0;
	temp.cntSolved = 0;
	solution.push(temp);

	temp.setState[0] = 1;
	temp.cntState = 1;
	for (auto f = sets[0].begin(); f != sets[0].end(); f++)
	{
		temp.isS[*f - 1] = 1;
		temp.cntSolved++;
	}
	solution.push(temp);

	while(!solution.empty())
	{
		temp = solution.top();
		solution.pop();
		vector<int> tempisS = temp.isS;

		// 현재 State가 Leaf Node
		if ( temp.stage == (sNum - 1) )
		{	
			// Leaf가 Best Solution
			if ( (bestSol > temp.cntState) && (temp.cntSolved == uNum) )
				bestSol = temp.cntState;
		}
		// 현재 State가 Not Leaf Node
		else
		{
			// Solution을 찾은 경우, BestSolution을 갱신하고 다음으로 넘어간다.
			if( temp.cntSolved == uNum )
			{
				if( bestSol > temp.cntState )
					bestSol = temp.cntState;
			}
			// Solution을 찾지 못한 경우, Stack에 양 쪽 노드를 Push한다.
			else
			{
				// Pruning 1: bestSolution보다 cntState값이 같거나 커지면, 스택에 추가하지 않는다.
				if( bestSol <= ( temp.cntState + 1 ) );
				else{
					temp.stage++;

					// Pruning 2: 만약, sets[temp.stage].size() == 1이면, isSol의 남은 개수만큼 Sol에 더한다.
					if( sets[temp.stage].size() == 1 )
					{
						int remain = (temp.cntState + uNum - temp.cntSolved);
						if( bestSol > remain )
							bestSol = remain;
					}
					else
					{
						int how = 0;
						// 현재 추가된 Subset에 따라 isS 갱신한다.
						for( auto it = sets[temp.stage].begin(); it != sets[temp.stage].end(); it++ )
						{
							if( tempisS[*it - 1] == 0 )
							{
								tempisS[*it - 1] = 1;
								how++;
							}
						}

						if( temp.stage != (sNum - 1) )
							solution.push(temp);

						// Pruning 3: 추가되는 set이 없으면, 왼쪽 Child는 생성하지 않는다.
						if ( how != 0 )
						{
							temp.isS = tempisS;
							temp.setState[temp.stage] = 1;
							temp.cntState++;
							temp.cntSolved += how;
							solution.push(temp);
						}
					}
				}	
			}
		}
	}
	
	cout << bestSol;
    
    return 0;
}