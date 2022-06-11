#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int map[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    // 초기화
    memset(map, -1, sizeof(map));
    map[0][0] = 1;
    
    for (int i = 0; i < puddles.size(); i++) {
        vector<int> cur = puddles[i];
        map[cur[1] - 1][cur[0] - 1] = 0;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] != -1) continue;
            else if(i == 0) {
                map[i][j] = map[i][j-1];
                continue;
            } else if(j == 0) {
                map[i][j] = map[i - 1][j];
                continue;
            }
            map[i][j] = (map[i - 1][j] + map[i][j - 1]) % 1000000007;
        }
    }
    
    return map[n-1][m-1];
}