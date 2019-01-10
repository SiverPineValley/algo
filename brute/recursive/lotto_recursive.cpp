// 6603 recursive version
// 백준's 코드
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> choice;
void lotto(vector<int> &a, int index, int cnt)
{
	if(cnt == 6)
	{
		for(int i : choice)
			cout << i << " ";
		cout<< "\n";
		return;
	}
	else if(index == a.size()) return;
	choice.push_back(a[index]);
	lotto(a, index+1, cnt+1);
	choice.pop_back();
	lotto(a, index+1, cnt);
}

int main(void)
{
	int n;
	cin >> n;
	while(n)
	{
		vector<int> a(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];
		lotto(a,0,0);
		cout << "\n";
		cin >> n;
	}
	return 0;
}