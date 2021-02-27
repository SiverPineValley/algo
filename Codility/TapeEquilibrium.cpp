// you can use includes, for example:
#include <vector>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int sum(vector<int> &A, int size) {
    int total = 0;
    for(int idx = 0; idx < size; idx++) {
        total += A[idx];
    }
    
    return total;
}

int solution(vector<int> &A) {
    int size = A.size();
    int second = sum(A, size), first = 0;
    int diff = 1000000000;

    for(int idx = 0; idx < size - 1; idx++) {
        second -= A[idx];
        first += A[idx];
        int each = abs(second - first);

        if(diff > each) {
            diff = each;
        }
    }

    return diff;
}