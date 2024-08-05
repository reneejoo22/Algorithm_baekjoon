//2857
#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
	int num = 0;
	int list[5] = { 0 };
	bool isit = false;
	string A;

	for (int i = 0; i < 5; i++) {
		string A;
		cin >> A;
		num = num + 1;

		for (int a = 0; a < A.length(); a++) {
			if (A[a] == 'F') {
				if (A[a + 1] == 'B') {
					if (A[a + 2] == 'I') {
						list[i] = num;
						isit = true;
					}
				}
			}
		}
	}


	if (!isit) {
		cout << "HE GOT AWAY!";
	}

	else {

		for (int p = 0; p < 5; p++) {
			if (list[p] == 0) {
				continue;
			}
			else {
				cout << list[p] << " ";
			}
		}
	}
}