#include<iostream>
using namespace std;

int main() {
	
	int max = -1;

	int plus, minus;
	int now = 0;
	for (int i = 0; i < 4; i++) {
		cin >> minus >> plus;
		now = now + (plus - minus);

		if (max < now) {
			max = now;
		}
	}

	cout << max;
}