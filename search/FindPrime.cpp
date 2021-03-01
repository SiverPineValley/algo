// 프로그래머스
// 완전탐색 - 소수 찾기
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
#include <cmath>

using namespace std;

set<int> duplicate;
int answer = 0, length;
string target;

bool isPrime(int num)
{
    if(num <= 1) return false;
    if(num == 2) return true;
    
    if(num % 2 == 0) return false;
    int sqrtn = (int) sqrt(num);
	for (int i = 3; i <= sqrtn; i += 2) {
    	if (num % i == 0) return false;
	}
    
    return true;
}

void check(int cur, int stage, vector<int> contained)
{   
    for(int index = 0; index < length; index++)
    {
        if(contained[index] == 1) continue;
        int temp = 0;
        temp = (cur * 10) + ((int) target[index] - 48);
        
        // 중복이 없으면 넣기
	    if(duplicate.count(temp) == 0)
        {
            if(isPrime(temp))
                answer++;
            duplicate.insert(temp);
        }
		
        if(stage + 1 == length) continue;
        contained[index] = 1;
        check(temp, stage + 1, contained);
		contained[index] = 0;
    }
    return;
}

int solution(string numbers) {
    vector<int> contained(7,0);

    target = numbers;
    length = numbers.length();
    check(0, 0, contained);
    
    return answer;
}