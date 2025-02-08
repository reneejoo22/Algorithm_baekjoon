#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;

	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<pair<int, int>> c(n);
		//c.clear();
		for (int q = 0; q < n; q++) {
			int a, b;
			cin >> a >> b;
			c[q] = { a,b };
		}

		sort(c.begin(), c.end());
		int count = 1;
		int tmp = 0;
		for (int p = 1; p < n; p++) {
			if (c[tmp].second > c[p].second) {
				count++;
				tmp = p;
			}
		}

		cout << count<<endl;
	}
	return 0;
}