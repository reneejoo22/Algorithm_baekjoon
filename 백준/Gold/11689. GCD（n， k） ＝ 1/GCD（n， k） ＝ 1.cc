//11689
#include<iostream>
#include<cmath>
using namespace std;

int main() {
	long n;
	cin >> n;

	//cout << sqrt(n) << endl;

	long res = n;
	for (long j = 2; j <= sqrt(n); j++) {
		if (n % j == 0) {
			res = res - res / j;
			//cout << "j: " << j << " res: " << res << endl;
		}
		while (n % j == 0) {
			n /= j;
			//cout << "n: " << n << endl;
		}
	}

	if (n > 1) {
		res = res - res / n;
	}
	cout << res << endl;
}