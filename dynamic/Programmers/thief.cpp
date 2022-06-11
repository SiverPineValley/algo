#include <string>
#include <vector>

using namespace std;

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int solution(vector<int> money) {
    int num = money.size();
    vector<int> first(num, 0);
    vector<int> second(num, 0);
    
    for(int i = 1; i < num; i++) {
        first[i] = money[i-1];
        second[i] = money[i];
    }
    
    for(int i = 2; i < num; i++) {
        first[i] = max(first[i - 1], first[i - 2] + first[i]);
        second[i] = max(second[i - 1], second[i - 2] + second[i]);
    }
    
    return max(first[num - 1], second[num - 1]);
}