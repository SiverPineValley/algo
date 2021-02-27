// you can use includes, for example:
#include <vector>
#include <algorithm>

int solution(vector<int> &A) {
    int size = A.size();
    vector<int> D(size, -1000000000);

    D[0] = A[0];
    D[1] = A[0] + A[1];

    for (int idx = 2; idx < size; idx++) {
        int next = idx - 6;
        if (next < 0) next = 0;
        for (int prev = idx - 1; prev >= next; prev--) {
            int each = A[idx] + D[prev];
            D[idx] = max(D[idx], each);
        }
    }

    return D[size - 1];
}