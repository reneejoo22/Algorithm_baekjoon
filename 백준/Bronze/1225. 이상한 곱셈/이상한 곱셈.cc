#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	long long sum = 0;
	for (int i = 0; i < a.length(); i++) {
		for (int p = 0; p < b.length(); p++) {
			sum += (int)(a[i] - 48) * (int)(b[p] - 48);
		}
	}

	cout << sum;
	return 0;
}
