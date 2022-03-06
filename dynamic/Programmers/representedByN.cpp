#include <iostream>
#include <cstring>

using namespace std;

#define BIG 999999999;
#define MIN(A,B) A < B ? A : B

int arr[100000000];

int dynamic(int now, int N, int number) {
    if (now < 0 || now > 297000) return BIG;
    if (arr[now] == 1) return 1;
    
    if (arr[now] == 0) arr[now] = BIG;
    arr[now] = MIN(arr[now], dynamic(now + N, N, number));
    arr[now] = MIN(arr[now], dynamic(now - N, N, number));
    arr[now] = MIN(arr[now], dynamic(now * N, N, number));
    arr[now] = MIN(arr[now], dynamic(now / N, N, number));
    for (int i = 1; now * 10 < (N*(10^i) + N);i++) {
        arr[now] = MIN(arr[now], dynamic(now + (N*(10^i) + N), N, number));
        arr[now] = MIN(arr[now], dynamic(now - (N*(10^i) + N), N, number));   
        arr[now] = MIN(arr[now], dynamic(now * (N*(10^i) + N), N, number));   
        arr[now] = MIN(arr[now], dynamic(now / (N*(10^i) + N), N, number));   
    }
    
    return arr[now];
}

int solution(int N, int number) {
    int answer = 0;
    memset(arr, 0, sizeof(arr));
    arr[N] = 1;
    answer = dynamic(number, N, number);
    if (answer >= 8) {
        answer = -1;
    }
    
    return answer;
}

int main(void) {
    cout << "실행" << endl;
    solution(5, 12);
    cout << "끝" << endl;

    return 0;
}