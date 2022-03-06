//프로그래머스
//BFS - 타겟 넘버
#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int operation[2] = {1, -1};

int solution(vector<int> numbers, int target) {
    int answer = 0, idx = 1;
    int size = numbers.size();
    queue<pair<int,int>> q;
    q.push(make_pair(numbers[0],0));
    q.push(make_pair(-1 * numbers[0],0));
    
    while(!q.empty()) {
        int now = q.front().first, idx = q.front().second;
        q.pop();
        
        if(idx == size - 1) {
            if(now == target) {
                answer++;     
            }
            continue;
        }
        
        for(int opIdx = 0; opIdx < 2 && idx < size - 1; opIdx++) {
            q.push(make_pair(now + (numbers[idx + 1] * operation[opIdx]),idx + 1));
        }
    }
    
    return answer;
}