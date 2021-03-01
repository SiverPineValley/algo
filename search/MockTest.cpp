// 프로그래머스
// 완전탐색 - 모의고사
#include <string>
#include <vector>

using namespace std;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int size = answers.size();
    
    vector<int> answerA = {1, 2, 3, 4, 5}, answerB = {2, 1, 2, 3, 2, 4, 2, 5}, answerC = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int countA = 0, countB = 0, countC = 0, max = 0;
    
    for(int idx = 0; idx <  size; idx++) {
        if(answerA[idx % 5] == answers[idx]) countA++;
        if(answerB[idx % 8] == answers[idx]) countB++;
        if(answerC[idx % 10] == answers[idx]) countC++;
    }
    
    max = MAX(max,countA);
    max = MAX(max,countB);
    max = MAX(max,countC);
        
    if(max == countA) answer.push_back(1);
    if(max == countB) answer.push_back(2);
    if(max == countC) answer.push_back(3);
    
    return answer;
}