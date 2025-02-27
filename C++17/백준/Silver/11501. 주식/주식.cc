//11501
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int p = 0;p < n;p++) {
		int m;
		cin >> m;
		
		vector<int>price(m);
		for (int i = 0;i < m;i++) {
			cin >> price[i];
		}

		int max = 0;
		long long money = 0;
		for (int q = m - 1;q >= 0;q--) {
			if (price[q] > max) {
				max = price[q];
			}
			else {
				money += max - price[q];
			}
		}

		cout << money << endl;
	}
}