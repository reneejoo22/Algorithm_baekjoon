//1138
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int>v(n, 0);
	for (int i = 1;i <= n;i++) {
		int num = 0;
		cin >> num;

		for (int q = 0;q < n;q++) {
			if (num == 0 && v[q] == 0) {
				v[q] = i;
				break;
			}
			if(v[q] == 0) {
				num--;
			}
		}
	}

	for (int p = 0;p < n;p++) {
		cout << v[p] << " ";
	}

}