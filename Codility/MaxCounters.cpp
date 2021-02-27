// you can use includes, for example:
#include <algorithm>

vector<int> solution(int N, vector<int> &A) {
    int max = 0, addMax = 0;
    vector<int> V(N,0);

    for(int each : A) {
        if (each == N + 1) {
            addMax = max;
        } else {
            if(V[each - 1] < addMax) V[each - 1] = addMax;
            V[each - 1]++;
            if (max < V[each-1]) max = V[each-1];
        }
    }

    for(int idx = 0; idx < N; idx++) {
        if (V[idx] < addMax) {
            V[idx] = addMax;
        }
    }

    return V;
}