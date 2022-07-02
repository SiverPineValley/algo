#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Prog {
    int weight;
    int time;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int size = truck_weights.size();
    int on_bridge = 0;
    queue<Prog> q;
    bool prev_out = false;

    while(!truck_weights.empty() || !q.empty()) {
        if (!truck_weights.empty()) {
            int f = truck_weights.front();
            // 다리에 더 들어갈 수 있을 때
            if (on_bridge + f <= weight) {
                if (!prev_out) {
                    time++;
                }
                q.push(Prog{f, time});
                truck_weights.erase(truck_weights.begin());
                on_bridge += f;
                prev_out = false;
                
                if (!q.empty()) {
                    Prog o = q.front();
                    if (bridge_length - (time - o.time) != 1) {
                        continue;
                    }
                }
                else continue;
            }
        }
        Prog o = q.front();
        time += bridge_length - (time - o.time);
        on_bridge -= o.weight;
        q.pop();
        prev_out = true;
    }
    
    return time;
}