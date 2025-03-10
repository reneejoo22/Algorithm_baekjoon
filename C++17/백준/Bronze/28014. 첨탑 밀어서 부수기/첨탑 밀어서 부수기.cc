//28014
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int>top(n);
	for (int i = 0;i < n;i++) {
		cin >> top[i];
	}

	int cnt = 1;
	for (int q = n-1; q > 0; q--) {
		if (top[q] >= top[q - 1]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}