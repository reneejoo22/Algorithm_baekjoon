//11501
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, l;
	cin >> n >> l;

	vector<int>apple;
	for (int i = 0;i < n;i++) {
		int num;
		cin >> num;
		if (num <= l) {
			l += 1;
		}
		else {
			apple.push_back(num);
		}
	}

	if (apple.size() != 0) {
		sort(apple.begin(), apple.end());

		for (int i = 0;i < apple.size();i++) {
			if (apple[i] <= l) {
				l += 1;
			}
			else {
				break;
			}
		}
	}

	cout << l;
}