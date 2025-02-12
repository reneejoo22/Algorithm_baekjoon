//1138
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int t[26];
int des(int a, int b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;

	int digit = 0;
	for (int i = 0;i < n;i++) {
		string a;
		cin >> a;

		int s = 1;
		for (int q = a.size() - 1;q >= 0;q--) {
			t[a[q] - 'A'] += s;
			s *= 10;
		}

		digit += a.size();
	}

	sort(t, t+26, des); //내림차순

	int i = 9, sum = 0;
	for (int p = 0;p < digit;p++) {
		t[p] *= i;
		i--;
		sum += t[p];
	}

	cout << sum;
}