// 2071. 평균값 구하기
#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    for(int t = 1; t <= n; t++)
    {
        float temp2;
        int ans, temp;
        float sum = 0;
        for(int i = 0; i < 10; i++)
        {
            cin >> temp;
            sum += temp;
        }
        temp2 = sum/10;
        temp = (int) temp2;
        temp2 -= temp;
        if(temp2 >= 0.5) ans = temp+1;
        else ans = temp;
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;   
}