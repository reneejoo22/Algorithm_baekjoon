#include <iostream>

#include <string>

using namespace std;

int main(void) {

	string channel[101];

	int N;

	cin >> N;

	int index1 = 0;

	int index2 = 0;

	for (int i = 1; i <= N; i++) {

		cin >> channel[i];

		if (channel[i] == "KBS1") {

			index1 = i;

		}

		if (channel[i] == "KBS2") {

			index2 = i;

		}

		

		//cout << channel[i] << ' ';

	}

	int x = index1 - 1;

	for (int i = 1; i <= x; i++) {

		cout << 1;

	}

	for (int i = 1; i <= x; i++) {

		cout << 4;

	}

	if (index1 > index2) index2 += 1;

	

	x = index2 - 1;

	for (int i = 1; i <= x; i++) {

		cout << 1;

	}

	for (int i = 1; i <= x-1; i++) {

		cout << 4;

	}

}