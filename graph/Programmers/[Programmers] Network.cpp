#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visit(n, false);
    queue<int> q;
    
    for(int i = 0; i < n; i++) {
        if (visit[i]) {
            continue;
        }
        
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (visit[v]) continue;
            visit[v] = true;
            
            for(int j = 0; j < n; j++) {
                if(computers[v][j] && !visit[j]) {
                    q.push(j);
                }
            }
        }
        answer++;
    }
    
    return answer;
}