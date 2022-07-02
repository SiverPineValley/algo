#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int size = progresses.size();
    
    // 큐에 담기
    for (int i = 0; i < size; i++) {
        if ((100-progresses[i]) % speeds[i] != 0) {
            q.push(((100 - progresses[i]) / speeds[i]) + 1);
            continue;
        }
        q.push((100 - progresses[i]) / speeds[i]);
    }
    
    // 하나씩 뽑기
    int now = 0;
    int job = 0;
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        
        if (now == 0) {
            now = f;
            job++;
        } else if (now < f) {
            answer.push_back(job);
            job = 1;
            now = f;
        } else {
            job++;
        }
    }
    
    if (job != 0) {
        answer.push_back(job);        
    }

    return answer;
}