// 프로그래머스
// hash - 완주하지 못한 선수
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int size = completion.size();
    map<string,int> m;
    
    for(string c : completion) {
        if (!m.count(c)) {
            m[c] = 1;
        } else {
            m[c] = m[c] + 1;
        }
    }
    
        for(string p : participant) {
        if (!m.count(p)) {
            answer = p;
            break;
        } else if (m[p] == 0) {
            answer = p;
            break;
        } else {
            m[p] = m[p] - 1;
        }
    }
    
    return answer;
}