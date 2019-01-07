#include <iostream>
using namespace std;
int main(void)
{
	int e = 1; // <= 15
	int s = 1; // <= 28
	int m = 1; // <= 19
	int y = 1;
	bool f = false;
	int in[3];
	for(int i = 0; i < 3; i++) cin >> in[i];
	while(!f)
	{
		if( (e==in[0]) && (s==in[1]) && (m==in[2]) )
			f = true;
		else
		{
			e++;
			s++;
			m++;
			y++;
			if(e > 15) e = 1;
			if(s > 28) s = 1;
			if(m > 19) m = 1;
		}
	}
	cout << y << "\n";
	return 0;
}