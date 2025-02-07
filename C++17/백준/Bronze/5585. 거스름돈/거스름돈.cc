//5585
#include <iostream>
using namespace std;

int main() {
	int n;
	int count = 0;
	cin >> n;

	n = 1000 - n;

	if (n >= 500) {
		count = count + (n / 500);
		n %= 500;
	}
	if (n >= 100) {
		count += n / 100;
		n %= 100;
	}
	if (n >= 100) {
		count += n / 100;
		n %= 100;
	}
	if (n >= 50) {
		count += n / 50;
		n %= 50;
	}
	if (n >= 10) {
		count += n / 10;
		n %= 10;
	}
	if (n >= 5) {
		count += n / 5;
		n %= 5;
	}
	if (n >= 1) {
		count += n / 1;
		n %= 1;
	}

	cout << count;
}