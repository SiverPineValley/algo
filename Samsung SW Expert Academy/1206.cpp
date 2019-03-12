// 1206. [S/W 문제해결 기본] 1일차 - View
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(void)
{
    int n;
    for(int t = 1; t <= 10; t++)
    {
        int cnt = 0;
        vector<int> b(1000);
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> b[i];
        for(int i = 2; i < n - 2; i++)
        {
            int l1, l2, r1, r2;
            l1 = b[i] - b[i-1];
            l2 = b[i] - b[i-2];
            r1 = b[i] - b[i+1];
            r2 = b[i] - b[i+2];
            if( (l1 > 0) && (l2 > 0) && (r1 > 0) && (r2 > 0) )
                cnt += min(min(l1,l2),min(r1,r2));
        }
        cout << "#" << t << " " << cnt << "\n";
    }
    return 0;   
}