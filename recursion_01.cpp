#include <iostream>

using namespace std;

int recursion(int n) {
	if(n <= 0) return 0;
	else {
		return n + recursion(n-1);
	}
}

int factorial(int n) {
	if(n == 0)
		return 1;
	else
		return n*factorial(n-1);

}

int power(double x, int n) {
	if (n == 0)
		return 1;
	else
		return x*power(x, n-1);
}

int fibonacci(int n) {
	if ( n < 2 )
		return n;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
	int result;

	cout << "숫자를 입력해주세요: ";
	cin >> result;

	cout << "Recursion Sum: " << recursion(result) <<endl;
	cout << "Factorial: " << factorial(result) <<endl;
	cout << "Power: " << power(2, result) <<endl;
	cout << "Fibonacci: " << fibonacci(result) <<endl;

	return 0;
}

