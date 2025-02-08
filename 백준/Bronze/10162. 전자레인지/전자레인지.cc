#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	int a = 0, b = 0, c = 0;

	if (t>=300) {
		a = t / 300;
		t %= 300;
	}

	if (60 <= t) {
		b = t / 60;
		t %= 60;
	}

	if (10 <= t) {
		c = t / 10;
		t %= 10;
	}

	if (t == 0) {
		cout << a << " " << b << " " << c << endl;
	}
	else {
		cout << "-1";
	}
}