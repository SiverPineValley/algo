#include <string>
#include <vector>

using namespace std;

struct Wait {
    int priority;
    bool loc;
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int size = priorities.size();
    int max = -1;
    vector<Wait> v;
    
    for(int i = 0; i < size; i++) {
        v.push_back(Wait{priorities[i], i == location});
        if (max < priorities[i]) {
            max = priorities[i];
        }
    }
    
    while(!v.empty()) {
        Wait f = v.front();
        v.erase(v.begin());
        if (f.priority < max) {
            v.push_back(Wait{f.priority, f.loc});
        } else {
            answer++;
            if (f.loc) {
                break;
            }
            
            max = -1;
            for(auto iter = v.begin(); iter != v.end(); iter++) {
                if (iter->priority > max) {
                    max = iter->priority;
                }
            }
        }
    }
    
    return answer;
}