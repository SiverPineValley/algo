// Programmers
// hash - 전화번호 목록
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// len(source) <= len(target)
bool isPrefix(string source, string target) {
    int idx = 0;
    bool result = true;
    for(char each : source) {
        if (each == target[idx]) {
            idx++;
            continue;
        } else {
            result = false;
            break;
        }
    }
    
    return result;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    int min = 21, max = -1;
    unordered_map<int,vector<string>> map_book;
    
    // Map 생성
    for(string each_book : phone_book) {
        int length = each_book.length();
        map_book[length].push_back(each_book);
        if (length < min) min = length;
        if (max < length) max = length;
    }
    
    // Map 비교
    for(int length = min;length <= max; length++) {
        if(map_book.count(length) == 0) continue;
        for (string source : map_book[length]) {
                for(int cmp = length; cmp <= max; cmp++) {
                    if(map_book.count(cmp) == 0) continue;
                    for (string target : map_book[cmp]) {
                        if(source == target) continue;
                        if(isPrefix(source,target)) return false;
                    }
            }
        }
    }
    
    return answer;
}