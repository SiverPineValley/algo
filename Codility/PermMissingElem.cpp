// you can use includes, for example:
#include <vector>
#include <map>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    map<int,bool> m;
    int size = A.size();

    for(auto each = A.begin(); each != A.end(); each++) {
        if (!m.count(*each))
            m[*each] = true;
    }

    int result = 1;
    for(; result <= size + 1; result++) {
        if (!m.count(result)) {
            return result;
        }
    }

    return size + 1;
}