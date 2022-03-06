#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Route {
    string target;
    int index;
};

struct Status {
    string now;
    int cnt;
    vector<bool> visited;
    vector<string> route;
};

vector<string> compare(vector<string> a, vector<string> b) {
    int size = a.size();
    if (size == 0) return b;
    
    for(int i = 0; i < size; i ++) {
        if (a[i] < b[i]) {
            return a;
        } else if (a[i] == b[i]) {
            continue;
        }
        return b;
    }
    
    return a;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int length = tickets.size();
    map<string,vector<Route>> route;
    
    // Route 생성
    for (int i = 0; i < length; i++) {
        vector<string> ticket = tickets[i];
        if (route.count(ticket[0]) == 0) {
            vector<Route> vc;
            vc.push_back({ticket[1], i});
            route.insert({ticket[0], vc});
        } else {
            route[ticket[0]].push_back({ticket[1], i});
        }
    }
    
    // 탐색
    queue<Status> q;
    q.push({"ICN", 1, vector<bool>(length,false), vector<string>(1, "ICN")});
    
    while (!q.empty()) {
        Status f = q.front();
        q.pop();
        
        if (f.cnt == length + 1) {
            answer = compare(answer, f.route);
            continue;
        }
        
        int targetSize = route[f.now].size();
        for (int i = 0; i < targetSize; i++) {
            Route tgt = route[f.now][i];
            Status temp = f;
            
            if (temp.visited[tgt.index]) {
                continue;
            }
            
            temp.visited[tgt.index] = true;
            temp.route.push_back(tgt.target);
            q.push({tgt.target, temp.cnt + 1, temp.visited, temp.route});
        }
    }
    
    return answer;
}