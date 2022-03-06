#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct alpa {
    string now;
    map<string,bool> visit;
};

bool compare(string now, string target) {
    int length = now.size();
    int diff = 0;
    for(int i = 0; i < length; i++) {
        if (now[i] != target[i]) {
            if (diff) {
                return false;
            }
            diff++;
        }
    }
    
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 51;
    int length = words.size();
    queue<alpa> q;    
    q.push({begin,map<string,bool>()});
    
    while(!q.empty()) {
        alpa f = q.front();
        q.pop();
        
        if (f.now == target) {
            int tempAnswer = f.visit.size();
            if (tempAnswer < answer && tempAnswer != 0) {
                answer = tempAnswer;
            }
            continue;
        }
        
        f.visit[f.now] = true;
        for(int i = 0; i < length; i++) {
            if (f.now == words[i] || f.visit.count(words[i]) > 0) {
                continue;
            }
            
            if (compare(f.now, words[i])) {
                q.push({words[i], f.visit});
            }
        }
    }
    
    if (answer == 51) {
        answer = 0;
    }
    
    return answer;
}