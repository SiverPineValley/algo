#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int r, c, k, n=3, m=3;
int cnt[101], a[101][101];

void solve()
{
    for (int t = 0; t < 101; t++)
    {
        if (a[r][c] == k)
        {
            printf("%d\n", t);
            return;
        }
        if (n >= m)
        {
            for (int y = 1; y <= n; y++)
            {
                priority_queue<pair<int, int>> pq;
                memset(cnt, 0, sizeof(cnt));
                for (int x = 1; x <= m; x++)
                {
                    if (a[y][x])
                    {
                        cnt[a[y][x]] += 1;
                        a[y][x] = 0;
                    }
                }
                for (int x = 1; x <= 100; x++)
                    if (cnt[x]) pq.push(make_pair(-cnt[x], -x));
                int len = pq.size()*2;
                m = max(m, len);
                for (int x = 1; x <= len; x += 2)
                {
                    a[y][x] = -pq.top().second;
                    a[y][x+1] = -pq.top().first;
                    pq.pop();
                }
            }
        }
        else
        {
            for (int x = 1; x <= m; x++)
            {
                priority_queue<pair<int, int>> pq;
                memset(cnt, 0, sizeof(cnt));
                for (int y = 1; y <= n; y++)
                {
                    if (a[y][x])
                    {
                        cnt[a[y][x]] += 1;
                        a[y][x] = 0;
                    }
                }
                for (int y = 1; y <= 100; y++)
                    if (cnt[y]) pq.push(make_pair(-cnt[y], -y));
                int len = pq.size()*2;
                n = max(n, len);
                for (int y = 1; y <= len; y += 2)
                {
                    a[y][x] = -pq.top().second;
                    a[y+1][x] = -pq.top().first;
                    pq.pop();
                }
            }
        }
        
    }
    printf("-1\n");
}

int main(void)
{
	cin >> r >> c >> k;
    for (int y = 1; y <= 3; y++)
        for (int x = 1; x <= 3; x++)
        	cin >> a[y][x];

    solve();
    return 0;
}
