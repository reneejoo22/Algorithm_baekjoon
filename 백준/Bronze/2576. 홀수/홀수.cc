//2490 baekjoon
#include<iostream>
#include<vector>
using namespace std;

int main() {

	int sum = 0, min = 100;

	for (int i = 0; i < 7; i++) {
		int num;
		cin >> num;

		if (num % 2 != 0) {
			sum = num + sum;
			if (num < min) {
				min = num;
			}
		}
	}

	if (sum == 0) {
		cout << -1;
	}
	else {
		cout << sum << "\n" << min;
	}
}