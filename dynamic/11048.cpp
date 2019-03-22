// 이동하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int maxThree(int a, int b, int c)
{
    return max(max(a,b),c);
}

int bottomUp(vector<vector<int>> &a, vector<vector<int>> &d)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            d[i][j] = maxThree(d[i-1][j],d[i][j-1],d[i-1][j-1]) + a[i][j];
    return d[n][m];
}

// 초기화가 음수로 되었을 때만 사용.
int topDown(int i, int j, vector<vector<int>> &a, vector<vector<int>> &d)
{
    if(i < 1 || j < 1) return 0;
    if(d[i][j] >= 0) return d[i][j];
    d[i][j] = maxThree(topDown(i-1,j,a,d),topDown(i,j-1,a,d),topDown(i-1,j-1,a,d)) + a[i][j];
    return d[i][j];
}

int main(void)
{
    cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int> (m+1));
    vector<vector<int>> d(n+1, vector<int> (m+1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    cout << bottomUp(a,d) << "\n";
    return 0;
}