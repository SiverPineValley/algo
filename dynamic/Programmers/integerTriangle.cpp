#include <string>
#include <vector>

using namespace std;
int answer, height, d[501][501];
int max(int a, int b){
    return a > b ? a : b;
}

int solution(vector<vector<int>> triangle) {
    answer = d[0][0] = triangle[0][0];
    height = triangle.size();
    
    for(int i=1; i<height; i++){
        for(int j=0; j<=i; j++){
            // 삼각형 제일 왼쪽 끝인 경우
            if(j == 0){
                d[i][j] = d[i-1][j] + triangle[i][j];
            // 삼각형 제일 오른쪽 끝인 경우
            }else if(j == i){
                d[i][j] = d[i-1][j-1] + triangle[i][j];
            }
            // 삼각형 내부인 경우
            else{
                d[i][j] = max(d[i-1][j-1], d[i-1][j]) + triangle[i][j];
            }
            
            answer = max(answer, d[i][j]);
        
    }
    return answer;
}