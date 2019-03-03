// 1546
#include <iostream>
using namespace std;
int main(void)
{
	double n;
	double test[1000];
	double max = 0;
	double sum = 0;
	double avg = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> test[i];
		if(max < test[i])
		{
			max = test[i];
		}
	}

	for(int i = 0; i < n; i++)
	{
		double temp;
		temp = test[i]/max*100;
		sum += temp;
	}


	avg = sum / n;
	cout << avg << "\n";
	return 0;
}