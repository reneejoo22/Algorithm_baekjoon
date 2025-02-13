#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;

	vector<int>v(t);
	int rule[3] = { 0,1,2 };
	int sum = 0, n = 0;
	for (int i = 0;i < t;i++) {
		int num;
		cin >> num;
		
		if (n > 2) {
			n = 0;
		}
		if (num == rule[n]) {
			sum++;
			n++;
		}
	}

	cout << sum;
	return 0;
}
