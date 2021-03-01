// 프로그래머스
// 완전탐색 - 카펫
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    int total = brown + yellow;
    
    for(int row = 3; row <= (total/row) ;row++) {
        if(total % row != 0) continue;
        int column = total/row;
        if((row - 2) * (column - 2) != yellow) continue;
        answer[0] = column;
        answer[1] = row;
        break;
    }
    
    return answer;
}