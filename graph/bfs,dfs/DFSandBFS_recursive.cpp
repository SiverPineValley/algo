// 1260
// 백준's 코드
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[1001];
void dfs(int node)
{
	bool check[1001];
    check[node] = true;
    printf("%d ",node);
    for (int i=0; i<a[node].size(); i++)
    {
        int next = a[node][i];
        if (check[next] == false)
        {
            dfs(next);
        }
    }
}
void bfs(int node) {
	bool check[1001];
    queue<int> q;
    check[node] = true;
    q.push(node);
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        printf("%d ",f);
        for (int i=0; i<a[f].size(); i++)
        {
            int next = a[f][i];
            if (check[next] == false)
            {
                check[next] = true;
                q.push(next);
            }
        }
    }
}
int main() {
    int n, m, start;
    scanf("%d %d %d",&n,&m,&start);
    for (int i=0; i<m; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1; i<=n; i++) {
        sort(a[i].begin(), a[i].end());
    }
    dfs(start);
    puts("");
    bfs(start);
    puts("");
    return 0;
}