// 15663
// 백준's 코드
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check[10]; int a[10]; int num[10];
vector<vector<int>> v;
void nm(int index, int N, int M)
{
	if(index == M)
	{
		vector<int> temp;
        for (int i=0; i < M; i++)
        {
            temp.push_back(num[a[i]-1]);
        }
        v.push_back(temp);
		return;
	}
	for(int i = 1; i<=N; i++)
	{
		if(check[i]) continue;
		check[i] = true;
		a[index] = i;
		nm(index+1,N,M);
		check[i] = false;
	}
}
int main(void)
{
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> num[i];
	sort(num,num+N);
	nm(0,N,M);
	sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for (auto &d : v)
    {
        for (int i=0; i<M; i++)
        {
            cout << d[i];
            if (i != M-1)
                cout << ' ';
        }
        cout << '\n';
    }
	return 0;
}