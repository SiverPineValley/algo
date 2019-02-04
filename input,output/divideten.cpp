// 11721
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string buff;
	cin >> buff;
	for(int i = 0; i < buff.length();)
	{
		int j = i;
		for(; (j < i+10)&&(j < buff.length()); j++)
		{
			cout << buff[j];
		}
		cout << "\n";
		i = j;
	}
	return 0;
}