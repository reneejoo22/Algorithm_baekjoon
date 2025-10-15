#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;

	int x, y;
	x = a * p;

	if (p > c)
		y = (p - c)*d + b;

	else
		y = b;



	if (x < y) 
		cout << x;

	else 
		cout << y;
}

