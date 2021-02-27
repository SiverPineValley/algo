// you can use includes, for example:
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    int size = A.size();
    int leaves = 0;
    vector<int> V(X + 1, 0);

    for(int idx = 0; idx < size; idx++) {
        if (V[A[idx]] == 0) {
            V[A[idx]] = 1;
            leaves++;
        }

        if (leaves == X) {
            return idx;
        }
    }

    return -1;
}