//14916
#include <iostream>
using namespace std;

int main() {
	int n;
	int num = 0;
	cin >> n;

	if (n % 5 == 0) {
		cout << n / 5;
	}

	else {
		while (n > 0) {
			n = n - 2;
			num = num + 1;

			if (n % 5 == 0) {
				num = num + (n / 5);
				cout << num;
				break;
			}
		}
	}

	if (n < 0) {
		cout << "-1";
	}

}