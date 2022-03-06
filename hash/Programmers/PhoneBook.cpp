// Programmers
// hash - 전화번호 목록
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string,int> map_book;
    
    // Map 생성
    for(string each_book : phone_book)
        map_book[each_book] = 1;
    
    // Map 비교
    for(string each_book : phone_book) {
        string book = "";
        for (int i = 0; i < each_book.size(); i++) {
            book += each_book[i];
            if (map_book[book] && book != each_book) {
                return false;
            }
        }
    }
    
    return true;
}