#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	while (cin >> a >> b >> c) {

		if (b - a < c - b) {
			cout << c - b -1 << endl;
		}
		else {
			cout << b - a -1 << endl;
		}

	}
}