//baekjoon 1267
#include<iostream>
using namespace std;

int main() {

	string num;
	int i = 0;

	while (true) {

		cin >> num;

		if (num.length() == 1 && num[0] == '0') {
			break;
		}

		int Wspace = 2;
		Wspace = Wspace + (num.length() - 1);

		for (int i = 0; i < num.length(); i++) {

			if (num[i] == '1') {
				Wspace = Wspace + 2;
			}
			else if (num[i] == '0') {
				Wspace = Wspace + 4;
			}
			else {
				Wspace = Wspace + 3;
			}
		}
		cout << Wspace << "\n";
	}
}