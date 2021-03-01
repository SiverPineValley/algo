// 프로그래머스
// hash - 위장
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string,int> cloth_map;
    int cloth_type = 0;

    for(vector<string> cloth : clothes) {
        if(cloth_map.count(cloth[1]) > 0) {
            cloth_map[cloth[1]]++;
        } else {
            cloth_map[cloth[1]] = 1;
            cloth_type++;
        }
    }
    
    for(unordered_map<string,int>::iterator iter = cloth_map.begin(); iter!= cloth_map.end(); iter++){
        answer = answer + (iter->second * answer);   
    }
    return answer-1;
}