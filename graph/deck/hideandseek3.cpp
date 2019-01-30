// 13549
#include <iostream>
#include <deque>
using namespace std;
int main(void)
{
	int n,k;
	deque<int> d;
	int c[100001];
	int w[100001];
	cin >> n >> k;
	d.push_back(n);
	c[n] = 1;
	w[n] = 0;

	while(!d.empty())
	{
		int a = d.front();
		d.pop_front();

		if(a*2 <= 100000)
		{
			if(!c[a*2])
			{
				c[a*2] = 1;
				w[a*2] = w[a];
				d.push_front(a*2);
			}
		}
		if(a-1 >= 0)
		{
			if(!c[a-1])
			{
				c[a-1] = 1;
				w[a-1] = w[a] + 1;
				d.push_back(a-1);
			}
		}
		if(a+1 <= 100000)
		{
			if(!c[a+1])
			{
				c[a+1] = 1;
				w[a+1] = w[a] + 1;
				d.push_back(a+1);
			}
		}
	}

	cout << w[k] << "\n";
	return 0;
}