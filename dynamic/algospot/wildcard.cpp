#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

string wildcard, filename;
int cache[101][101];

int dynamic(int w, int f)
{
	// 기저사례는 따로 없음
	// Caching 확인
	int& ref = cache[w][f];
	if(ref != -1) return ref;

	// 매치 해보기
	while( w < wildcard.size() && f < filename.size() && 
	( wildcard[w] == '?' || wildcard[w] == filename[f] ) )
	{
		return ref = dynamic(w + 1, f + 1);
	}

	// 멈춘이유 -> 둘 다 문자열 끝에 도달했으면 1, filename이 끝에 도달 못했으면 0 리턴
	if( w == wildcard.size() ) return ref = ( f == filename.size() );

	// * 때문에 멈춤 
	if( wildcard[w] == '*' )
		if(dynamic(w+1, f) || ( f < filename.size() && dynamic(w, f+1) ))
			return ref = 1;

	// 이하의 경우에는 대응되지 않는다.
	return ref = 0;
}

int main(void)
{
	int testCase;
	cin >> testCase;
	while(testCase--)
	{
		int fileNum;
		vector<string> results;
		// 와일드카드명과 파일 개수 입력
		cin >> wildcard;
		cin >> fileNum;

		for(string sorted : results)
			cout << sorted << "\n";

		// 파일명 입력
		for(int index = 0; index < fileNum; index++)
		{
			cin >> filename;
			memset(cache, -1, sizeof(cache));
			if(dynamic(0,0) == 1)
				results.push_back(filename);
		}

		sort(results.begin() ,results.end());
		for(string sorted : results)
			cout << sorted << "\n";
	}
	return 0;
}