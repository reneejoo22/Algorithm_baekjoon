//1747
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

#define Large 10000001

int main() {

	long n;
	cin >> n;
	long A[Large] = { 0 };

	for (int i = 2; i < Large; i++) {
		A[i] = i;
	}

	for (int i = 2; i <= sqrt(Large); i++) {	//배수지우기
		if (A[i] == 0) {
			continue;
		}
		for (int p = i + i; p < Large; p = p + i) {
			A[p] = 0;
		}
	}

	string str;
	int s, e;
	bool check = false;

	for (int q = n; q < Large; q++) {
		if (A[q] != 0) {
			str = to_string(A[q]);
			s = 0; e = str.length() - 1;

			for (int c = 0; c <= str.length() / 2; c++) {
				if (str[s] == str[e]) {
					s++;
					e--;
					check = true;
				}
				else {
					check = false;
					break;
				}
			}

			if (check) {
				cout << A[q];
				break;
			}
			else {
				continue;
			}
		}
	}

	return 0;
}